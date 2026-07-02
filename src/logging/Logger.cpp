// src/logging/Logger.cpp
#include "logging/Logger.h"
#include "core/Constants.h"

#include <print>
#include <format>
#include <chrono>
#include <filesystem>

namespace logging {

Logger& Logger::instance() {
    static Logger inst;
    return inst;
}

void Logger::initialize(std::string_view logDir, LogLevel minLevel) {
    std::lock_guard<std::mutex> lk(m_mutex);
    if (m_initialized) return;

    m_minLevel = minLevel;
    m_minLevelAtomic.store(static_cast<int>(minLevel), std::memory_order_release);
    std::filesystem::create_directories(logDir);
    m_file.open(buildLogFilePath(logDir), std::ios::out | std::ios::app);
    m_running.store(true, std::memory_order_release);
    m_writerThread = std::thread(&Logger::writerLoop, this);
    m_initialized = true;
}

void Logger::shutdown() {
    {
        std::lock_guard<std::mutex> lk(m_mutex);
        if (!m_initialized) return;
        m_running.store(false, std::memory_order_release);
    }
    m_cv.notify_all();
    if (m_writerThread.joinable())
        m_writerThread.join();

    if (m_file.is_open()) {
        m_file.flush();
        m_file.close();
    }

    std::lock_guard<std::mutex> lk(m_mutex);
    m_initialized = false;
}

void Logger::log(LogLevel level,
                 std::string_view domain,
                 std::string_view message,
                 std::source_location loc)
{
    if (static_cast<int>(level) < m_minLevelAtomic.load(std::memory_order_relaxed)) return;

    std::string line = std::format("[{}] [{}] [{}] [{}:{}] {}",
        nowTimestamp(),
        levelToString(level),
        domain,
        loc.file_name(),
        loc.line(),
        message);

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        if (!m_initialized) return;
        m_queue.push_back(std::move(line));
    }
    m_cv.notify_one();
}

void Logger::writerLoop() {
    auto lastFlush = std::chrono::steady_clock::now();

    while (true) {
        std::deque<std::string> batch;
        {
            std::unique_lock<std::mutex> lk(m_mutex);
            m_cv.wait(lk, [this] {
                return !m_running.load(std::memory_order_acquire) || !m_queue.empty();
            });

            if (!m_running.load(std::memory_order_acquire) && m_queue.empty())
                break;

            batch.swap(m_queue);
        }

        for (const auto& entry : batch) {
            std::println("{}", entry);
            if (m_file.is_open())
                m_file << entry << '\n';
        }

        const auto now = std::chrono::steady_clock::now();
        if (now - lastFlush >= Constants::Logging::kFlushInterval) {
            if (m_file.is_open()) m_file.flush();
            lastFlush = now;
        }
    }

    if (m_file.is_open()) m_file.flush();
}

std::string_view Logger::levelToString(LogLevel level) const noexcept {
    switch (level) {
        case LogLevel::Debug: return "DEBUG";
        case LogLevel::Info:  return "INFO";
        case LogLevel::Warn:  return "WARN";
        case LogLevel::Error: return "ERROR";
    }
    return "INFO";
}

std::string Logger::nowTimestamp() const {
    const auto now  = std::chrono::system_clock::now();
    const auto secs = std::chrono::floor<std::chrono::seconds>(now);
    const auto ms   = std::chrono::duration_cast<std::chrono::milliseconds>(now - secs).count();

    return std::format("{:%Y-%m-%d %H:%M:%S}.{:03d}",
        std::chrono::zoned_time{std::chrono::current_zone(), secs},
        ms);
}

std::string Logger::buildLogFilePath(std::string_view logDir) const {
    const auto now  = std::chrono::system_clock::now();
    const auto days = std::chrono::floor<std::chrono::days>(now);

    return std::format("{}/app_{:%Y%m%d}.log",
        logDir,
        std::chrono::zoned_time{std::chrono::current_zone(), days});
}

} // namespace logging
