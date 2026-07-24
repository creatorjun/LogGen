// src/engine/RateController.h
#pragma once
#include <chrono>
#include <cstddef>

class RateController {
public:
    explicit RateController(double initialRate = 1.0);

    void update(bool   burstEnable,
                float  burstIntervalSec,
                float  burstDurationSec,
                double normalRate,
                double burstRate) noexcept;

    [[nodiscard]] double effectiveRate() const noexcept { return m_rate; }
    [[nodiscard]] bool   inBurstMode()   const noexcept { return m_inBurstMode; }

    [[nodiscard]] size_t tick(size_t maxBatch) noexcept;
    void consume(size_t sent) noexcept;

    void resetLastTickTime() noexcept {
        m_lastTickTime = std::chrono::steady_clock::now();
        m_bucket       = 0.0;
    }

private:
    double  m_rate{1.0};
    double  m_bucket{};
    double  m_bucketCap{};

    bool    m_inBurstMode{};
    bool    m_prevBurstEnable{};

    std::chrono::steady_clock::time_point m_lastTickTime{
        std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point m_burstStartTime{
        std::chrono::steady_clock::now()};
};
