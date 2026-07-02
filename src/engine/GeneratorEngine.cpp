// src/engine/GeneratorEngine.cpp

#ifdef _WIN32
#  ifndef NOMINMAX
#    define NOMINMAX
#  endif
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#endif

#include "GeneratorEngine.h"
#include "ThreadPool.h"
#include "UDPSender.h"
#include "TCPSender.h"
#include "FieldGenerator.h"
#include "LogTemplateEngine.h"
#include "ScenarioSelector.h"
#include "TICategoryMapper.h"
#include "logging/Logger.h"
#include "core/Constants.h"
#include <format>
#include <chrono>
#include <thread>
#include <charconv>
#include <cstring>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <cmath>

#ifdef _WIN32
#include <windows.h>
#include <timeapi.h>
#pragma comment(lib, "winmm.lib")
#endif

static inline std::string_view u32ToSV(uint32_t v, char* buf, size_t bufsz) {
    auto [end, ec] = std::to_chars(buf, buf + bufsz, v);
    return { buf, static_cast<size_t>(end - buf) };
}

static inline float    fixedToFloat(uint32_t v) { return static_cast<float>(v) / 100.0f; }
static inline uint32_t floatToFixed(float v)    { return static_cast<uint32_t>(v * 100.0f); }

static inline void assignSV(std::string& dst, std::string_view sv) {
    dst.assign(sv.data(), sv.size());
}

namespace {

struct TokenRefs {
    std::string* timestamp;
    std::string* date;
    std::string* time;
    std::string* attackSeqNum;
    std::string* srcIp;
    std::string* dstIp;
    std::string* srcPort;
    std::string* dstPort;
    std::string* action;
    std::string* attackName;
    std::string* severity;
    std::string* proto;
    std::string* priority;
    std::string* eventType;
    std::string* connId;
    std::string* pid;
    std::string* eventId;
    std::string* username;
    std::string* httpMethod;
    std::string* uri;
    std::string* httpHost;
    std::string* pktCnt;
    std::string* byteCnt;
    std::string* tiIp;
    std::string* tiCategory;
    std::string* tiSeverity;
    std::string* tiCountry;
    std::string* tiCountryCode;
    std::string* tiDescription;
    std::string* tiSource;
};

void ensureTokenKeys(std::flat_map<std::string, std::string>& tokens) {
    static constexpr const char* kKeys[] = {
        "TIMESTAMP", "DATE", "TIME", "ATTACK_SEQ_NUM",
        "SRC_IP",    "DST_IP",  "SRC_PORT",  "DST_PORT",
        "ACTION",    "ATTACK_NAME", "SEVERITY", "PROTO",
        "PRIORITY",  "EVENT_TYPE",  "CONN_ID",  "PID",
        "EVENT_ID",  "USERNAME",    "HTTP_METHOD", "URI",
        "HTTP_HOST", "PKT_CNT",     "BYTE_CNT",
        "TI_IP",     "TI_CATEGORY", "TI_SEVERITY",
        "TI_COUNTRY", "TI_COUNTRY_CODE", "TI_DESCRIPTION", "TI_SOURCE",
    };
    for (const char* k : kKeys)
        tokens.try_emplace(k);
}

TokenRefs resolveTokenRefs(std::flat_map<std::string, std::string>& tokens) {
    auto get = [&](const char* key) -> std::string* {
        auto it = tokens.find(key);
        return (it != tokens.end()) ? &it->second : nullptr;
    };
    return TokenRefs{
        .timestamp     = get("TIMESTAMP"),
        .date          = get("DATE"),
        .time          = get("TIME"),
        .attackSeqNum  = get("ATTACK_SEQ_NUM"),
        .srcIp         = get("SRC_IP"),
        .dstIp         = get("DST_IP"),
        .srcPort       = get("SRC_PORT"),
        .dstPort       = get("DST_PORT"),
        .action        = get("ACTION"),
        .attackName    = get("ATTACK_NAME"),
        .severity      = get("SEVERITY"),
        .proto         = get("PROTO"),
        .priority      = get("PRIORITY"),
        .eventType     = get("EVENT_TYPE"),
        .connId        = get("CONN_ID"),
        .pid           = get("PID"),
        .eventId       = get("EVENT_ID"),
        .username      = get("USERNAME"),
        .httpMethod    = get("HTTP_METHOD"),
        .uri           = get("URI"),
        .httpHost      = get("HTTP_HOST"),
        .pktCnt        = get("PKT_CNT"),
        .byteCnt       = get("BYTE_CNT"),
        .tiIp          = get("TI_IP"),
        .tiCategory    = get("TI_CATEGORY"),
        .tiSeverity    = get("TI_SEVERITY"),
        .tiCountry     = get("TI_COUNTRY"),
        .tiCountryCode = get("TI_COUNTRY_CODE"),
        .tiDescription = get("TI_DESCRIPTION"),
        .tiSource      = get("TI_SOURCE"),
    };
}

} // namespace

