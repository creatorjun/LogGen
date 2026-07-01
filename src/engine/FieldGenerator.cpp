// src/engine/FieldGenerator.cpp
#include "FieldGenerator.h"
#include "logging/Logger.h"
#include <charconv>
#include <cstring>
#include <ctime>
#include <format>

FieldGenerator::FieldGenerator()
    : m_rng(std::random_device{}())
{}

void FieldGenerator::setDateOffsetDays(int days) {
    m_dateOffsetDays = days;
    m_tsLen = 0;
}

void FieldGenerator::refreshTimestamp() const {
    auto now = std::chrono::system_clock::now();
    if (m_dateOffsetDays != 0)
        now += std::chrono::hours(24 * m_dateOffsetDays);

    const auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - m_lastTsTime);
    if (m_tsLen > 0 && diff.count() == 0) return;
    m_lastTsTime = now;

    const auto t = std::chrono::system_clock::to_time_t(now);
    struct tm tm_buf{};
#ifdef _WIN32
    localtime_s(&tm_buf, &t);
#else
    localtime_r(&t, &tm_buf);
#endif
    m_tsLen   = std::strftime(m_tsBuf,   sizeof(m_tsBuf),   "%Y-%m-%dT%H:%M:%S", &tm_buf);
    m_dateLen = std::strftime(m_dateBuf, sizeof(m_dateBuf), "%Y-%m-%d",           &tm_buf);
    m_timeLen = std::strftime(m_timeBuf, sizeof(m_timeBuf), "%H:%M:%S",           &tm_buf);
}

std::string_view FieldGenerator::generateTimestamp() const {
    refreshTimestamp();
    return { m_tsBuf, m_tsLen };
}

std::string_view FieldGenerator::generateDate() const {
    refreshTimestamp();
    return { m_dateBuf, m_dateLen };
}

std::string_view FieldGenerator::generateTime() const {
    refreshTimestamp();
    return { m_timeBuf, m_timeLen };
}

uint32_t FieldGenerator::ipToUint(std::string_view ipStr) const {
    uint32_t    result = 0;
    const char* p      = ipStr.data();
    const char* end    = p + ipStr.size();
    for (int shift = 24; shift >= 0 && p < end; shift -= 8) {
        uint32_t octet = 0;
        auto [next, ec] = std::from_chars(p, end, octet);
        result |= (octet << shift);
        p = (next < end && *next == '.') ? next + 1 : end;
    }
    return result;
}

void FieldGenerator::uintToIpBuf(uint32_t ipVal, char* buf, size_t& len) const {
    char* p = buf;
    auto writeOctet = [&](uint32_t v) {
        char tmp[4];
        auto [end, ec] = std::to_chars(tmp, tmp + 4, v);
        std::memcpy(p, tmp, end - tmp);
        p += (end - tmp);
    };
    writeOctet((ipVal >> 24) & 0xFF); *p++ = '.';
    writeOctet((ipVal >> 16) & 0xFF); *p++ = '.';
    writeOctet((ipVal >>  8) & 0xFF); *p++ = '.';
    writeOctet( ipVal        & 0xFF);
    len = static_cast<size_t>(p - buf);
}

void FieldGenerator::setIpRange(const std::string& startIp, const std::string& endIp) {
    m_cachedIpStart = ipToUint(startIp);
    m_cachedIpEnd   = ipToUint(endIp);
    if (m_cachedIpStart > m_cachedIpEnd) std::swap(m_cachedIpStart, m_cachedIpEnd);
    m_distIp = std::uniform_int_distribution<uint32_t>(m_cachedIpStart, m_cachedIpEnd);
}

void FieldGenerator::cacheIpRange(const std::string& startIp, const std::string& endIp) {
    const uint32_t s   = ipToUint(startIp);
    const uint32_t e   = ipToUint(endIp);
    m_cachedIpStart    = std::min(s, e);
    m_cachedIpEnd      = std::max(s, e);
    m_distCachedIp     = std::uniform_int_distribution<uint32_t>(m_cachedIpStart, m_cachedIpEnd);
    m_hasCachedIpRange = true;
}

