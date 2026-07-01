// src/engine/GeneratorEngine.cpp
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

#ifdef _WIN32
#define NOMINMAX          // windows.h 의 min/max 매크로 비활성화
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

GeneratorEngine::GeneratorEngine(int threadPoolSize, size_t queueCapacity)
    : m_poolSize(threadPoolSize)
    , m_dispatchQueue(queueCapacity)
{
#ifdef _WIN32
    timeBeginPeriod(1);  // Windows 타이머 해상도 1ms로 향상
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
GeneratorEngine::initWorkerSender(const DeviceProfile& p,
                                   std::unique_ptr<ISender>& senderBase,
                                   UDPSender*& udpSender) {
    senderBase = p.collector.useTCP
        ? std::unique_ptr<ISender>(std::make_unique<TCPSender>())
        : std::unique_ptr<ISender>(std::make_unique<UDPSender>());

    udpSender = p.collector.useTCP
        ? nullptr
        : static_cast<UDPSender*>(senderBase.get());

    if (!senderBase->openConnection(p.collector.ip, p.collector.port))
        return std::unexpected(std::format("Connection failed: {}:{}",
            p.collector.ip, p.collector.port));
    return {};
}

GeneratorEngine::RefreshResult
GeneratorEngine::refreshProfile(
        const std::string&       profileId,
        uint64_t&                knownVersion,
        DeviceProfile&           p,
        std::unique_ptr<ISender>& senderBase,
        UDPSender*&              udpSender,
        int&                     consecutiveFails,
        LogTemplateEngine&       templateEngine,
        FieldGenerator&          fieldGen,
        ScenarioSelector&        scenarioSelector,
        std::flat_map<std::string, std::string>& tokens,
        bool&                    prevBurstEnable,
        bool&                    inBurstMode,
        std::chrono::steady_clock::time_point& burstStartTime) {

    const uint64_t curVersion = m_profileVersion.load(std::memory_order_acquire);
    if (curVersion == knownVersion)
        return RefreshState::kNoChange;

    DeviceProfile updated;
    {
        std::shared_lock lock(m_statsMutex);
        auto it = m_profileMap.find(profileId);
        if (it == m_profileMap.end())
            return std::unexpected(std::format("Profile not found: {}", profileId));
        updated      = it->second;
        knownVersion = curVersion;
    }

    const bool collectorChanged =
        updated.collector.useTCP != p.collector.useTCP ||
        updated.collector.ip     != p.collector.ip     ||
        updated.collector.port   != p.collector.port;

    p = updated;

    if (collectorChanged) {
        if (auto res = initWorkerSender(p, senderBase, udpSender); !res) {
            pushWorkerError(p.id, p.deviceName,
                std::format("Reconnect failed: {}", res.error()));
            return std::unexpected(res.error());
        }
        consecutiveFails = 0;
        LOG_INFO("NETWORK", std::format("Collector connection updated: device={}, target={}:{}",
            p.deviceName, p.collector.ip, p.collector.port));
    }

    if (!templateEngine.loadTemplate(p.formatRaw)) {
        const auto msg = std::format("Template reload failed: {}", p.deviceName);
        pushWorkerError(p.id, p.deviceName, msg);
        return std::unexpected(msg);
    }

    tokens["EQP_IP"] = p.eqpIp;
    if (!p.event.srcIpRandom) tokens["SRC_IP"] = p.event.srcIp;
    if (!p.event.dstIpRandom) tokens["DST_IP"] = p.event.dstIpFixed;

    if (!prevBurstEnable && p.scheduler.burstEnable) {
        burstStartTime = std::chrono::steady_clock::now();
        inBurstMode    = false;
    }
    prevBurstEnable = p.scheduler.burstEnable;

    if (p.event.srcIpRandom) fieldGen.cacheIpRange(p.event.srcIpStart, p.event.srcIpEnd);
    if (p.event.dstIpRandom) fieldGen.cacheDstIpRange(p.event.dstIpStart, p.event.dstIpEnd);
    scenarioSelector.updateScenarios(p.event.scenarios);

    return collectorChanged ? RefreshState::kConnectionChanged : RefreshState::kUpdated;
}

void GeneratorEngine::updateBurstState(
        const DeviceProfile& p,
        bool&  inBurstMode,
        std::chrono::steady_clock::time_point& burstStartTime,
        const std::chrono::steady_clock::time_point& now) {
    if (!p.scheduler.burstEnable) {
        inBurstMode = false;
        return;
    }
    const float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        now - burstStartTime).count() / 1000.0f;
    if (!inBurstMode && elapsed >= p.scheduler.burstIntervalSec) {
        inBurstMode    = true;
        burstStartTime = now;
    } else if (inBurstMode && elapsed >= p.scheduler.burstDurationSec) {
        inBurstMode    = false;
        burstStartTime = now;
    }
}

