// src/engine/LogDispatchQueue.h
#pragma once

#include <vector>
#include <atomic>
#include <array>
#include <thread>
#include <chrono>
#include <cstddef>
#include <new>
#include "core/LogEntry.h"
#include "core/Constants.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4324)
#endif

class LogDispatchQueue {
public:
    explicit LogDispatchQueue(size_t capacity = Constants::Memory::kLogDispatchQueueDefault)
        : m_capacity(nextPow2(capacity))
        , m_mask(m_capacity - 1)
        , m_buf(m_capacity)
    {
        for (size_t i = 0; i < m_capacity; ++i)
            m_buf[i].seq.store(i, std::memory_order_relaxed);
        m_enqueuePos.store(0, std::memory_order_relaxed);
        m_dequeuePos.store(0, std::memory_order_relaxed);
        m_wakeFlag.store(false, std::memory_order_relaxed);
    }

    bool tryPush(LogEntry entry) {
        Cell*  cell;
        size_t pos = m_enqueuePos.load(std::memory_order_relaxed);
        for (;;) {
            cell = &m_buf[pos & m_mask];
            size_t   seq  = cell->seq.load(std::memory_order_acquire);
            intptr_t diff = static_cast<intptr_t>(seq) - static_cast<intptr_t>(pos);
            if (diff == 0) {
                if (m_enqueuePos.compare_exchange_weak(pos, pos + 1,
                        std::memory_order_relaxed))
                    break;
            } else if (diff < 0) {
                return false;
            } else {
                pos = m_enqueuePos.load(std::memory_order_relaxed);
            }
        }
        cell->data = std::move(entry);
        cell->seq.store(pos + 1, std::memory_order_release);
        return true;
    }

    size_t tryPushBatch(const std::vector<LogEntry>& entries, size_t count) {
        size_t pushed = 0;
        for (size_t i = 0; i < count; ++i) {
            if (!tryPush(entries[i])) break;
            ++pushed;
        }
        return pushed;
    }

    // SINGLE_CONSUMER CONTRACT: drain() must be called from exactly one
    // thread at a time. m_dequeuePos is never contended during this call,
    // so the batch loop uses fetch_add instead of CAS to advance the
    // position — fetch_add has no failure path and no branch on LL/SC
    // architectures (ARM, RISC-V). Do NOT introduce CAS or multi-consumer
    // patterns here without revisiting the entire dequeue logic.
    size_t drain(std::vector<LogEntry>& out, const std::atomic<bool>& running) {
        out.clear();

        size_t pos  = m_dequeuePos.load(std::memory_order_relaxed);
        int    spin = 0;

        // 단건 dequeue: spin/yield/sleep 루프 내에서 spurious failure는
        // 재진입으로 처리되므로 compare_exchange_weak 유지
        for (;;) {
            Cell*    cell = &m_buf[pos & m_mask];
            size_t   seq  = cell->seq.load(std::memory_order_acquire);
            intptr_t diff = static_cast<intptr_t>(seq) - static_cast<intptr_t>(pos + 1);

            if (diff == 0) {
                if (m_dequeuePos.compare_exchange_weak(pos, pos + 1,
                        std::memory_order_relaxed)) {
                    out.push_back(std::move(cell->data));
                    cell->seq.store(pos + m_capacity, std::memory_order_release);
                    break;
                }
                continue;
            }

            if (!running.load(std::memory_order_relaxed) && empty())
                return 0;

            if (spin < Constants::Queue::kSpinCount) {
                ++spin;
                continue;
            }
            if (spin < Constants::Queue::kSpinCount + Constants::Queue::kYieldCount) {
                ++spin;
                std::this_thread::yield();
                continue;
            }

            if (m_wakeFlag.load(std::memory_order_acquire)) {
                m_wakeFlag.store(false, std::memory_order_relaxed);
                return 0;
            }

            std::this_thread::sleep_for(Constants::Queue::kSleepDuration);
            pos  = m_dequeuePos.load(std::memory_order_relaxed);
            spin = 0;
        }

        // 배치 수집 루프: 단일 소비자 보장 하에 CAS 불필요.
        // seq 가드(diff != 0)가 미기록 슬롯 접근을 막으므로 정확성 유지.
        // fetch_add는 조건 분기 없는 원자 증가 — LL/SC 아키텍처에서
        // CAS strong 내부 재시도 루프가 완전히 제거됨.
        size_t cur = pos + 1;
        for (;;) {
            Cell*    cell = &m_buf[cur & m_mask];
            size_t   seq  = cell->seq.load(std::memory_order_acquire);
            intptr_t diff = static_cast<intptr_t>(seq) - static_cast<intptr_t>(cur + 1);
            if (diff != 0) break;

            m_dequeuePos.fetch_add(1, std::memory_order_relaxed);
            out.push_back(std::move(cell->data));
            cell->seq.store(cur + m_capacity, std::memory_order_release);
            cur++;
        }
        return out.size();
    }

    void wakeAll() {
        m_wakeFlag.store(true, std::memory_order_release);
    }

    [[nodiscard]] bool   empty()    const noexcept {
        const size_t enq = m_enqueuePos.load(std::memory_order_relaxed);
        const size_t deq = m_dequeuePos.load(std::memory_order_relaxed);
        return enq == deq;
    }

    [[nodiscard]] size_t capacity() const noexcept { return m_capacity; }

private:
    static constexpr size_t kCacheLine =
        std::hardware_destructive_interference_size;

    static constexpr size_t kAtomicSz  = sizeof(std::atomic<size_t>);
    static constexpr size_t kPadSize   = kCacheLine > kAtomicSz
                                             ? kCacheLine - kAtomicSz
                                             : 1;

    static_assert(kCacheLine >= kAtomicSz,
        "hardware_destructive_interference_size < sizeof(atomic<size_t>): "
        "padding would underflow — review platform cache line assumptions");

    struct alignas(kCacheLine) Cell {
        std::atomic<size_t> seq;
        LogEntry            data;
    };

    static size_t nextPow2(size_t v) noexcept {
        if (v == 0) return 1;
        --v;
        v |= v >> 1;  v |= v >> 2;  v |= v >> 4;
        v |= v >> 8;  v |= v >> 16; v |= v >> 32;
        return ++v;
    }

    alignas(kCacheLine) std::atomic<size_t> m_enqueuePos;
    [[no_unique_address]]
    std::array<std::byte, kPadSize>         m_padEnqueue;

    alignas(kCacheLine) std::atomic<size_t> m_dequeuePos;
    [[no_unique_address]]
    std::array<std::byte, kPadSize>         m_padDequeue;

    alignas(kCacheLine) std::atomic<bool>   m_wakeFlag;

    size_t            m_capacity;
    size_t            m_mask;
    std::vector<Cell> m_buf;
};

#ifdef _MSC_VER
#pragma warning(pop)
#endif