void FieldGenerator::cacheDstIpRange(const std::string& startIp, const std::string& endIp) {
    const uint32_t s      = ipToUint(startIp);
    const uint32_t e      = ipToUint(endIp);
    m_cachedDstIpStart    = std::min(s, e);
    m_cachedDstIpEnd      = std::max(s, e);
    m_distCachedDstIp     = std::uniform_int_distribution<uint32_t>(m_cachedDstIpStart, m_cachedDstIpEnd);
    m_hasCachedDstIpRange = true;
}

std::string_view FieldGenerator::generateRandomSrcIp() const {
    const uint32_t ip = m_hasCachedIpRange ? m_distCachedIp(m_rng) : m_distIp(m_rng);
    uintToIpBuf(ip, m_ipBuf, m_ipLen);
    return { m_ipBuf, m_ipLen };
}

std::string_view FieldGenerator::generateRandomDstIp() const {
    const uint32_t ip = m_hasCachedDstIpRange ? m_distCachedDstIp(m_rng) : m_distIp(m_rng);
    uintToIpBuf(ip, m_dstIpBuf, m_dstIpLen);
    return { m_dstIpBuf, m_dstIpLen };
}

std::string FieldGenerator::generateRandomSrcIp(
    const std::string& startIp, const std::string& endIp) const
{
    const uint32_t s = ipToUint(startIp);
    const uint32_t e = ipToUint(endIp);
    std::uniform_int_distribution<uint32_t> d(std::min(s, e), std::max(s, e));
    char buf[16]; size_t len;
    uintToIpBuf(d(m_rng), buf, len);
    return std::string(buf, len);
}

uint16_t FieldGenerator::generateRandomSrcPort() const {
    return m_distSrcPort(m_rng);
}

uint16_t FieldGenerator::generateRandomPort(const std::vector<uint16_t>& ports) const {
    if (ports.empty()) return 80;
    std::uniform_int_distribution<size_t> d(0, ports.size() - 1);
    return ports[d(m_rng)];
}

std::string_view FieldGenerator::generateAction(int allowPct) const {
    static constexpr std::array<std::string_view, 2> kTbl{ "allow", "deny" };
    return (m_distAction(m_rng) <= allowPct) ? kTbl[0] : kTbl[1];
}

std::string_view FieldGenerator::generateSeverity() const {
    static constexpr std::array<std::string_view, 4> kTbl{ "low", "medium", "high", "critical" };
    static_assert(kTbl.size() == 4, "kTbl size mismatch with m_distSeverity range [0,3]");
    return pickFromTable(kTbl, m_distSeverity);
}

std::string_view FieldGenerator::generateProto() const {
    static constexpr std::array<std::string_view, 3> kTbl{ "TCP", "UDP", "ICMP" };
    static_assert(kTbl.size() == 3, "kTbl size mismatch with m_distProto range [0,2]");
    return pickFromTable(kTbl, m_distProto);
}

std::string_view FieldGenerator::generatePriority() const {
    auto [end, ec] = std::to_chars(
        m_priorityBuf, m_priorityBuf + sizeof(m_priorityBuf),
        m_distPriority(m_rng));
    m_priorityLen = static_cast<size_t>(end - m_priorityBuf);
    return { m_priorityBuf, m_priorityLen };
}

std::string_view FieldGenerator::generateEventType() const {
    static constexpr std::array<std::string_view, 4> kTbl{ "alert", "log", "drop", "pass" };
    static_assert(kTbl.size() == 4, "kTbl size mismatch with m_distEventType range [0,3]");
    return pickFromTable(kTbl, m_distEventType);
}