GeneratorEngine::GeneratorEngine(int threadPoolSize, size_t queueCapacity)
    : m_poolSize(threadPoolSize)
    , m_dispatchQueue(queueCapacity)
{
#ifdef _WIN32
    timeBeginPeriod(1);
#endif
}

GeneratorEngine::~GeneratorEngine() {
    stop();
#ifdef _WIN32
    timeEndPeriod(1);
#endif
}

void GeneratorEngine::setLogCallback(LogCallback cb) {
    m_callback = std::move(cb);
}

void GeneratorEngine::setDateOffsetDays(int days) {
    m_dateOffsetDays.store(days, std::memory_order_relaxed);
}

bool GeneratorEngine::loadTIPool(const std::string& csvPath) {
    return m_tiPool.loadFromCSV(csvPath);
}

void GeneratorEngine::pushWorkerError(std::string_view deviceId,
                                      std::string_view deviceName,
                                      std::string_view message) {
    LOG_ERROR("ENGINE", std::format("Worker error: deviceId={}, name={}, message={}",
        deviceId, deviceName, message));
    const uint64_t ms = static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now().time_since_epoch()).count());
    LogEntry err;
    err.deviceId    = deviceId;
    err.deviceName  = deviceName;
    err.rawLog      = std::format("[WORKER_ERROR] {}", message);
    err.timestampMs = ms;
    m_dispatchQueue.tryPush(std::move(err));
}

std::expected<void, std::string>
GeneratorEngine::initWorkerSender(WorkerContext& ctx) {
    const DeviceProfile& p = ctx.profile;
    ctx.sender = p.collector.useTCP
        ? std::unique_ptr<ISender>(std::make_unique<TCPSender>())
        : std::unique_ptr<ISender>(std::make_unique<UDPSender>());

    ctx.udpSender = p.collector.useTCP
        ? nullptr
        : static_cast<UDPSender*>(ctx.sender.get());

    if (!ctx.sender->openConnection(p.collector.ip, p.collector.port))
        return std::unexpected(std::format("Connection failed: {}:{}",
            p.collector.ip, p.collector.port));
    return {};
}

