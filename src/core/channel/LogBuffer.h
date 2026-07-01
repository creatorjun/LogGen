// src/core/channel/LogBuffer.h
#pragma once

#include <algorithm>
#include <vector>
#include <mutex>
#include <atomic>
#include <cstdint>
#include "core/LogEntry.h"
#include "core/Constants.h"

class LogBuffer {
public:
    static constexpr size_t kCapacity = Constants::Memory::kLogBufferCapacity;

    LogBuffer()
        : m_buf(kCapacity)
        , m_head(0)
        , m_count(0)
    {}

    void push(LogEntry entry) {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_buf[m_head] = std::move(entry);
        m_head = (m_head + 1) % kCapacity;
        if (m_count < kCapacity) ++m_count;
        m_totalPushed.fetch_add(1, std::memory_order_relaxed);
        m_version.fetch_add(1, std::memory_order_relaxed);
    }

    [[nodiscard]] uint64_t getVersion() const {
        return m_version.load(std::memory_order_relaxed);
    }

    [[nodiscard]] uint64_t getTotalPushed() const {
        return m_totalPushed.load(std::memory_order_relaxed);
    }

    [[nodiscard]] std::vector<LogEntry> getNewLogs(uint64_t& offset) const {
        std::lock_guard<std::mutex> lk(m_mutex);
        const uint64_t total = m_totalPushed.load(std::memory_order_relaxed);
        if (total <= offset) return {};

        const uint64_t newCount  = total - offset;
        const size_t   toFetch   = static_cast<size_t>(std::min(newCount, static_cast<uint64_t>(kCapacity)));
        const size_t   fetchCapped = std::min(toFetch, m_count);
        const size_t   startIdx  = (m_head + kCapacity - fetchCapped) % kCapacity;

        std::vector<LogEntry> result;
        result.reserve(fetchCapped);
        for (size_t i = 0; i < fetchCapped; ++i)
            result.push_back(m_buf[(startIdx + i) % kCapacity]);

        offset = total;
        return result;
    }

    void clear() {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_head  = 0;
        m_count = 0;
        m_totalPushed.store(0, std::memory_order_relaxed);
        m_version.fetch_add(1, std::memory_order_relaxed);
    }

private:
    std::vector<LogEntry>  m_buf;
    size_t                 m_head;
    size_t                 m_count;
    mutable std::mutex     m_mutex;
    std::atomic<uint64_t>  m_version{0};
    std::atomic<uint64_t>  m_totalPushed{0};
};