std::string_view FieldGenerator::generateConnId() const {
    auto [end, ec] = std::to_chars(
        m_connIdBuf, m_connIdBuf + sizeof(m_connIdBuf),
        m_distConnId(m_rng));
    m_connIdLen = static_cast<size_t>(end - m_connIdBuf);
    return { m_connIdBuf, m_connIdLen };
}

std::string_view FieldGenerator::generatePid() const {
    auto [end, ec] = std::to_chars(
        m_pidBuf, m_pidBuf + sizeof(m_pidBuf),
        m_distPid(m_rng));
    m_pidLen = static_cast<size_t>(end - m_pidBuf);
    return { m_pidBuf, m_pidLen };
}

std::string_view FieldGenerator::generateEventId() const {
    static constexpr std::array<std::string_view, 7> kTbl{
        "1000", "1001", "1002", "1003", "2000", "4624", "4625"
    };
    static_assert(kTbl.size() == 7, "kTbl size mismatch with m_distEventId range [0,6]");
    return pickFromTable(kTbl, m_distEventId);
}

std::string_view FieldGenerator::generateUsername() const {
    static constexpr std::array<std::string_view, 8> kTbl{
        "admin", "user", "guest", "root",
        "service", "operator", "test", "system"
    };
    static_assert(kTbl.size() == 8, "kTbl size mismatch with m_distUsername range [0,7]");
    return pickFromTable(kTbl, m_distUsername);
}

std::string_view FieldGenerator::generateHttpMethod() const {
    static constexpr std::array<std::string_view, 6> kTbl{
        "GET", "POST", "PUT", "DELETE", "PATCH", "HEAD"
    };
    static_assert(kTbl.size() == 6, "kTbl size mismatch with m_distHttpMethod range [0,5]");
    return pickFromTable(kTbl, m_distHttpMethod);
}

std::string_view FieldGenerator::generateUri() const {
    static constexpr std::array<std::string_view, 10> kTbl{
        "/api/v1/login", "/api/v1/data", "/upload", "/download", "/admin",
        "/health", "/metrics", "/static/js/app.js", "/favicon.ico", "/"
    };
    static_assert(kTbl.size() == 10, "kTbl size mismatch with m_distUri range [0,9]");
    return pickFromTable(kTbl, m_distUri);
}

std::string_view FieldGenerator::generateHttpHost() const {
    static constexpr std::array<std::string_view, 5> kTbl{
        "example.com", "api.internal", "cdn.example.net",
        "mail.company.co", "login.service.io"
    };
    static_assert(kTbl.size() == 5, "kTbl size mismatch with m_distHost range [0,4]");
    return pickFromTable(kTbl, m_distHost);
}

std::string_view FieldGenerator::generateSeqNum() const {
    const uint64_t seq = m_seqCounter.fetch_add(1, std::memory_order_relaxed);
    auto [end, ec] = std::to_chars(m_seqBuf, m_seqBuf + sizeof(m_seqBuf), seq);
    m_seqLen = static_cast<size_t>(end - m_seqBuf);
    return { m_seqBuf, m_seqLen };
}

uint32_t FieldGenerator::generateRandomCount(uint32_t minVal, uint32_t maxVal) const {
    if (minVal > maxVal) std::swap(minVal, maxVal);
    std::uniform_int_distribution<uint32_t> d(minVal, maxVal);
    return d(m_rng);
}

size_t FieldGenerator::pickIndex(size_t count) const {
    if (count == 0) return 0;
    std::uniform_int_distribution<size_t> d(0, count - 1);
    return d(m_rng);
}

std::string FieldGenerator::generate(const std::string& key) const {
    if (key == "timestamp")   return std::string(generateTimestamp());
    if (key == "random_ip")   return std::string(generateRandomSrcIp());
    if (key == "random_port") return std::to_string(generateRandomSrcPort());
    LOG_DEBUG("TEMPLATE", std::format("FieldGenerator::generate unknown key=[{}]", key));
    return std::format("?{}?", key);
}
