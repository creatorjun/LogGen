// src/core/channel/LockFreeLogBuffer.h
#pragma once

#include <vector>
#include <mutex>
#include <atomic>
#include <cstdint>
#include "core/LogEntry.h"
#include "core/Constants.h"

class MutexLogBuffer {
public:
    explicit MutexLogBuffer(size_t maxHistory = Constants::Memory::kMutexLogBufferHistory)
        : m_maxHistory(maxHistory)
        , m_logs(maxHistory)
        , m_head(0)
        , m_tail(0)
        , m_count(0)
        , m_version(0)
    {}

    void push(LogEntry entry) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_logs[m_tail] = std::move(entry);
        m_tail = (m_tail + 1) % m_maxHistory;
        if (m_count < m_maxHistory) {
            ++m_count;
        } else {
            m_head = (m_head + 1) % m_maxHistory;
        }
        m_version.fetch_add(1, std::memory_order_relaxed);
    }

    [[nodiscard]] std::vector<LogEntry> getLogs() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        std::vector<LogEntry> result;
        result.reserve(m_count);
        size_t curr = m_head;
        for (size_t i = 0; i < m_count; ++i) {
            result.push_back(m_logs[curr]);
            curr = (curr + 1) % m_maxHistory;
        }
        return result;
    }

    [[nodiscard]] uint64_t getVersion() const {
        return m_version.load(std::memory_order_relaxed);
    }

    void clear() {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_head  = 0;
        m_tail  = 0;
        m_count = 0;
        m_version.fetch_add(1, std::memory_order_relaxed);
    }

private:
    size_t                     m_maxHistory;
    std::vector<LogEntry>      m_logs;
    size_t                     m_head;
    size_t                     m_tail;
    size_t                     m_count;
    mutable std::mutex         m_mutex;
    std::atomic<uint64_t>      m_version;
};
