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
#include "ConnectionManager.h"
#include "WorkerAllocationStrategy.h"
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

static inline float    fixedToFloat(uint32_t v) noexcept { return static_cast<float>(v) / 100.0f; }
static inline uint32_t floatToFixed(float v)    noexcept { return static_cast<uint32_t>(v * 100.0f); }

static inline std::string_view u32ToSV(uint32_t v, char* buf, size_t bufsz) noexcept {
    auto [end, ec] = std::to_chars(buf, buf + bufsz, v);
    return { buf, static_cast<size_t>(end - buf) };
}

static inline void assignSV(std::string& dst, std::string_view sv) noexcept {
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
    std::string* blackSha1;
    std::string* city;
    std::string* dstnIp;
    std::string* dstnIpLong;
    std::string* dstnPort;
    std::string* email;
    std::string* extField;
    std::string* fileSize;
    std::string* gatherEtime;
    std::string* instCd1;
    std::string* inPktSize;
    std::string* latitude;
    std::string* originalLog;
    std::string* outPktCnt;
    std::string* outPktSize;
    std::string* payload;
    std::string* prtc;
    std::string* rebuildDt;
    std::string* regiNo;
    std::string* srcCountryCode;
    std::string* trafficType;
    std::string* virusAction;
    std::string* virusDivision;
    std::string* count;
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
        "BLACK_SHA1", "CITY", "DSTN_IP", "DSTN_IP_LONG", "DSTN_PORT",
        "EMAIL", "EXT_FIELD", "FILE_SIZE", "GATHER_ETIME", "INST_CD1",
        "IN_PKT_SIZE", "LATITUDE", "ORIGINAL_LOG", "OUT_PKT_CNT", "OUT_PKT_SIZE",
        "PAYLOAD", "PRTC", "REBUILD_DT", "REGI_NO", "SRC_COUNTRY_CODE",
        "TRAFFIC_TYPE", "VIRUS_ACTION", "VIRUS_DIVISION", "COUNT",
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
        .blackSha1     = get("BLACK_SHA1"),
        .city          = get("CITY"),
        .dstnIp        = get("DSTN_IP"),
        .dstnIpLong    = get("DSTN_IP_LONG"),
        .dstnPort      = get("DSTN_PORT"),
        .email         = get("EMAIL"),
        .extField      = get("EXT_FIELD"),
        .fileSize      = get("FILE_SIZE"),
        .gatherEtime   = get("GATHER_ETIME"),
        .instCd1       = get("INST_CD1"),
        .inPktSize     = get("IN_PKT_SIZE"),
        .latitude      = get("LATITUDE"),
        .originalLog   = get("ORIGINAL_LOG"),
        .outPktCnt     = get("OUT_PKT_CNT"),
        .outPktSize    = get("OUT_PKT_SIZE"),
        .payload       = get("PAYLOAD"),
        .prtc          = get("PRTC"),
        .rebuildDt     = get("REBUILD_DT"),
        .regiNo        = get("REGI_NO"),
        .srcCountryCode = get("SRC_COUNTRY_CODE"),
        .trafficType   = get("TRAFFIC_TYPE"),
        .virusAction   = get("VIRUS_ACTION"),
        .virusDivision = get("VIRUS_DIVISION"),
        .count         = get("COUNT"),
    };
}

} // anonymous namespace

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

