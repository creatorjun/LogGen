// src/core/ApiRequestEntry.h
#pragma once

#include <string>
#include <cstdint>

struct ApiRequestEntry {
    std::string timestamp;       // human-readable timestamp string
    uint64_t    timestampMs = 0; // epoch ms (optional)
    std::string method;
    std::string path;
    std::string sourceIp;
    std::string body;
    int         statusCode  = 200;
    int64_t     latencyMs   = 0;
};
