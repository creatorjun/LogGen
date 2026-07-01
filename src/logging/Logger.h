// src/logging/Logger.h
#pragma once

#include <string_view>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <fstream>
#include <atomic>

namespace logging {

enum class LogLevel {
    Debug,
    Info,
    Warn,
    Error
};

class Logger {
public:
    [[nodiscard]] static Logger& instance();

    void initialize(std::string_view logDir = "logs",
                    LogLevel minLevel = LogLevel::Info);
    void shutdown();
    void log(LogLevel level, std::string_view domain, std::string_view message);

    Logger(const Logger&)            = delete;
    Logger& operator=(const Logger&) = delete;

private:
    Logger()  = default;
    ~Logger() = default;

    void                      writerLoop();
    [[nodiscard]] std::string_view levelToString(LogLevel level) const noexcept;
    [[nodiscard]] std::string      nowTimestamp() const;
    [[nodiscard]] std::string      buildLogFilePath(std::string_view logDir) const;

    std::mutex              m_mutex;
    std::condition_variable m_cv;
    std::deque<std::string> m_queue;
    std::thread             m_writerThread;
    std::ofstream           m_file;
    std::atomic<bool>       m_running{false};
    std::atomic<int>        m_minLevelAtomic{static_cast<int>(LogLevel::Info)};
    bool                    m_initialized = false;
    LogLevel                m_minLevel    = LogLevel::Info;
};

} // namespace logging

#define LOG_DEBUG(domain, message) ::logging::Logger::instance().log(::logging::LogLevel::Debug, domain, message)
#define LOG_INFO(domain, message)  ::logging::Logger::instance().log(::logging::LogLevel::Info,  domain, message)
#define LOG_WARN(domain, message)  ::logging::Logger::instance().log(::logging::LogLevel::Warn,  domain, message)
#define LOG_ERROR(domain, message) ::logging::Logger::instance().log(::logging::LogLevel::Error, domain, message)