GeneratorEngine::RefreshResult
GeneratorEngine::refreshProfile(WorkerContext& ctx) {
    const uint64_t curVersion = m_profileVersion.load(std::memory_order_acquire);
    if (curVersion == ctx.knownVersion)
        return RefreshState::kNoChange;

    DeviceProfile updated;
    bool collectorChanged;
    {
        std::shared_lock lock(m_statsMutex);
        auto it = m_profileMap.find(ctx.profileId);
        if (it == m_profileMap.end())
            return std::unexpected(std::format("Profile not found: {}", ctx.profileId));

        const auto& src = it->second;
        collectorChanged =
            src.collector.useTCP != ctx.profile.collector.useTCP ||
            src.collector.ip     != ctx.profile.collector.ip     ||
            src.collector.port   != ctx.profile.collector.port;

        updated          = src;
        ctx.knownVersion = curVersion;
    }

    ctx.profile = updated;

    if (collectorChanged) {
        if (auto res = ctx.connMgr.connect(ctx.profile); !res) {
            pushWorkerError(ctx.profile.id, ctx.profile.deviceName,
                std::format("Reconnect failed: {}", res.error()));
            return std::unexpected(res.error());
        }
        ctx.connMgr.resetFails();
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

    if (ctx.profile.event.srcIpRandom)
        ctx.fieldGen.cacheIpRange(ctx.profile.event.srcIpStart, ctx.profile.event.srcIpEnd);
    if (ctx.profile.event.dstIpRandom)
        ctx.fieldGen.cacheDstIpRange(ctx.profile.event.dstIpStart, ctx.profile.event.dstIpEnd);
    ctx.scenarioSelector.updateScenarios(ctx.profile.event.scenarios, ctx.templateEngine);

    return collectorChanged ? RefreshState::kConnectionChanged : RefreshState::kUpdated;
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

    const std::string_view devId   = p.id;
    const std::string_view devName = p.deviceName;

    TokenRefs r = resolveTokenRefs(ctx.tokens);

    for (size_t bi = 0; bi < batchSize; ++bi) {
        const ScenarioResult scenario = ctx.scenarioSelector.select();

        LogEntry entry;
        entry.deviceId    = devId;
        entry.deviceName  = devName;
        entry.timestampMs = nowMs;

        if (scenario.isCustom && scenario.compiledCustomLog) {
            if (r.timestamp)    assignSV(*r.timestamp,    ctx.fieldGen.generateTimestamp());
            if (r.date)         assignSV(*r.date,         ctx.fieldGen.generateDate());
            if (r.time)         assignSV(*r.time,         ctx.fieldGen.generateTime());
            if (r.attackSeqNum) assignSV(*r.attackSeqNum, ctx.fieldGen.generateSeqNum());
            if (srcIpRandom && r.srcIp)
                                assignSV(*r.srcIp,        ctx.fieldGen.generateRandomSrcIp());
            if (dstIpRandom && r.dstIp)
                                assignSV(*r.dstIp,        ctx.fieldGen.generateRandomDstIp());
            if (r.srcPort)  assignSV(*r.srcPort,  u32ToSV(ctx.fieldGen.generateRandomSrcPort(),      ctx.srcPortBuf, 8));
            if (r.dstPort)  assignSV(*r.dstPort,  u32ToSV(ctx.fieldGen.generateRandomPort(dstPorts), ctx.dstPortBuf, 8));
            if (r.action)   assignSV(*r.action,   ctx.fieldGen.generateAction(allowPct));
            if (r.attackName) assignSV(*r.attackName, scenario.attackName);
            if (r.proto)    assignSV(*r.proto,    ctx.fieldGen.generateProto());

            entry.rawLog = LogTemplateEngine::renderCompiled(*scenario.compiledCustomLog, ctx.tokens);
            ctx.sendBuf.push_back(entry.rawLog);
            ctx.dispatchBuf.push_back(std::move(entry));
            continue;
        }

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
        if (r.attackName) assignSV(*r.attackName, scenario.attackName);
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

        if (r.blackSha1)    *r.blackSha1    = ctx.fieldGen.generateBlackSha1();
        if (r.city)         assignSV(*r.city,         ctx.fieldGen.generateCity());
        if (r.email)        assignSV(*r.email,        ctx.fieldGen.generateEmail());
        if (r.extField)     assignSV(*r.extField,     ctx.fieldGen.generateExtField());
        if (r.instCd1)      assignSV(*r.instCd1,      ctx.fieldGen.generateInstCd1());
        if (r.latitude)     assignSV(*r.latitude,     ctx.fieldGen.generateLatitude());
        if (r.originalLog)  assignSV(*r.originalLog,  ctx.fieldGen.generateOriginalLog());
        if (r.payload)      assignSV(*r.payload,      ctx.fieldGen.generatePayload());
        if (r.rebuildDt)    assignSV(*r.rebuildDt,    ctx.fieldGen.generateRebuildDt());
        if (r.regiNo)       assignSV(*r.regiNo,       ctx.fieldGen.generateRegiNo());
        if (r.trafficType)  assignSV(*r.trafficType,  ctx.fieldGen.generateTrafficType());
        if (r.virusDivision) assignSV(*r.virusDivision, ctx.fieldGen.generateVirusDivision());
        if (r.inPktSize)    assignSV(*r.inPktSize,    u32ToSV(ctx.fieldGen.generateRandomCount(64, 65535),  ctx.byteBuf, 8));
        if (r.outPktCnt)    assignSV(*r.outPktCnt,    u32ToSV(ctx.fieldGen.generateRandomCount(1,    200),  ctx.pktBuf,  8));
        if (r.outPktSize)   assignSV(*r.outPktSize,   u32ToSV(ctx.fieldGen.generateRandomCount(64, 65535),  ctx.byteBuf, 8));
        if (r.count)        assignSV(*r.count,        u32ToSV(ctx.fieldGen.generateRandomCount(1,    100),  ctx.pktBuf,  8));
        if (r.fileSize)     assignSV(*r.fileSize,     u32ToSV(ctx.fieldGen.generateRandomCount(1024, 10485760), ctx.byteBuf, 8));

        if (r.gatherEtime && r.timestamp)  *r.gatherEtime   = *r.timestamp;
        if (r.prtc        && r.proto)      *r.prtc          = *r.proto;
        if (r.virusAction && r.action)     *r.virusAction   = *r.action;
        if (r.dstnIp      && r.dstIp)      *r.dstnIp        = *r.dstIp;
        if (r.dstnPort    && r.dstPort)    *r.dstnPort      = *r.dstPort;
        if (r.srcCountryCode && r.tiCountryCode) *r.srcCountryCode = *r.tiCountryCode;
        if (r.dstnIpLong  && r.dstnIp && !r.dstnIp->empty())
            *r.dstnIpLong = ctx.fieldGen.generateIpLong(*r.dstnIp);

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
                if (r.srcCountryCode) *r.srcCountryCode = ti.countryCode;
            }
        }

        entry.rawLog = ctx.templateEngine.render(ctx.tokens);
        ctx.sendBuf.push_back(entry.rawLog);
        ctx.dispatchBuf.push_back(std::move(entry));
    }
}