GeneratorEngine::RefreshResult
GeneratorEngine::refreshProfile(WorkerContext& ctx) {
    const uint64_t curVersion = m_profileVersion.load(std::memory_order_acquire);
    if (curVersion == ctx.knownVersion)
        return RefreshState::kNoChange;

    DeviceProfile updated;
    {
        std::shared_lock lock(m_statsMutex);
        auto it = m_profileMap.find(ctx.profileId);
        if (it == m_profileMap.end())
            return std::unexpected(std::format("Profile not found: {}", ctx.profileId));
        updated          = it->second;
        ctx.knownVersion = curVersion;
    }

    const bool collectorChanged =
        updated.collector.useTCP != ctx.profile.collector.useTCP ||
        updated.collector.ip     != ctx.profile.collector.ip     ||
        updated.collector.port   != ctx.profile.collector.port;

    ctx.profile = updated;

    if (collectorChanged) {
        if (auto res = initWorkerSender(ctx); !res) {
            pushWorkerError(ctx.profile.id, ctx.profile.deviceName,
                std::format("Reconnect failed: {}", res.error()));
            return std::unexpected(res.error());
        }
        ctx.consecutiveFails = 0;
        LOG_INFO("NETWORK", std::format("Collector connection updated: device={}, target={}:{}",
            ctx.profile.deviceName, ctx.profile.collector.ip, ctx.profile.collector.port));
    }

    if (!ctx.templateEngine.loadTemplate(ctx.profile.formatRaw)) {
        const auto msg = std::format("Template reload failed: {}", ctx.profile.deviceName);
        pushWorkerError(ctx.profile.id, ctx.profile.deviceName, msg);
        return std::unexpected(msg);
    }

    ctx.tokens["EQP_IP"] = ctx.profile.eqpIp;
    if (!ctx.profile.event.srcIpRandom) ctx.tokens["SRC_IP"] = ctx.profile.event.srcIp;
    if (!ctx.profile.event.dstIpRandom) ctx.tokens["DST_IP"] = ctx.profile.event.dstIpFixed;

    if (!ctx.prevBurstEnable && ctx.profile.scheduler.burstEnable) {
        ctx.burstStartTime = std::chrono::steady_clock::now();
        ctx.inBurstMode    = false;
    }
    ctx.prevBurstEnable = ctx.profile.scheduler.burstEnable;

    if (ctx.profile.event.srcIpRandom)
        ctx.fieldGen.cacheIpRange(ctx.profile.event.srcIpStart, ctx.profile.event.srcIpEnd);
    if (ctx.profile.event.dstIpRandom)
        ctx.fieldGen.cacheDstIpRange(ctx.profile.event.dstIpStart, ctx.profile.event.dstIpEnd);
    ctx.scenarioSelector.updateScenarios(ctx.profile.event.scenarios);

    return collectorChanged ? RefreshState::kConnectionChanged : RefreshState::kUpdated;
}

void GeneratorEngine::updateBurstState(
        WorkerContext& ctx,
        const std::chrono::steady_clock::time_point& now) {
    if (!ctx.profile.scheduler.burstEnable) {
        ctx.inBurstMode = false;
        return;
    }
    const float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        now - ctx.burstStartTime).count() / 1000.0f;
    if (!ctx.inBurstMode && elapsed >= ctx.profile.scheduler.burstIntervalSec) {
        ctx.inBurstMode    = true;
        ctx.burstStartTime = now;
    } else if (ctx.inBurstMode && elapsed >= ctx.profile.scheduler.burstDurationSec) {
        ctx.inBurstMode    = false;
        ctx.burstStartTime = now;
    }
}