void GeneratorEngine::buildBatch(
        const DeviceProfile& p,
        FieldGenerator&      fieldGen,
        ScenarioSelector&    scenarioSelector,
        LogTemplateEngine&   templateEngine,
        std::flat_map<std::string, std::string>& tokens,
        size_t               batchSize,
        uint64_t             nowMs,
        std::vector<std::string>& sendBuf,
        std::vector<LogEntry>&    dispatchBuf,
        char* srcPortBuf, char* dstPortBuf,
        char* pktBuf,     char* byteBuf) {

    const int  allowPct    = p.event.allowPct;
    const bool useTIPool   = p.event.useTIPool;
    const bool srcIpRandom = p.event.srcIpRandom;
    const bool dstIpRandom = p.event.dstIpRandom;
    const auto& dstPorts   = p.event.dstPorts;

    for (size_t bi = 0; bi < batchSize; ++bi) {
        assignSV(tokens["TIMESTAMP"],     fieldGen.generateTimestamp());
        assignSV(tokens["DATE"],           fieldGen.generateDate());
        assignSV(tokens["TIME"],           fieldGen.generateTime());
        assignSV(tokens["ATTACK_SEQ_NUM"], fieldGen.generateSeqNum());
        if (srcIpRandom)
            assignSV(tokens["SRC_IP"],     fieldGen.generateRandomSrcIp());
        if (dstIpRandom)
            assignSV(tokens["DST_IP"],     fieldGen.generateRandomDstIp());
        assignSV(tokens["SRC_PORT"],       u32ToSV(fieldGen.generateRandomSrcPort(),        srcPortBuf, 8));
        assignSV(tokens["DST_PORT"],       u32ToSV(fieldGen.generateRandomPort(dstPorts),   dstPortBuf, 8));
        assignSV(tokens["ACTION"],         fieldGen.generateAction(allowPct));
        assignSV(tokens["ATTACK_NAME"],    scenarioSelector.selectAttackScenario());
        assignSV(tokens["SEVERITY"],       fieldGen.generateSeverity());
        assignSV(tokens["PROTO"],          fieldGen.generateProto());
        assignSV(tokens["PRIORITY"],       fieldGen.generatePriority());
        assignSV(tokens["EVENT_TYPE"],     fieldGen.generateEventType());
        assignSV(tokens["CONN_ID"],        fieldGen.generateConnId());
        assignSV(tokens["PID"],            fieldGen.generatePid());
        assignSV(tokens["EVENT_ID"],       fieldGen.generateEventId());
        assignSV(tokens["USERNAME"],       fieldGen.generateUsername());
        assignSV(tokens["HTTP_METHOD"],    fieldGen.generateHttpMethod());
        assignSV(tokens["URI"],            fieldGen.generateUri());
        assignSV(tokens["HTTP_HOST"],      fieldGen.generateHttpHost());
        assignSV(tokens["PKT_CNT"],        u32ToSV(fieldGen.generateRandomCount(1,    100), pktBuf,  8));
        assignSV(tokens["BYTE_CNT"],       u32ToSV(fieldGen.generateRandomCount(64, 65535), byteBuf, 8));

        tokens["TI_IP"]       = tokens["SRC_IP"];
        tokens["TI_CATEGORY"] = tokens["ATTACK_NAME"];
        tokens["TI_SEVERITY"] = tokens["SEVERITY"];

        if (useTIPool && !m_tiPool.empty()) {
            const TIEntry ti = m_tiPool.getRandomTI();
            if (!ti.ip.empty()) {
                tokens["SRC_IP"]          = ti.ip;
                tokens["TI_IP"]           = ti.ip;
                tokens["TI_COUNTRY"]      = ti.countryName;
                tokens["TI_COUNTRY_CODE"] = ti.countryCode;
                tokens["TI_CATEGORY"]     = ti.category;
                tokens["TI_SEVERITY"]     = ti.severity;
                tokens["TI_DESCRIPTION"]  = ti.description;
                tokens["TI_SOURCE"]       = ti.source;
                tokens["ATTACK_NAME"]     = ti.category;
                tokens["SEVERITY"]        = ti.severity;
            }
        }

        std::string rendered = templateEngine.render(tokens);
        LOG_DEBUG("ENGINE", std::format("[{}] {}", p.deviceName, rendered));

        LogEntry entry;
        entry.deviceId    = p.id;
        entry.deviceName  = p.deviceName;
        entry.rawLog      = rendered;
        entry.timestampMs = nowMs;
        dispatchBuf.push_back(std::move(entry));
        sendBuf.push_back(std::move(rendered));
    }
}

