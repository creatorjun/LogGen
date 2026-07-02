// src/logging/Logger.h
#pragma once

#include <string_view>
#include <source_location>
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
    void log(LogLevel level,
             std::string_view domain,
             std::string_view message,
             std::source_location loc = std::source_location::current());

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

namespace log_detail {

inline void emit(::logging::LogLevel level,
                 std::string_view domain,
                 std::string_view message,
                 std::source_location loc)
{
    ::logging::Logger::instance().log(level, domain, message, loc);
}

} // namespace log_detail

inline void LOG_DEBUG(std::string_view domain, std::string_view message,
    std::source_location loc = std::source_location::current())
{
    log_detail::emit(::logging::LogLevel::Debug, domain, message, loc);
}

inline void LOG_INFO(std::string_view domain, std::string_view message,
    std::source_location loc = std::source_location::current())
{
    log_detail::emit(::logging::LogLevel::Info, domain, message, loc);
}

inline void LOG_WARN(std::string_view domain, std::string_view message,
    std::source_location loc = std::source_location::current())
{
    log_detail::emit(::logging::LogLevel::Warn, domain, message, loc);
}

inline void LOG_ERROR(std::string_view domain, std::string_view message,
    std::source_location loc = std::source_location::current())
{
    log_detail::emit(::logging::LogLevel::Error, domain, message, loc);
}