void GeneratorEngine::buildBatch(
        WorkerContext& ctx,
        size_t         batchSize,
        uint64_t       nowMs) {
    const DeviceProfile& p = ctx.profile;
    const int  allowPct    = p.event.allowPct;
    const bool useTIPool   = p.event.useTIPool;
    const bool srcIpRandom = p.event.srcIpRandom;
    const bool dstIpRandom = p.event.dstIpRandom;
    const auto& dstPorts   = p.event.dstPorts;

    TokenRefs r = resolveTokenRefs(ctx.tokens);

    for (size_t bi = 0; bi < batchSize; ++bi) {
        if (r.timestamp)    assignSV(*r.timestamp,    ctx.fieldGen.generateTimestamp());
        if (r.date)         assignSV(*r.date,         ctx.fieldGen.generateDate());
        if (r.time)         assignSV(*r.time,         ctx.fieldGen.generateTime());
        if (r.attackSeqNum) assignSV(*r.attackSeqNum, ctx.fieldGen.generateSeqNum());
        if (srcIpRandom && r.srcIp)
                            assignSV(*r.srcIp,        ctx.fieldGen.generateRandomSrcIp());
        if (dstIpRandom && r.dstIp)
                            assignSV(*r.dstIp,        ctx.fieldGen.generateRandomDstIp());
        if (r.srcPort)  assignSV(*r.srcPort,  u32ToSV(ctx.fieldGen.generateRandomSrcPort(),       ctx.srcPortBuf, 8));
        if (r.dstPort)  assignSV(*r.dstPort,  u32ToSV(ctx.fieldGen.generateRandomPort(dstPorts),  ctx.dstPortBuf, 8));
        if (r.action)   assignSV(*r.action,   ctx.fieldGen.generateAction(allowPct));
        if (r.attackName) assignSV(*r.attackName, ctx.scenarioSelector.selectAttackScenario());
        if (r.severity) assignSV(*r.severity, ctx.fieldGen.generateSeverity());
        if (r.proto)    assignSV(*r.proto,    ctx.fieldGen.generateProto());
        if (r.priority) assignSV(*r.priority, ctx.fieldGen.generatePriority());
        if (r.eventType) assignSV(*r.eventType, ctx.fieldGen.generateEventType());
        if (r.connId)   assignSV(*r.connId,   ctx.fieldGen.generateConnId());
        if (r.pid)      assignSV(*r.pid,      ctx.fieldGen.generatePid());
        if (r.eventId)  assignSV(*r.eventId,  ctx.fieldGen.generateEventId());
        if (r.username) assignSV(*r.username, ctx.fieldGen.generateUsername());
        if (r.httpMethod) assignSV(*r.httpMethod, ctx.fieldGen.generateHttpMethod());
        if (r.uri)      assignSV(*r.uri,      ctx.fieldGen.generateUri());
        if (r.httpHost) assignSV(*r.httpHost, ctx.fieldGen.generateHttpHost());
        if (r.pktCnt)   assignSV(*r.pktCnt,   u32ToSV(ctx.fieldGen.generateRandomCount(1,    100), ctx.pktBuf,  8));
        if (r.byteCnt)  assignSV(*r.byteCnt,  u32ToSV(ctx.fieldGen.generateRandomCount(64, 65535), ctx.byteBuf, 8));

        if (r.tiIp       && r.srcIp)      *r.tiIp       = *r.srcIp;
        if (r.tiCategory && r.attackName) *r.tiCategory = *r.attackName;
        if (r.tiSeverity && r.severity)   *r.tiSeverity = *r.severity;

        if (useTIPool && !m_tiPool.empty()) {
            const TIEntry ti = m_tiPool.getRandomTI();
            if (!ti.ip.empty()) {
                if (r.srcIp)         *r.srcIp         = ti.ip;
                if (r.tiIp)          *r.tiIp          = ti.ip;
                if (r.tiCountry)     *r.tiCountry     = ti.countryName;
                if (r.tiCountryCode) *r.tiCountryCode = ti.countryCode;
                if (r.tiCategory)    *r.tiCategory    = ti.category;
                if (r.tiSeverity)    *r.tiSeverity    = ti.severity;
                if (r.tiDescription) *r.tiDescription = ti.description;
                if (r.tiSource)      *r.tiSource      = ti.source;
                if (r.attackName)    *r.attackName    = ti.category;
                if (r.severity)      *r.severity      = ti.severity;
            }
        }

        ctx.sendBuf.emplace_back(ctx.templateEngine.render(ctx.tokens));

        LogEntry entry;
        entry.deviceId    = p.id;
        entry.deviceName  = p.deviceName;
        entry.rawLog      = ctx.sendBuf.back();
        entry.timestampMs = nowMs;
        ctx.dispatchBuf.push_back(std::move(entry));
    }
}

uint64_t GeneratorEngine::sendAndDispatch(WorkerContext& ctx, size_t batchSize) {
    const DeviceProfile& p = ctx.profile;
    uint64_t sentCount = 0;

    if (ctx.udpSender) {
        sentCount = static_cast<uint64_t>(ctx.udpSender->sendBatchGetCount(ctx.sendBuf));
        ctx.consecutiveFails = (sentCount > 0) ? 0 : ctx.consecutiveFails + 1;
    } else {
        if (ctx.sender->sendBatch(ctx.sendBuf)) {
            sentCount            = static_cast<uint64_t>(batchSize);
            ctx.consecutiveFails = 0;
        } else {
            ++ctx.consecutiveFails;
            LOG_WARN("NETWORK", std::format("sendBatch failed ({}/{}): device={}, target={}:{}",
                ctx.consecutiveFails, Constants::Engine::kMaxConsecutiveFails,
                p.deviceName, p.collector.ip, p.collector.port));

            if (ctx.consecutiveFails >= Constants::Engine::kMaxConsecutiveFails) {
                const auto elapsed = std::chrono::steady_clock::now() - ctx.lastReconnectAttempt;
                if (elapsed >= Constants::Engine::kReconnectInterval) {
                    ctx.lastReconnectAttempt = std::chrono::steady_clock::now();
                    LOG_WARN("NETWORK", std::format(
                        "Max consecutive failures reached, forcing reconnect: device={}",
                        p.deviceName));
                    if (ctx.sender->openConnection(p.collector.ip, p.collector.port)) {
                        ctx.consecutiveFails = 0;
                        LOG_INFO("NETWORK", std::format(
                            "Forced reconnect succeeded: device={}", p.deviceName));
                    } else {
                        LOG_ERROR("NETWORK", std::format(
                            "Forced reconnect failed: device={}", p.deviceName));
                    }
                }
            }
        }
    }

    if (sentCount > 0)
        m_dispatchQueue.tryPushBatch(ctx.dispatchBuf, sentCount);

    return sentCount;
}