uint64_t GeneratorEngine::sendAndDispatch(WorkerContext& ctx, size_t batchSize) {
    const DeviceProfile& p  = ctx.profile;
    ISender*   sender    = ctx.connMgr.sender();
    UDPSender* udpSender = ctx.connMgr.udpSender();
    uint64_t sentCount = 0;

    if (udpSender) {
        sentCount = static_cast<uint64_t>(udpSender->sendBatchGetCount(ctx.sendBuf));
        if (sentCount > 0) ctx.connMgr.resetFails();
        else               ctx.connMgr.incFails();
    } else {
        if (sender->sendBatch(ctx.sendBuf)) {
            sentCount = static_cast<uint64_t>(batchSize);
            ctx.connMgr.resetFails();
        } else {
            ctx.connMgr.incFails();
            LOG_WARN("NETWORK", std::format("sendBatch failed ({}/{}): device={}, target={}:{}",
                ctx.connMgr.consecutiveFails(), Constants::Engine::kMaxConsecutiveFails,
                p.deviceName, p.collector.ip, p.collector.port));
            ctx.connMgr.reconnectIfNeeded(p);
        }
    }

    if (sentCount > 0)
        m_dispatchQueue.tryPushBatch(ctx.dispatchBuf, sentCount);

    return sentCount;
}

void GeneratorEngine::updateRateStats(WorkerContext& ctx,
                                       uint64_t       sentCount,
                                       std::chrono::steady_clock::time_point now) {
    ctx.logsSentInThisInterval += sentCount;
    const double elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(
        now - ctx.lastRateCalcTime).count();

    if (elapsed >= Constants::Engine::kRateCalcIntervalSec) {
        const float rate = static_cast<float>(
            static_cast<double>(ctx.logsSentInThisInterval) / elapsed);
        if (ctx.devRateFixed)
            ctx.devRateFixed->store(floatToFixed(rate), std::memory_order_relaxed);
        ctx.logsSentInThisInterval = 0;
        ctx.lastRateCalcTime       = now;
    }
}

bool Generator