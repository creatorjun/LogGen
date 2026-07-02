// src/engine/ConnectionManager.h
#pragma once
#include <memory>
#include <string>
#include <expected>
#include <chrono>
#include "engine/ISender.h"
#include "engine/UDPSender.h"
#include "core/DeviceProfile.h"

class ConnectionManager {
public:
    [[nodiscard]] std::expected<void, std::string>
        connect(const DeviceProfile& p);

    [[nodiscard]] bool reconnectIfNeeded(const DeviceProfile& p);

    [[nodiscard]] ISender*   sender()    noexcept { return m_sender.get(); }
    [[nodiscard]] UDPSender* udpSender() noexcept { return m_udpSender; }

    [[nodiscard]] int  consecutiveFails() const noexcept { return m_consecutiveFails; }
    void resetFails() noexcept { m_consecutiveFails = 0; }
    void incFails()   noexcept { ++m_consecutiveFails; }
    void setFails(int v) noexcept { m_consecutiveFails = v; }

private:
    std::unique_ptr<ISender> m_sender;
    UDPSender*               m_udpSender{};
    int                      m_consecutiveFails{};
    std::chrono::steady_clock::time_point m_lastReconnectAttempt{};
};