void GeneratorEngine::updateRateStats(WorkerContext& ctx, uint64_t sentCount) {
    ctx.logsSentInThisInterval += sentCount;
    const auto   rateNow = std::chrono::steady_clock::now();
    const double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(
        rateNow - ctx.lastRateCalcTime).count();

    if (elapsed >= Constants::Engine::kRateCalcIntervalSec) {
        const float rate = static_cast<float>(
            static_cast<double>(ctx.logsSentInThisInterval) / elapsed);
        if (ctx.devRateFixed)
            ctx.devRateFixed->store(floatToFixed(rate), std::memory_order_relaxed);
        ctx.logsSentInThisInterval = 0;
        ctx.lastRateCalcTime       = rateNow;
    }
}

bool GeneratorEngine::runTokenBatchPath(
        WorkerContext& ctx,
        double         effectiveRate,
        size_t         maxBatch,
        uint64_t       nowMs,
        bool           isFastPath) {

    const auto   nowToken = std::chrono::steady_clock::now();
    const double dtSec    = std::chrono::duration_cast<std::chrono::duration<double>>(
        nowToken - ctx.tokenLastTime).count();
    ctx.tokenLastTime = nowToken;

    ctx.tokenBucket += effectiveRate * dtSec;
    const double bucketCap = static_cast<double>(maxBatch) * 2.0;
    if (ctx.tokenBucket > bucketCap)
        ctx.tokenBucket = bucketCap;

    if (ctx.tokenBucket < 1.0) {
        if (isFastPath) {
            auto refreshRes = refreshProfile(ctx);
            if (!refreshRes) return false;
            std::this_thread::yield();
        } else {
            const double waitSec = (1.0 - ctx.tokenBucket) / effectiveRate;
            std::this_thread::sleep_for(
                std::chrono::duration_cast<std::chrono::steady_clock::duration>(
                    std::chrono::duration<double>(waitSec)));
        }
        return true;
    }

    const size_t tokenSz   = static_cast<size_t>(ctx.tokenBucket);
    const size_t batchSize = (tokenSz < maxBatch) ? tokenSz : maxBatch;

    auto refreshRes = refreshProfile(ctx);
    if (!refreshRes) return false;

    buildBatch(ctx, batchSize, nowMs);

    const uint64_t sentCount = sendAndDispatch(ctx, batchSize);

    ctx.tokenBucket -= static_cast<double>(sentCount);

    if (sentCount > 0) {
        if (ctx.devCounter) ctx.devCounter->fetch_add(sentCount, std::memory_order_relaxed);
        m_totalSentCount.fetch_add(sentCount, std::memory_order_relaxed);
    }
    updateRateStats(ctx, sentCount);
    return true;
}

void GeneratorEngine::spawnWorkers(const std::string& profileId, int count) {
    m_profileWorkerCount[profileId] = count;
    for (int i = 0; i < count; ++i) {
        m_activeWorkers.insert(workerKey(profileId, i));
        m_threadPool->enqueue([this, id = profileId, idx = i, cnt = count]() {
            workerLoop(id, idx, cnt);
        });
    }
}

