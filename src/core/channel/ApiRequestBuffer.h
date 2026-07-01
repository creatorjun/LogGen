// src/core/channel/ApiRequestBuffer.h
#pragma once

#include <vector>
#include <mutex>
#include <atomic>
#include <cstdint>
#include "core/ApiRequestEntry.h"
#include "core/Constants.h"

class ApiRequestBuffer {
public:
    explicit ApiRequestBuffer(size_t capacity = Constants::Memory::kApiRequestBufferCapacity)
        : m_buf(capacity)
        , m_capacity(capacity)
        , m_head(0)
        , m_count(0)
    {}

    void push(ApiRequestEntry entry) {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_buf[m_head] = std::move(entry);
        m_head = (m_head + 1) % m_capacity;
        if (m_count < m_capacity) ++m_count;
        m_version.fetch_add(1, std::memory_order_relaxed);
    }

    [[nodiscard]] std::vector<ApiRequestEntry> getEntries() const {
        std::lock_guard<std::mutex> lk(m_mutex);
        std::vector<ApiRequestEntry> out;
        out.reserve(m_count);
        const size_t start = (m_count < m_capacity) ? 0 : m_head;
        for (size_t i = 0; i < m_count; ++i)
            out.push_back(m_buf[(start + i) % m_capacity]);
        return out;
    }

    [[nodiscard]] uint64_t getVersion() const {
        return m_version.load(std::memory_order_relaxed);
    }

    void clear() {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_head  = 0;
        m_count = 0;
        m_version.fetch_add(1, std::memory_order_relaxed);
    }

private:
    std::vector<ApiRequestEntry> m_buf;
    size_t                       m_capacity;
    size_t                       m_head;
    size_t                       m_count;
    mutable std::mutex           m_mutex;
    std::atomic<uint64_t>        m_version{0};
};
