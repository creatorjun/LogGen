// src/infrastructure/NetworkInitializer.h
#pragma once

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>

namespace infrastructure {

class NetworkInitializer {
public:
    NetworkInitializer() {
        WSADATA wsaData;
        m_initialized = (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0);
    }
    ~NetworkInitializer() {
        if (m_initialized) WSACleanup();
    }

    NetworkInitializer(const NetworkInitializer&)            = delete;
    NetworkInitializer& operator=(const NetworkInitializer&) = delete;

    [[nodiscard]] bool isInitialized() const { return m_initialized; }

private:
    bool m_initialized = false;
};

} // namespace infrastructure

#endif