void GeneratorEngine::start(const std::vector<DeviceProfile>& profiles) {
    stop();
    LOG_INFO("ENGINE", std::format("Engine start requested. profiles={}", profiles.size()));

    std::vector<std::reference_wrapper<const DeviceProfile>> enabled;
    for (const auto& p : profiles)
        if (p.enabled) enabled.emplace_back(p);

    const int activeCount = static_cast<int>(enabled.size());

    std::vector<int> workerCounts(activeCount, 1);
    const int remaining = m_poolSize - activeCount;
    if (remaining > 0 && activeCount > 0) {
        std::vector<double> eps(activeCount);
        for (int i = 0; i < activeCount; ++i) {
            const double v = static_cast<double>(
                enabled[i].get().scheduler.normalRateToEps());
            eps[i] = (v > 1.0) ? v : 1.0;
        }

        double totalEps = 0.0;
        for (int i = 0; i < activeCount; ++i) totalEps += eps[i];

        std::vector<double> share(activeCount);
        for (int i = 0; i < activeCount; ++i)
            share[i] = (eps[i] / totalEps) * static_cast<double>(remaining);

        for (int i = 0; i < activeCount; ++i)
            workerCounts[i] += static_cast<int>(share[i]);

        int allocated = 0;
        for (int i = 0; i < activeCount; ++i) allocated += workerCounts[i];
        int leftover = (m_poolSize - allocated);
        if (leftover > 0) {
            std::vector<std::pair<double, int>> rem;
            rem.reserve(activeCount);
            for (int i = 0; i < activeCount; ++i)
                rem.emplace_back(share[i] - std::floor(share[i]), i);
            std::sort(rem.begin(), rem.end(),
                [](const std::pair<double,int>& a, const std::pair<double,int>& b){
                    return a.first > b.first;
                });
            for (int k = 0; k < leftover && k < activeCount; ++k)
                ++workerCounts[rem[k].second];
        }
    }

    {
        std::unique_lock lock(m_statsMutex);
        m_profileMap.clear();
        m_activeWorkers.clear();
        m_profileWorkerCount.clear();
        m_totalSentCount.store(0, std::memory_order_relaxed);

        for (const auto& p : profiles) {
            m_profileMap[p.id] = p;
            auto cit = m_deviceCounters.find(p.id);
            if (cit == m_deviceCounters.end()) {
                m_deviceCounters[p.id]   = std::make_unique<std::atomic<uint64_t>>(0);
                m_deviceRatesFixed[p.id] = std::make_unique<std::atomic<uint32_t>>(0);
            } else {
                cit->second->store(0, std::memory_order_relaxed);
                m_deviceRatesFixed[p.id]->store(0, std::memory_order_relaxed);
            }
        }
        m_profileVersion.fetch_add(1, std::memory_order_release);
    }

    m_running.store(true, std::memory_order_seq_cst);
    m_dispatcherThread = std::thread(&GeneratorEngine::dispatcherLoop, this);
    m_threadPool       = std::make_unique<ThreadPool>(m_poolSize);

    {
        std::unique_lock lock(m_statsMutex);
        for (int i = 0; i < activeCount; ++i) {
            const std::string& id  = enabled[i].get().id;
            const int          cnt = workerCounts[i];
            LOG_INFO("ENGINE", std::format(
                "Worker started for profileId={}, device={} (workers={})",
                id, enabled[i].get().deviceName, cnt));
            spawnWorkers(id, cnt);
        }
    }
    LOG_INFO("ENGINE", std::format("Engine started. threadPoolSize={}", m_poolSize));
}

void GeneratorEngine::stop() {
    if (!m_running.load(std::memory_order_acquire)) return;
    LOG_INFO("ENGINE", "Engine stop requested");
    m_running.store(false, std::memory_order_release);
    m_running.notify_all();
    m_threadPool.reset();
    m_dispatchQueue.wakeAll();
    if (m_dispatcherThread.joinable())
        m_dispatcherThread.join();
    LOG_INFO("ENGINE", "Engine stopped cleanly");
}

