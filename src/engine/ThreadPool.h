// src/engine/ThreadPool.h
#pragma once

#include <vector>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
#include <cstddef>

class ThreadPool {
public:
    explicit ThreadPool(size_t threads, bool enableAffinity = true);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

private:
    static void pinCurrentThread(size_t index);

    std::vector<std::thread>           m_workers;
    std::deque<std::function<void()>>  m_tasks;
    std::mutex                         m_queueMutex;
    std::condition_variable            m_cv;
    std::atomic<bool>                  m_stop{false};
    bool                               m_enableAffinity{true};
};
