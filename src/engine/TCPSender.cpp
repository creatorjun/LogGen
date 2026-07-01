// src/engine/TCPSender.cpp
#include "TCPSender.h"
#include "logging/Logger.h"
#include <cstring>

TCPSender::TCPSender()  = default;
TCPSender::~TCPSender() { closeConnection(); }

bool TCPSender::openConnection(const std::string& targetIp, uint16_t port) {
    closeConnection();

    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socket == kInvalidTcpSocket) {
        LOG_ERROR("NETWORK", "TCP socket() failed: " + targetIp + ":" + std::to_string(port));
        return false;
    }

#ifdef _WIN32
    DWORD timeout = kConnectTimeoutMs;
    setsockopt(m_socket, SOL_SOCKET, SO_SNDTIMEO,
               reinterpret_cast<const char*>(&timeout), sizeof(timeout));
#else
    struct timeval tv;
    tv.tv_sec  = kConnectTimeoutMs / 1000;
    tv.tv_usec = (kConnectTimeoutMs % 1000) * 1000;
    setsockopt(m_socket, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
#endif

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port   = htons(port);
    if (inet_pton(AF_INET, targetIp.c_str(), &addr.sin_addr) <= 0) {
        LOG_ERROR("NETWORK", "TCP inet_pton failed for IP: " + targetIp);
        closeConnection();
        return false;
    }

    if (connect(m_socket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) != 0) {
        LOG_ERROR("NETWORK", "TCP connect failed: " + targetIp + ":" + std::to_string(port));
        closeConnection();
        return false;
    }

    m_targetIp = targetIp;
    m_port     = port;
    LOG_INFO("NETWORK", "TCP connection opened: " + targetIp + ":" + std::to_string(port));
    return true;
}

bool TCPSender::reconnect() {
    const std::string ip   = m_targetIp;
    const uint16_t    port = m_port;
    if (ip.empty() || port == 0) return false;
    LOG_WARN("NETWORK", "TCP reconnecting: " + ip + ":" + std::to_string(port));
    return openConnection(ip, port);
}

bool TCPSender::sendFrame(const std::string& frame) {
    if (m_socket == kInvalidTcpSocket) return false;

    size_t totalSent = 0;
    size_t bytesLeft = frame.size();
    const char* data = frame.c_str();

    while (totalSent < frame.size()) {
#ifdef _WIN32
        int n = send(m_socket, data + totalSent, static_cast<int>(bytesLeft), 0);
        if (n == SOCKET_ERROR) {
            return false;
        }
#else
        ssize_t n = send(m_socket, data + totalSent, bytesLeft, MSG_NOSIGNAL);
        if (n < 0) {
            if (errno == EINTR) continue;
            return false;
        }
#endif
        if (n == 0) {
            return false;
        }

        totalSent += static_cast<size_t>(n);
        bytesLeft -= static_cast<size_t>(n);
    }

    return true;
}

bool TCPSender::sendLog(const std::string& rawLog) {
    if (m_socket == kInvalidTcpSocket) return false;

    const std::string frame = rawLog + "\n";

    if (sendFrame(frame)) return true;

    LOG_WARN("NETWORK", "TCP send failed, attempting reconnect: " + m_targetIp + ":" + std::to_string(m_port));
    if (!reconnect()) return false;

    return sendFrame(frame);
}

bool TCPSender::sendBatch(const std::vector<std::string>& logs) {
    for (const auto& log : logs) {
        if (!sendLog(log)) return false;
    }
    return true;
}

void TCPSender::closeConnection() {
    if (m_socket == kInvalidTcpSocket) return;
#ifdef _WIN32
    closesocket(m_socket);
#else
    close(m_socket);
#endif
    if (!m_targetIp.empty())
        LOG_INFO("NETWORK", "TCP connection closed: " + m_targetIp + ":" + std::to_string(m_port));
    m_socket   = kInvalidTcpSocket;
    m_targetIp = {};
    m_port     = 0;
}