void GeneratorEngine::updateProfile(const DeviceProfile& profile) {
    bool spawnWorker = false;
    {
        std::unique_lock lock(m_statsMutex);
        auto it = m_profileMap.find(profile.id);
        if (it != m_profileMap.end()) {
            const bool wasEnabled = it->second.enabled;
            it->second = profile;
            m_profileVersion.fetch_add(1, std::memory_order_release);
            LOG_DEBUG("ENGINE", std::format("Profile updated: id={}, name={}",
                profile.id, profile.deviceName));

            if (!wasEnabled && profile.enabled &&
                !m_activeWorkers.contains(workerKey(profile.id, 0))) {
                m_activeWorkers.insert(workerKey(profile.id, 0));
                spawnWorker = true;
            }
        }
    }

    if (spawnWorker && m_threadPool && m_running.load(std::memory_order_acquire)) {
        LOG_INFO("ENGINE", std::format("Spawning new worker for device: id={}, name={}",
            profile.id, profile.deviceName));
        m_threadPool->enqueue([this, id = profile.id]() { workerLoop(id, 0, 1); });
    }
}

void GeneratorEngine::dispatcherLoop() {
    std::vector<LogEntry> batch;
    batch.reserve(Constants::Engine::kBatchSize * 2);
    LOG_INFO("ENGINE", "Dispatcher thread started");
    while (true) {
        const size_t n = m_dispatchQueue.drain(batch, m_running);
        for (size_t i = 0; i < n; ++i) {
            if (m_callback) m_callback(std::move(batch[i]));
        }
        if (!m_running.load(std::memory_order_relaxed) && m_dispatchQueue.empty())
            break;
    }
    LOG_INFO("ENGINE", "Dispatcher thread stopped");
}