uint64_t GeneratorEngine::sendAndDispatch(
        const DeviceProfile& p,
        std::unique_ptr<ISender>& senderBase,
        UDPSender*               udpSender,
        int&                     consecutiveFails,
        std::chrono::steady_clock::time_point& lastReconnectAttempt,
        size_t                   batchSize,
        const std::vector<std::string>& sendBuf,
        const std::vector<LogEntry>&    dispatchBuf) {

    uint64_t sentCount = 0;

    if (udpSender) {
        sentCount = static_cast<uint64_t>(udpSender->sendBatchGetCount(sendBuf));
        consecutiveFails = (sentCount > 0) ? 0 : consecutiveFails + 1;
    } else {
        if (senderBase->sendBatch(sendBuf)) {
            sentCount        = static_cast<uint64_t>(batchSize);
            consecutiveFails = 0;
        } else {
            ++consecutiveFails;
            LOG_WARN("NETWORK", std::format("sendBatch failed ({}/{}): device={}, target={}:{}",
                consecutiveFails, Constants::Engine::kMaxConsecutiveFails,
                p.deviceName, p.collector.ip, p.collector.port));

            if (consecutiveFails >= Constants::Engine::kMaxConsecutiveFails) {
                const auto elapsed = std::chrono::steady_clock::now() - lastReconnectAttempt;
                if (elapsed >= Constants::Engine::kReconnectInterval) {
                    lastReconnectAttempt = std::chrono::steady_clock::now();
                    LOG_WARN("NETWORK", std::format(
                        "Max consecutive failures reached, forcing reconnect: device={}",
                        p.deviceName));
                    if (senderBase->openConnection(p.collector.ip, p.collector.port)) {
                        consecutiveFails = 0;
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
        m_dispatchQueue.tryPushBatch(dispatchBuf, sentCount);

    return sentCount;
}

void GeneratorEngine::updateRateStats(
        uint64_t                sentCount,
        uint64_t&               logsSentInThisInterval,
        std::chrono::steady_clock::time_point& lastRateCalcTime,
        std::atomic<uint32_t>*  devRateFixed) {

    logsSentInThisInterval += sentCount;
    const auto   rateNow = std::chrono::steady_clock::now();
    const double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(
        rateNow - lastRateCalcTime).count();

    if (elapsed >= Constants::Engine::kRateCalcIntervalSec) {
        const float rate = static_cast<float>(
            static_cast<double>(logsSentInThisInterval) / elapsed);
        if (devRateFixed)
            devRateFixed->store(floatToFixed(rate), std::memory_order_relaxed);
        logsSentInThisInterval = 0;
        lastRateCalcTime       = rateNow;
    }
}

void GeneratorEngine::start(const std::vector<DeviceProfile>& profiles) {
    stop();
    LOG_INFO("ENGINE", std::format("Engine start requested. profiles={}", profiles.size()));
    {
        std::unique_lock lock(m_statsMutex);
        m_profileMap.clear();
        m_activeWorkers.clear();
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

    for (const auto& p : profiles | std::views::filter(&DeviceProfile::enabled)) {
        if (!m_running.load(std::memory_order_acquire)) break;
        {
            std::unique_lock lock(m_statsMutex);
            m_activeWorkers.insert(p.id);
        }
        m_threadPool->enqueue([this, id = p.id]() { workerLoop(id); });
    }
    LOG_INFO("ENGINE", std::format("Engine started. threadPoolSize={}", m_poolSize));
}

void GeneratorEngine::stop() {
    if (!m_running.load(std::memory_order_acquire)) return;
    LOG_INFO("ENGINE", "Engine stop requested");
    m_running.store(false, std::memory_order_release);
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
                !m_activeWorkers.contains(profile.id)) {
                m_activeWorkers.insert(profile.id);
                spawnWorker = true;
            }
        }
    }

    if (spawnWorker && m_threadPool && m_running.load(std::memory_order_acquire)) {
        LOG_INFO("ENGINE", std::format("Spawning new worker for device: id={}, name={}",
            profile.id, profile.deviceName));
        m_threadPool->enqueue([this, id = profile.id]() { workerLoop(id); });
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

void GeneratorEngine::workerLoop(const std::string& profileId) {
    if (!m_running.load(std::memory_order_acquire)) {
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(profileId);
        return;
    }

    DeviceProfile p;
    uint64_t      knownVersion = 0;

    std::atomic<uint64_t>* devCounter   = nullptr;
    std::atomic<uint32_t>* devRateFixed = nullptr;

    {
        std::shared_lock lock(m_statsMutex);
        auto it = m_profileMap.find(profileId);
        if (it == m_profileMap.end()) return;
        p            = it->second;
        knownVersion = m_profileVersion.load(std::memory_order_acquire);

        if (auto cit = m_deviceCounters.find(profileId); cit != m_deviceCounters.end())
            devCounter = cit->second.get();
        if (auto rit = m_deviceRatesFixed.find(profileId); rit != m_deviceRatesFixed.end())
            devRateFixed = rit->second.get();
    }

    LOG_INFO("ENGINE", std::format("Worker started for profileId={}, device={}",
        profileId, p.deviceName));

    std::unique_ptr<ISender> senderBase;
    UDPSender* udpSender = nullptr;

    if (auto res = initWorkerSender(p, senderBase, udpSender); !res) {
        pushWorkerError(p.id, p.deviceName, res.error());
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(profileId);
        return;
    }

    LogTemplateEngine templateEngine;
    if (!templateEngine.loadTemplate(p.formatRaw)) {
        pushWorkerError(p.id, p.deviceName,
            std::format("Template load failed (formatRaw empty): {}", p.deviceName));
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(profileId);
        return;
    }

    FieldGenerator fieldGen;
    fieldGen.setDateOffsetDays(m_dateOffsetDays.load(std::memory_order_relaxed));
    if (p.event.srcIpRandom) fieldGen.cacheIpRange(p.event.srcIpStart, p.event.srcIpEnd);
    if (p.event.dstIpRandom) fieldGen.cacheDstIpRange(p.event.dstIpStart, p.event.dstIpEnd);

    ScenarioSelector scenarioSelector;
    scenarioSelector.updateScenarios(p.event.scenarios);

    // 워커별 로컬 슬립 제어 (공유 mutex 제거)
    std::mutex              workerMutex;
    std::condition_variable workerCv;

    auto     lastRateCalcTime        = std::chrono::steady_clock::now();
    uint64_t logsSentInThisInterval  = 0;
    auto     burstStartTime          = std::chrono::steady_clock::now();
    bool     inBurstMode             = false;
    bool     prevBurstEnable         = p.scheduler.burstEnable;

    std::flat_map<std::string, std::string> tokens;

    tokens["EQP_IP"]          = p.eqpIp;
    tokens["TI_COUNTRY"]      = "UNKNOWN";
    tokens["TI_COUNTRY_CODE"] = "ZZ";
    tokens["TI_DESCRIPTION"]  = "N/A";
    tokens["TI_SOURCE"]       = "LOCAL";

    if (!p.event.srcIpRandom) tokens["SRC_IP"] = p.event.srcIp;
    if (!p.event.dstIpRandom) tokens["DST_IP"] = p.event.dstIpFixed;

    char srcPortBuf[8], dstPortBuf[8], pktBuf[8], byteBuf[8];

    std::vector<std::string> sendBuf;
    sendBuf.reserve(Constants::Engine::kFastBatchSize);
    std::vector<LogEntry> dispatchBuf;
    dispatchBuf.reserve(Constants::Engine::kFastBatchSize);

    int  consecutiveFails     = 0;
    auto lastReconnectAttempt = std::chrono::steady_clock::time_point{};

    // 토큰 버킷: fast-path 속도 제어용
    double tokenBucket   = 0.0;
    auto   tokenLastTime = std::chrono::steady_clock::now();

    while (m_running.load(std::memory_order_relaxed)) {
        auto refreshRes = refreshProfile(
            profileId, knownVersion, p,
            senderBase, udpSender, consecutiveFails,
            templateEngine, fieldGen, scenarioSelector,
            tokens, prevBurstEnable, inBurstMode, burstStartTime);

        if (!refreshRes) break;

        if (!p.enabled) {
            std::unique_lock<std::mutex> lk(workerMutex);
            workerCv.wait_for(lk, Constants::Engine::kWorkerIdleWait,
                [this] { return !m_running.load(std::memory_order_relaxed); });
            continue;
        }

        const auto now = std::chrono::steady_clock::now();
        updateBurstState(p, inBurstMode, burstStartTime, now);

        const double normalEps = static_cast<double>(p.scheduler.normalRateToEps());
        const double burstEps  = static_cast<double>(p.scheduler.burstRateToEps());
        const double effectiveRate = inBurstMode
            ? (burstEps  <= 0.0 ? 1.0 : burstEps)
            : (normalEps <= 0.0 ? 1.0 : normalEps);

        const uint64_t nowMs = static_cast<uint64_t>(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count());

        sendBuf.clear();
        dispatchBuf.clear();

        if (effectiveRate >= Constants::Engine::kFastPathThreshold) {
            // ── fast-path: wait_until 없이 연속 전송, 토큰 버킷으로 속도 제어 ──
            const auto   nowFast = std::chrono::steady_clock::now();
            const double dtSec   = std::chrono::duration_cast<std::chrono::duration<double>>(
                nowFast - tokenLastTime).count();
            tokenLastTime = nowFast;

            tokenBucket += effectiveRate * dtSec;
            if (tokenBucket > static_cast<double>(Constants::Engine::kFastBatchSize))
                tokenBucket  = static_cast<double>(Constants::Engine::kFastBatchSize);

            if (tokenBucket < 1.0) {
                std::this_thread::yield();
                continue;
            }

            // std::min 대신 삼항 연산자 사용 (NOMINMAX 보호 이중화)
            const size_t tokenSz  = static_cast<size_t>(tokenBucket);
            const size_t batchSize = (tokenSz < Constants::Engine::kFastBatchSize)
                                   ? tokenSz
                                   : Constants::Engine::kFastBatchSize;

            buildBatch(p, fieldGen, scenarioSelector, templateEngine,
                tokens, batchSize, nowMs,
                sendBuf, dispatchBuf,
                srcPortBuf, dstPortBuf, pktBuf, byteBuf);

            const uint64_t sentCount = sendAndDispatch(
                p, senderBase, udpSender, consecutiveFails, lastReconnectAttempt,
                batchSize, sendBuf, dispatchBuf);

            tokenBucket -= static_cast<double>(sentCount);

            if (sentCount > 0) {
                if (devCounter) devCounter->fetch_add(sentCount, std::memory_order_relaxed);
                m_totalSentCount.fetch_add(sentCount, std::memory_order_relaxed);
            }
            updateRateStats(sentCount, logsSentInThisInterval, lastRateCalcTime, devRateFixed);

        } else {
            // ── normal-path: wait_until 기반 정밀 인터벌 제어 ──
            const size_t currentBatchSize = (effectiveRate < 60.0) ? 1
                                          : Constants::Engine::kBatchSize;
            const double batchIntervalSec = static_cast<double>(currentBatchSize) / effectiveRate;
            const auto   batchDuration    = std::chrono::duration_cast<
                std::chrono::steady_clock::duration>(
                    std::chrono::duration<double>(batchIntervalSec));
            const auto nextLoopTime = now + batchDuration;

            buildBatch(p, fieldGen, scenarioSelector, templateEngine,
                tokens, currentBatchSize, nowMs,
                sendBuf, dispatchBuf,
                srcPortBuf, dstPortBuf, pktBuf, byteBuf);

            const uint64_t sentCount = sendAndDispatch(
                p, senderBase, udpSender, consecutiveFails, lastReconnectAttempt,
                currentBatchSize, sendBuf, dispatchBuf);

            if (sentCount > 0) {
                if (devCounter) devCounter->fetch_add(sentCount, std::memory_order_relaxed);
                m_totalSentCount.fetch_add(sentCount, std::memory_order_relaxed);
            }
            updateRateStats(sentCount, logsSentInThisInterval, lastRateCalcTime, devRateFixed);

            std::unique_lock<std::mutex> lk(workerMutex);
            workerCv.wait_until(lk, nextLoopTime,
                [this] { return !m_running.load(std::memory_order_relaxed); });
        }
    }

    {
        std::unique_lock lock(m_statsMutex);
        m_activeWorkers.erase(profileId);
    }
    LOG_INFO("ENGINE", std::format("Worker stopped for profileId={}, device={}",
        profileId, p.deviceName));
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
