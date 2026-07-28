// src/engine/ThreadPool.h
#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <functional>
#include <cstddef>
#include <new>
#include <memory>

class ThreadPool {
public:
    explicit ThreadPool(size_t threads, bool enableAffinity = true);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

private:
    static void pinCurrentThread(size_t index);

    static constexpr size_t kCacheLine  = std::hardware_destructive_interference_size;
    static constexpr size_t kQueueCap   = 65536;
    static constexpr size_t kQueueMask  = kQueueCap - 1;

    static_assert((kQueueCap & kQueueMask) == 0, "kQueueCap must be power of 2");

    struct alignas(kCacheLine) Cell {
        std::atomic<size_t>   seq{0};
        std::function<void()> task;
    };

    struct alignas(kCacheLine) PaddedIdx {
        std::atomic<size_t> val{0};
        char pad[kCacheLine - sizeof(std::atomic<size_t>)];
    };

    static_assert(sizeof(PaddedIdx) == kCacheLine);

    Cell       m_buf[kQueueCap];
    PaddedIdx  m_enq;
    PaddedIdx  m_deq;

    std::vector<std::thread> m_workers;
    std::atomic<bool>        m_stop{false};
    bool                     m_enableAffinity{true};

    std::atomic<bool>        m_taskFlag{false};
};
