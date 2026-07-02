// src/engine/TCPSender.cpp
#include "TCPSender.h"
#include "logging/Logger.h"
#include "core/Constants.h"
#include <cstring>

TCPSender::TCPSender() {
    m_coalesceBuf.reserve(Constants::Network::kTcpCoalesceReserve);
}

TCPSender::~TCPSender() { closeConnection(); }

bool TCPSender::openConnection(const std::string& targetIp, uint16_t port) {
    closeConnection();

    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socket == kInvalidTcpSocket) {
        LOG_ERROR("NETWORK", "TCP socket() failed: " + targetIp + ":" + std::to_string(port));
        return false;
    }

    // TCP_NODELAY: disable Nagle — we coalesce ourselves
#ifdef _WIN32
    BOOL nodelay = TRUE;
    setsockopt(m_socket, IPPROTO_TCP, TCP_NODELAY,
               reinterpret_cast<const char*>(&nodelay), sizeof(nodelay));

    // send-side SO_SNDBUF
    int sndbuf = Constants::Network::kUdpSendBufferBytes; // reuse same 64MB constant
    setsockopt(m_socket, SOL_SOCKET, SO_SNDBUF,
               reinterpret_cast<const char*>(&sndbuf), sizeof(sndbuf));

    DWORD timeout = kConnectTimeoutMs;
    setsockopt(m_socket, SOL_SOCKET, SO_SNDTIMEO,
               reinterpret_cast<const char*>(&timeout), sizeof(timeout));
#else
    int nodelay = 1;
    setsockopt(m_socket, IPPROTO_TCP, TCP_NODELAY, &nodelay, sizeof(nodelay));

    int sndbuf = Constants::Network::kUdpSendBufferBytes;
    setsockopt(m_socket, SOL_SOCKET, SO_SNDBUF, &sndbuf, sizeof(sndbuf));

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

bool TCPSender::sendRaw(const char* data, size_t len) {
    size_t sent = 0;
    while (sent < len) {
#ifdef _WIN32
        int n = send(m_socket, data + sent, static_cast<int>(len - sent), 0);
        if (n == SOCKET_ERROR) return false;
#else
        ssize_t n = send(m_socket, data + sent, len - sent, MSG_NOSIGNAL);
        if (n < 0) {
            if (errno == EINTR) continue;
            return false;
        }
#endif
        if (n == 0) return false;
        sent += static_cast<size_t>(n);
    }
    return true;
}

bool TCPSender::sendLog(const std::string& rawLog) {
    if (m_socket == kInvalidTcpSocket) return false;

    // fast path: single send with inline newline via scatter-gather
    m_coalesceBuf.assign(rawLog);
    m_coalesceBuf += '\n';

    if (sendRaw(m_coalesceBuf.data(), m_coalesceBuf.size())) return true;

    LOG_WARN("NETWORK", "TCP send failed, attempting reconnect: " +
             m_targetIp + ":" + std::to_string(m_port));
    if (!reconnect()) return false;
    return sendRaw(m_coalesceBuf.data(), m_coalesceBuf.size());
}

bool TCPSender::sendBatch(const std::vector<std::string>& logs) {
    if (m_socket == kInvalidTcpSocket || logs.empty()) return false;

    // Coalesce all logs into one buffer: "log1\nlog2\n..."
    // This turns N syscalls into 1, dramatically reducing overhead.
    m_coalesceBuf.clear();
    for (const auto& log : logs) {
        m_coalesceBuf += log;
        m_coalesceBuf += '\n';
    }

    if (sendRaw(m_coalesceBuf.data(), m_coalesceBuf.size())) return true;

    LOG_WARN("NETWORK", "TCP batch send failed, attempting reconnect: " +
             m_targetIp + ":" + std::to_string(m_port));
    if (!reconnect()) return false;
    return sendRaw(m_coalesceBuf.data(), m_coalesceBuf.size());
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
