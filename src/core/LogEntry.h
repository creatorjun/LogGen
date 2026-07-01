// src/core/LogEntry.h
#pragma once

#include <string>
#include <cstdint>

struct LogEntry {
    std::string deviceId;
    std::string deviceName;
    std::string rawLog;
    uint64_t    timestampMs = 0;

    LogEntry()                           = default;
    LogEntry(const LogEntry&)            = default;
    LogEntry(LogEntry&&)                 = default;
    LogEntry& operator=(const LogEntry&) = default;
    LogEntry& operator=(LogEntry&&)      = default;
};
