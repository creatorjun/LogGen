// src/engine/ConnectionManager.cpp
#include "ConnectionManager.h"
#include "engine/TCPSender.h"
#include "core/Constants.h"
#include "logging/Logger.h"
#include <format>

std::expected<void, std::string>
ConnectionManager::connect(const DeviceProfile& p) {
    m_sender = p.collector.useTCP
        ? static_cast<std::unique_ptr<ISender>>(std::make_unique<TCPSender>())
        : static_cast<std::unique_ptr<ISender>>(std::make_unique<UDPSender>());

    m_udpSender = p.collector.useTCP
        ? nullptr
        : static_cast<UDPSender*>(m_sender.get());

    if (!m_sender->openConnection(p.collector.ip, p.collector.port))
        return std::unexpected(std::format("Connection failed: {}:{}",
            p.collector.ip, p.collector.port));
    return {};
}

bool ConnectionManager::reconnectIfNeeded(const DeviceProfile& p) {
    if (m_consecutiveFails < Constants::Engine::kMaxConsecutiveFails)
        return false;

    const auto elapsed = std::chrono::steady_clock::now() - m_lastReconnectAttempt;
    if (elapsed < Constants::Engine::kReconnectInterval)
        return false;

    m_lastReconnectAttempt = std::chrono::steady_clock::now();
    LOG_WARN("NETWORK", std::format(
        "Max consecutive failures reached, forcing reconnect: device={}",
        p.deviceName));

    if (m_sender->openConnection(p.collector.ip, p.collector.port)) {
        m_consecutiveFails = 0;
        LOG_INFO("NETWORK", std::format(
            "Forced reconnect succeeded: device={}", p.deviceName));
        return true;
    }

    LOG_ERROR("NETWORK", std::format(
        "Forced reconnect failed: device={}", p.deviceName));
    return false;
}
