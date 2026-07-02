// src/engine/RateController.cpp
#include "RateController.h"
#include <cmath>
#include <algorithm>

RateController::RateController(double initialRate)
    : m_rate(initialRate > 0.0 ? initialRate : 1.0)
    , m_bucketCap(initialRate * 2.0)
{}

void RateController::update(
        bool   burstEnable,
        float  burstIntervalSec,
        float  burstDurationSec,
        double normalRate,
        double burstRate) noexcept {

    if (!m_prevBurstEnable && burstEnable) {
        m_burstStartTime = std::chrono::steady_clock::now();
        m_inBurstMode    = false;
    }
    m_prevBurstEnable = burstEnable;

    if (burstEnable) {
        const auto  now     = std::chrono::steady_clock::now();
        const float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
            now - m_burstStartTime).count() / 1000.0f;

        if (!m_inBurstMode && elapsed >= burstIntervalSec) {
            m_inBurstMode    = true;
            m_burstStartTime = now;
        } else if (m_inBurstMode && elapsed >= burstDurationSec) {
            m_inBurstMode    = false;
            m_burstStartTime = now;
        }
    } else {
        m_inBurstMode = false;
    }

    const double chosen = m_inBurstMode
        ? (burstRate  <= 0.0 ? 1.0 : burstRate)
        : (normalRate <= 0.0 ? 1.0 : normalRate);
    m_rate = chosen;
}

size_t RateController::tick(size_t maxBatch) noexcept {
    const auto   now   = std::chrono::steady_clock::now();
    const double dtSec = std::chrono::duration_cast<std::chrono::duration<double>>(
        now - m_lastTickTime).count();
    m_lastTickTime = now;

    m_bucket   += m_rate * dtSec;
    m_bucketCap = static_cast<double>(maxBatch) * 2.0;
    if (m_bucket > m_bucketCap)
        m_bucket = m_bucketCap;

    if (m_bucket < 1.0)
        return 0;

    const size_t tokens = static_cast<size_t>(m_bucket);
    return tokens < maxBatch ? tokens : maxBatch;
}

void RateController::consume(size_t sent) noexcept {
    m_bucket -= static_cast<double>(sent);
    if (m_bucket < 0.0)
        m_bucket = 0.0;
}
