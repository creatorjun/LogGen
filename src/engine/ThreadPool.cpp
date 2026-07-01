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
    const DWORD cpuCount = std::max<DWORD>(1, GetActiveProcessorCount(ALL_PROCESSOR_GROUPS));
    const DWORD targetCpu = static_cast<DWORD>(index % cpuCount);
    if (targetCpu < (sizeof(DWORD_PTR) * 8)) {
        const DWORD_PTR mask = (static_cast<DWORD_PTR>(1) << targetCpu);
        SetThreadAffinityMask(GetCurrentThread(), mask);
    }
#else
    const long cpuCount = std::max<long>(1, sysconf(_SC_NPROCESSORS_ONLN));
    const size_t targetCpu = index % static_cast<size_t>(cpuCount);
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(static_cast<int>(targetCpu), &cpuset);
    pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cpuset);
#endif
}

ThreadPool::ThreadPool(size_t threads, bool enableAffinity)
    : m_enableAffinity(enableAffinity)
{
    for (size_t i = 0; i < threads; ++i) {
        m_workers.emplace_back([this, i] {
            if (m_enableAffinity) pinCurrentThread(i);
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(m_queueMutex);
                    m_cv.wait(lock, [this] {
                        return m_stop.load(std::memory_order_relaxed) || !m_tasks.empty();
                    });
                    if (m_stop.load(std::memory_order_relaxed) && m_tasks.empty()) return;
                    task = std::move(m_tasks.front());
                    m_tasks.pop();
                }
                task();
            }
        });
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(m_queueMutex);
        if (m_stop.load(std::memory_order_relaxed)) return;
        m_tasks.emplace(std::move(task));
    }
    m_cv.notify_one();
}

ThreadPool::~ThreadPool() {
    m_stop.store(true, std::memory_order_release);
    m_cv.notify_all();
    for (std::thread& worker : m_workers)
        if (worker.joinable()) worker.join();
}
