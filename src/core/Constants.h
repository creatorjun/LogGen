// src/core/Constants.h
#pragma once

#include <cstddef>
#include <cstdint>
#include <chrono>

namespace Constants {

    namespace Memory {
        inline constexpr size_t kMemoryPoolBlockSize      = 4096;
        inline constexpr size_t kLogDispatchQueueDefault  = 131072;
        inline constexpr size_t kLogBufferCapacity        = 2048;
        inline constexpr size_t kApiRequestBufferCapacity = 500;
        inline constexpr size_t kMutexLogBufferHistory    = 500;
    }

    namespace Engine {
        inline constexpr int    kDefaultThreadPoolSize  = 8;
        inline constexpr size_t kDefaultQueueCapacity   = 131072;
        inline constexpr size_t kBatchSize              = 256;
        inline constexpr size_t kFastBatchSize          = 8192;   // 4096 -> 8192
        inline constexpr double kFastPathThreshold      = 1000.0;
        inline constexpr double kMidPathThreshold       = 100.0;
        inline constexpr int    kMaxConsecutiveFails    = 5;
        inline constexpr auto   kReconnectInterval      = std::chrono::seconds(3);
        inline constexpr auto   kWorkerIdleWait         = std::chrono::milliseconds(100);
        inline constexpr double kRateCalcIntervalSec    = 1.0;
    }

    namespace Queue {
        inline constexpr int  kSpinCount     = 1000;
        inline constexpr int  kYieldCount    = 100;
        inline constexpr auto kSleepDuration = std::chrono::microseconds(50);
    }

    namespace Network {
        inline constexpr int    kTcpConnectTimeoutMs  = 3000;
        inline constexpr int    kTcpSendTimeoutMs     = 2000;
        inline constexpr size_t kUdpBatchCapacity     = 1024;          // 256  -> 1024
        inline constexpr int    kUdpSendBufferBytes   = 64 * 1024 * 1024; // 8MB -> 64MB
        inline constexpr size_t kTcpCoalesceReserve   = 4 * 1024 * 1024;  // 4MB pre-alloc for batch coalesce
    }

    namespace Logging {
        inline constexpr auto kFlushInterval = std::chrono::milliseconds(200);
    }

} // namespace Constants
