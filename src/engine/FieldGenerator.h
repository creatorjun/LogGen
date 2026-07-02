// src/engine/FieldGenerator.h
#pragma once

#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <atomic>
#include <random>
#include <chrono>
#include <cstdint>

class FieldGenerator {
public:
    FieldGenerator();

    void setIpRange(const std::string& startIp, const std::string& endIp);
    void cacheIpRange(const std::string& startIp, const std::string& endIp);
    void cacheDstIpRange(const std::string& startIp, const std::string& endIp);
    void setDateOffsetDays(int days);

    [[nodiscard]] std::string_view generateTimestamp()   const;
    [[nodiscard]] std::string_view generateDate()        const;
    [[nodiscard]] std::string_view generateTime()        const;
    [[nodiscard]] std::string_view generateRandomSrcIp() const;
    [[nodiscard]] std::string_view generateRandomDstIp() const;
    [[nodiscard]] std::string_view generateAction(int allowPct) const;
    [[nodiscard]] std::string_view generateSeverity()    const;
    [[nodiscard]] std::string_view generateProto()       const;
    [[nodiscard]] std::string_view generatePriority()    const;
    [[nodiscard]] std::string_view generateEventType()   const;
    [[nodiscard]] std::string_view generateConnId()      const;
    [[nodiscard]] std::string_view generatePid()         const;
    [[nodiscard]] std::string_view generateEventId()     const;
    [[nodiscard]] std::string_view generateUsername()    const;
    [[nodiscard]] std::string_view generateHttpMethod()  const;
    [[nodiscard]] std::string_view generateUri()         const;
    [[nodiscard]] std::string_view generateHttpHost()    const;
    [[nodiscard]] std::string_view generateSeqNum()      const;

    [[nodiscard]] uint16_t generateRandomSrcPort() const;
    [[nodiscard]] uint16_t generateRandomPort(const std::vector<uint16_t>& ports) const;
    [[nodiscard]] uint32_t generateRandomCount(uint32_t minVal, uint32_t maxVal) const;

    [[nodiscard]] std::string generateRandomSrcIp(const std::string& startIp,
                                                  const std::string& endIp) const;
    [[nodiscard]] std::string generate(const std::string& key) const;
    [[nodiscard]] size_t      pickIndex(size_t count) const;

private:
    template <size_t N>
    [[nodiscard]] std::string_view pickFromTable(
        const std::array<std::string_view, N>& tbl,
        std::uniform_int_distribution<int>& dist) const noexcept {
        return tbl[static_cast<size_t>(dist(m_rng))];
    }

    [[nodiscard]] uint32_t ipToUint(std::string_view ipStr) const;
    void                   uintToIpBuf(uint32_t ipVal, char* buf, size_t& len) const;
    void                   refreshTimestamp() const;

    int m_dateOffsetDays = 0;

    mutable std::mt19937 m_rng;

    mutable std::uniform_int_distribution<uint32_t> m_distIp;
    mutable std::uniform_int_distribution<uint16_t> m_distSrcPort{ 1024, 65535 };
    mutable std::uniform_int_distribution<int>      m_distSeverity{ 0, 3 };
    mutable std::uniform_int_distribution<int>      m_distProto{ 0, 2 };
    mutable std::uniform_int_distribution<int>      m_distPriority{ 1, 7 };
    mutable std::uniform_int_distribution<int>      m_distEventType{ 0, 3 };
    mutable std::uniform_int_distribution<uint32_t> m_distConnId{ 10000000u, 99999999u };
    mutable std::uniform_int_distribution<uint32_t> m_distPid{ 1000u, 65535u };
    mutable std::uniform_int_distribution<int>      m_distEventId{ 0, 6 };
    mutable std::uniform_int_distribution<int>      m_distUsername{ 0, 7 };
    mutable std::uniform_int_distribution<int>      m_distHttpMethod{ 0, 5 };
    mutable std::uniform_int_distribution<int>      m_distUri{ 0, 9 };
    mutable std::uniform_int_distribution<int>      m_distHost{ 0, 4 };
    mutable std::uniform_int_distribution<int>      m_distAction{ 1, 100 };

    mutable uint32_t m_cachedIpStart = 0;
    mutable uint32_t m_cachedIpEnd   = 0;
    mutable std::uniform_int_distribution<uint32_t> m_distCachedIp;
    mutable bool     m_hasCachedIpRange = false;

    mutable uint32_t m_cachedDstIpStart = 0;
    mutable uint32_t m_cachedDstIpEnd   = 0;
    mutable std::uniform_int_distribution<uint32_t> m_distCachedDstIp;
    mutable bool     m_hasCachedDstIpRange = false;

    // generateRandomCount 캐시: buildBatch에서 사용하는 두 고정 범위 [1,100], [64,65535]
    mutable std::uniform_int_distribution<uint32_t> m_distPktCnt{ 1u, 100u };
    mutable std::uniform_int_distribution<uint32_t> m_distByteCnt{ 64u, 65535u };

    // generateRandomPort 캐시: 포트 목록 크기가 바뀌었을 때만 param() 재설정
    mutable std::uniform_int_distribution<size_t> m_distDstPort{ 0, 0 };
    mutable size_t                                m_lastDstPortCount = 0;

    // pickIndex 캐시: count가 바뀌었을 때만 param() 재설정
    mutable std::uniform_int_distribution<size_t> m_distPickIndex{ 0, 0 };
    mutable size_t                                m_lastPickCount = 0;

    mutable char   m_tsBuf[32]   = {};
    mutable size_t m_tsLen       = 0;
    mutable char   m_dateBuf[16] = {};
    mutable size_t m_dateLen     = 0;
    mutable char   m_timeBuf[12] = {};
    mutable size_t m_timeLen     = 0;
    mutable std::chrono::time_point<std::chrono::system_clock> m_lastTsTime;

    mutable char   m_ipBuf[16]    = {};
    mutable size_t m_ipLen        = 0;
    mutable char   m_dstIpBuf[16] = {};
    mutable size_t m_dstIpLen     = 0;

    mutable char   m_priorityBuf[4]  = {};
    mutable size_t m_priorityLen     = 0;
    mutable char   m_connIdBuf[12]   = {};
    mutable size_t m_connIdLen       = 0;
    mutable char   m_pidBuf[8]       = {};
    mutable size_t m_pidLen          = 0;

    mutable std::atomic<uint64_t> m_seqCounter{ 1 };
    mutable char                  m_seqBuf[24] = {};
    mutable size_t                m_seqLen     = 0;
};