void GeneratorEngine::workerLoop(const std::string& profileId,
                                  int workerIndex,
                                  int totalWorkers) {
    const std::string wKey = workerKey(profileId, workerIndex);

    if (!m_running.load(std::memory_order_acquire)) {
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(wKey);
        return;
    }

    WorkerContext ctx;
    ctx.profileId    = profileId;
    ctx.workerIndex  = workerIndex;
    ctx.totalWorkers = totalWorkers;

    {
        std::shared_lock lock(m_statsMutex);
        auto it = m_profileMap.find(profileId);
        if (it == m_profileMap.end()) return;
        ctx.profile      = it->second;
        ctx.knownVersion = m_profileVersion.load(std::memory_order_acquire);

        if (auto cit = m_deviceCounters.find(profileId); cit != m_deviceCounters.end())
            ctx.devCounter = cit->second.get();
        if (auto rit = m_deviceRatesFixed.find(profileId); rit != m_deviceRatesFixed.end())
            ctx.devRateFixed = rit->second.get();
    }

    LOG_INFO("ENGINE", std::format("Worker started for profileId={}, device={}",
        profileId, ctx.profile.deviceName));

    if (auto res = initWorkerSender(ctx); !res) {
        pushWorkerError(ctx.profile.id, ctx.profile.deviceName, res.error());
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(wKey);
        return;
    }

    if (!ctx.templateEngine.loadTemplate(ctx.profile.formatRaw)) {
        pushWorkerError(ctx.profile.id, ctx.profile.deviceName,
            std::format("Template load failed (formatRaw empty): {}", ctx.profile.deviceName));
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(wKey);
        return;
    }

    ctx.fieldGen.setDateOffsetDays(m_dateOffsetDays.load(std::memory_order_relaxed));
    if (ctx.profile.event.srcIpRandom)
        ctx.fieldGen.cacheIpRange(ctx.profile.event.srcIpStart, ctx.profile.event.srcIpEnd);
    if (ctx.profile.event.dstIpRandom)
        ctx.fieldGen.cacheDstIpRange(ctx.profile.event.dstIpStart, ctx.profile.event.dstIpEnd);

    ctx.scenarioSelector.updateScenarios(ctx.profile.event.scenarios);

    ctx.lastRateCalcTime = std::chrono::steady_clock::now();
    ctx.burstStartTime   = std::chrono::steady_clock::now();
    ctx.tokenLastTime    = std::chrono::steady_clock::now();
    ctx.prevBurstEnable  = ctx.profile.scheduler.burstEnable;

    ctx.tokens["EQP_IP"]          = ctx.profile.eqpIp;
    ctx.tokens["TI_COUNTRY"]      = "UNKNOWN";
    ctx.tokens["TI_COUNTRY_CODE"] = "ZZ";
    ctx.tokens["TI_DESCRIPTION"]  = "N/A";
    ctx.tokens["TI_SOURCE"]       = "LOCAL";
    if (!ctx.profile.event.srcIpRandom) ctx.tokens["SRC_IP"] = ctx.profile.event.srcIp;
    if (!ctx.profile.event.dstIpRandom) ctx.tokens["DST_IP"] = ctx.profile.event.dstIpFixed;
    ensureTokenKeys(ctx.tokens);

    ctx.sendBuf.reserve(Constants::Engine::kFastBatchSize);
    ctx.dispatchBuf.reserve(Constants::Engine::kFastBatchSize);

    const double workerRateDivisor = static_cast<double>(totalWorkers);

    while (m_running.load(std::memory_order_relaxed)) {
        if (!ctx.profile.enabled) {
            m_running.wait(true, std::memory_order_relaxed);
            if (!m_running.load(std::memory_order_relaxed)) break;
            auto refreshRes = refreshProfile(ctx);
            if (!refreshRes) break;
            continue;
        }

        const auto now = std::chrono::steady_clock::now();
        updateBurstState(ctx, now);

        const double normalEps = static_cast<double>(ctx.profile.scheduler.normalRateToEps());
        const double burstEps  = static_cast<double>(ctx.profile.scheduler.burstRateToEps());
        const double totalRate = ctx.inBurstMode
            ? (burstEps  <= 0.0 ? 1.0 : burstEps)
            : (normalEps <= 0.0 ? 1.0 : normalEps);

        const double effectiveRate = totalRate / workerRateDivisor;

        const uint64_t nowMs = static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count());

        ctx.sendBuf.clear();
        ctx.dispatchBuf.clear();

        if (effectiveRate >= Constants::Engine::kFastPathThreshold) {
            if (!runTokenBatchPath(ctx, effectiveRate,
                    Constants::Engine::kFastBatchSize, nowMs, true))
                break;

        } else if (effectiveRate >= Constants::Engine::kMidPathThreshold) {
            if (!runTokenBatchPath(ctx, effectiveRate,
                    Constants::Engine::kBatchSize, nowMs, false))
                break;

        } else {
            const size_t currentBatchSize = (effectiveRate < 60.0) ? 1
                                          : Constants::Engine::kBatchSize;
            const double batchIntervalSec = static_cast<double>(currentBatchSize) / effectiveRate;
            const auto   nextLoopTime     = now + std::chrono::duration_cast<
                std::chrono::steady_clock::duration>(
                    std::chrono::duration<double>(batchIntervalSec));

            auto refreshRes = refreshProfile(ctx);
            if (!refreshRes) break;

            buildBatch(ctx, currentBatchSize, nowMs);

            const uint64_t sentCount = sendAndDispatch(ctx, currentBatchSize);

            if (sentCount > 0) {
                if (ctx.devCounter) ctx.devCounter->fetch_add(sentCount, std::memory_order_relaxed);
                m_totalSentCount.fetch_add(sentCount, std::memory_order_relaxed);
            }
            updateRateStats(ctx, sentCount);

            std::this_thread::sleep_until(nextLoopTime);
        }
    }

    {
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(wKey);
    }
    LOG_INFO("ENGINE", std::format("Worker stopped for profileId={}, device={}",
        profileId, ctx.profile.deviceName));
}

uint64_t GeneratorEngine::getTotalSent() const {
    return m_totalSentCount.load(std::memory_order_relaxed);
}

uint64_t GeneratorEngine::getSentByDevice(const std::string& deviceId) const {
    std::shared_lock lock(m_statsMutex);
    auto it = m_deviceCounters.find(deviceId);
    return (it != m_deviceCounters.end()) ? it->second->load(std::memory_order_relaxed) : 0;
}

float GeneratorEngine::getCurrentRateByDevice(const std::string& deviceId) const {
    std::shared_lock lock(m_statsMutex);
    auto it = m_deviceRatesFixed.find(deviceId);
    return (it != m_deviceRatesFixed.end())
        ? fixedToFloat(it->second->load(std::memory_order_relaxed))
        : 0.0f;
}
