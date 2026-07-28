// src/engine/ThreadPool.cpp
#include "ThreadPool.h"
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#endif

void ThreadPool::pinCurrentThread(size_t index) {
#ifdef _WIN32
    const DWORD cpuCount  = std::max<DWORD>(1, GetActiveProcessorCount(ALL_PROCESSOR_GROUPS));
    const DWORD targetCpu = static_cast<DWORD>(index % cpuCount);
    if (targetCpu < (sizeof(DWORD_PTR) * 8)) {
        const DWORD_PTR mask = (static_cast<DWORD_PTR>(1) << targetCpu);
        SetThreadAffinityMask(GetCurrentThread(), mask);
    }
#else
    const long   cpuCount  = std::max<long>(1, sysconf(_SC_NPROCESSORS_ONLN));
    const size_t targetCpu = index % static_cast<size_t>(cpuCount);
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(static_cast<int>(targetCpu), &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
#endif
}

ThreadPool::ThreadPool(size_t threads, bool enableAffinity)
    : m_buf(std::make_unique<Cell[]>(kQueueCap))
    , m_enableAffinity(enableAffinity)
{
    for (size_t i = 0; i < kQueueCap; ++i)
        m_buf[i].seq.store(i, std::memory_order_relaxed);

    for (size_t i = 0; i < threads; ++i) {
        m_workers.emplace_back([this, i] {
            if (m_enableAffinity) pinCurrentThread(i);

            constexpr int kSpinMax  = 1000;
            constexpr int kYieldMax = 100;

            while (true) {
                size_t pos = m_deq.val.load(std::memory_order_relaxed);

                for (int spin = 0;;) {
                    Cell*    cell = &m_buf[pos & kQueueMask];
                    size_t   seq  = cell->seq.load(std::memory_order_acquire);
                    intptr_t diff = static_cast<intptr_t>(seq)
                                  - static_cast<intptr_t>(pos + 1);

                    if (diff == 0) {
                        if (m_deq.val.compare_exchange_weak(
                                pos, pos + 1, std::memory_order_relaxed))
                        {
                            std::function<void()> task = std::move(cell->task);
                            cell->seq.store(pos + kQueueCap,
                                            std::memory_order_release);
                            task();
                            break;
                        }
                        continue;
                    }

                    if (diff < 0) {
                        if (m_stop.load(std::memory_order_relaxed)) return;

                        if (spin < kSpinMax) {
                            ++spin;
                            continue;
                        }
                        if (spin < kSpinMax + kYieldMax) {
                            ++spin;
                            std::this_thread::yield();
                            continue;
                        }

                        const size_t observed = m_epoch.load(std::memory_order_acquire);
                        if (m_deq.val.load(std::memory_order_relaxed) != pos) {
                            pos  = m_deq.val.load(std::memory_order_relaxed);
                            spin = 0;
                            continue;
                        }
                        m_epoch.wait(observed, std::memory_order_acquire);

                        if (m_stop.load(std::memory_order_relaxed)) return;

                        pos  = m_deq.val.load(std::memory_order_relaxed);
                        spin = 0;
                        continue;
                    }

                    pos = m_deq.val.load(std::memory_order_relaxed);
                }
            }
        });
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    size_t pos = m_enq.val.load(std::memory_order_relaxed);
    Cell*  cell;

    for (;;) {
        cell             = &m_buf[pos & kQueueMask];
        size_t   seq     = cell->seq.load(std::memory_order_acquire);
        intptr_t diff    = static_cast<intptr_t>(seq)
                         - static_cast<intptr_t>(pos);

        if (diff == 0) {
            if (m_enq.val.compare_exchange_weak(
                    pos, pos + 1, std::memory_order_relaxed))
                break;
        } else if (diff < 0) {
            return;
        } else {
            pos = m_enq.val.load(std::memory_order_relaxed);
        }
    }

    cell->task = std::move(task);
    cell->seq.store(pos + 1, std::memory_order_release);

    m_epoch.fetch_add(1, std::memory_order_release);
    m_epoch.notify_one();
}

ThreadPool::~ThreadPool() {
    m_stop.store(true, std::memory_order_release);
    m_epoch.fetch_add(1, std::memory_order_release);
    m_epoch.notify_all();
    for (std::thread& w : m_workers)
        if (w.joinable()) w.join();
}
