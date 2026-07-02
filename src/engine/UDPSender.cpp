// src/engine/UDPSender.cpp
#ifdef _WIN32
#  ifndef NOMINMAX
#    define NOMINMAX
#  endif
#endif

#include "UDPSender.h"
#include "logging/Logger.h"
#include "core/Constants.h"
#include <algorithm>
#include <cstring>

#ifdef _WIN32
UDPSender::UDPSender() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
}
UDPSender::~UDPSender() {
    closeConnection();
    WSACleanup();
}
#else
UDPSender::UDPSender()  = default;
UDPSender::~UDPSender() { closeConnection(); }
#endif

bool UDPSender::openConnection(const std::string& targetIp, uint16_t port) {
    closeConnection();

    m_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (m_socket == kInvalidUdpSocket) {
        LOG_ERROR("NETWORK", "UDP socket() failed: " + targetIp + ":" + std::to_string(port));
        return false;
    }

    int sndbuf = Constants::Network::kUdpSendBufferBytes;
#ifdef _WIN32
    setsockopt(m_socket, SOL_SOCKET, SO_SNDBUF,
               reinterpret_cast<const char*>(&sndbuf), sizeof(sndbuf));
    // Non-blocking for Windows hot path
    u_long nonBlocking = 1;
    ioctlsocket(m_socket, FIONBIO, &nonBlocking);
#else
    setsockopt(m_socket, SOL_SOCKET, SO_SNDBUF, &sndbuf, sizeof(sndbuf));
#endif

    m_addr = {};
    m_addr.sin_family = AF_INET;
    m_addr.sin_port   = htons(port);

    if (inet_pton(AF_INET, targetIp.c_str(), &m_addr.sin_addr) <= 0) {
        LOG_ERROR("NETWORK", "UDP inet_pton failed for IP: " + targetIp);
        closeConnection();
        return false;
    }

    // connect() so subsequent sendto -> send, avoids repeated addr copy in kernel
    if (connect(m_socket,
                reinterpret_cast<const sockaddr*>(&m_addr),
                sizeof(m_addr)) != 0) {
        // non-fatal for UDP; log and continue
        LOG_WARN("NETWORK", "UDP connect() failed (non-fatal): " + targetIp + ":" + std::to_string(port));
    }

    m_targetIp = targetIp;
    m_port     = port;
    LOG_INFO("NETWORK", "UDP connection opened: " + targetIp + ":" + std::to_string(port));
    return true;
}

bool UDPSender::sendLog(const std::string& rawLog) {
    if (m_socket == kInvalidUdpSocket) return false;
#ifdef _WIN32
    int n = send(m_socket, rawLog.c_str(), static_cast<int>(rawLog.size()), 0);
    return n != SOCKET_ERROR;
#else
    ssize_t n = send(m_socket, rawLog.c_str(), rawLog.size(), MSG_NOSIGNAL);
    return n >= 0;
#endif
}

size_t UDPSender::sendBatchGetCount(const std::vector<std::string>& logs) {
    if (m_socket == kInvalidUdpSocket || logs.empty()) return 0;

    size_t successCount = 0;

#ifdef _WIN32
    // Windows: build WSABUF array and call WSASend (connected socket -> no addr needed)
    size_t offset = 0;
    while (offset < logs.size()) {
        const size_t chunk = std::min(logs.size() - offset,
                                      Constants::Network::kUdpBatchCapacity);
        for (size_t i = 0; i < chunk; ++i) {
            m_wsaBufs[i].buf = const_cast<char*>(logs[offset + i].c_str());
            m_wsaBufs[i].len = static_cast<ULONG>(logs[offset + i].size());
        }
        // Send each packet individually but with pre-built WSABUF (avoids kernel addr copy)
        for (size_t i = 0; i < chunk; ++i) {
            DWORD bytesSent = 0;
            int ret = WSASend(
                m_socket,
                &m_wsaBufs[i], 1,
                &bytesSent,
                0,
                nullptr, nullptr);
            if (ret == 0 || WSAGetLastError() == WSAEWOULDBLOCK) {
                ++successCount;
            }
        }
        offset += chunk;
    }
#else
    // Linux: sendmmsg sends multiple datagrams in one syscall
    size_t offset = 0;
    while (offset < logs.size()) {
        const size_t chunk = std::min(logs.size() - offset,
                                      Constants::Network::kUdpBatchCapacity);
        for (size_t i = 0; i < chunk; ++i) {
            m_iovecs[i].iov_base = const_cast<char*>(logs[offset + i].c_str());
            m_iovecs[i].iov_len  = logs[offset + i].size();

            memset(&m_mmsgHdrs[i], 0, sizeof(m_mmsgHdrs[i]));
            m_mmsgHdrs[i].msg_hdr.msg_iov    = &m_iovecs[i];
            m_mmsgHdrs[i].msg_hdr.msg_iovlen = 1;
            // msg_name not needed: socket is connected
        }
        int sent = sendmmsg(m_socket, m_mmsgHdrs,
                            static_cast<unsigned int>(chunk), MSG_DONTWAIT);
        if (sent > 0)
            successCount += static_cast<size_t>(sent);
        offset += chunk;
    }
#endif
    return successCount;
}

bool UDPSender::sendBatch(const std::vector<std::string>& logs) {
    return sendBatchGetCount(logs) == logs.size();
}

void UDPSender::closeConnection() {
    if (m_socket == kInvalidUdpSocket) return;
#ifdef _WIN32
    closesocket(m_socket);
#else
    close(m_socket);
#endif
    if (!m_targetIp.empty())
        LOG_INFO("NETWORK", "UDP connection closed: " + m_targetIp + ":" + std::to_string(m_port));
    m_socket   = kInvalidUdpSocket;
    m_targetIp = {};
    m_port     = 0;
}
