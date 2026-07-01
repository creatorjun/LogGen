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
    u_long nonBlocking = 0;
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

    m_targetIp = targetIp;
    m_port     = port;
    LOG_INFO("NETWORK", "UDP connection opened: " + targetIp + ":" + std::to_string(port));
    return true;
}

bool UDPSender::sendLog(const std::string& rawLog) {
    if (m_socket == kInvalidUdpSocket) return false;

#ifdef _WIN32
    int n = sendto(m_socket, rawLog.c_str(), static_cast<int>(rawLog.size()), 0,
                   reinterpret_cast<const sockaddr*>(&m_addr), sizeof(m_addr));
    if (n == SOCKET_ERROR) {
        LOG_WARN("NETWORK", "UDP sendto failed: " + m_targetIp + ":" + std::to_string(m_port));
        return false;
    }
#else
    ssize_t n = sendto(m_socket, rawLog.c_str(), rawLog.size(), MSG_NOSIGNAL,
                       reinterpret_cast<const sockaddr*>(&m_addr), sizeof(m_addr));
    if (n < 0) {
        LOG_WARN("NETWORK", "UDP sendto failed: " + m_targetIp + ":" + std::to_string(m_port));
        return false;
    }
#endif
    return true;
}

size_t UDPSender::sendBatchGetCount(const std::vector<std::string>& logs) {
    if (m_socket == kInvalidUdpSocket || logs.empty()) return 0;

    size_t successCount = 0;

#ifdef _WIN32
    size_t offset = 0;
    while (offset < logs.size()) {
        const size_t chunk = (std::min)(logs.size() - offset, Constants::Network::kUdpBatchCapacity);
        for (size_t i = 0; i < chunk; ++i) {
            m_wsaBufs[i].buf = const_cast<char*>(logs[offset + i].c_str());
            m_wsaBufs[i].len = static_cast<ULONG>(logs[offset + i].size());
        }
        for (size_t i = 0; i < chunk; ++i) {
            DWORD bytesSent = 0;
            int ret = WSASendTo(
                m_socket,
                &m_wsaBufs[i], 1,
                &bytesSent,
                0,
                reinterpret_cast<const sockaddr*>(&m_addr),
                sizeof(m_addr),
                nullptr, nullptr);
            if (ret == 0) {
                ++successCount;
            } else {
                LOG_WARN("NETWORK", "UDP WSASendTo failed: " + m_targetIp + ":" + std::to_string(m_port));
            }
        }
        offset += chunk;
    }
#else
    size_t offset = 0;
    while (offset < logs.size()) {
        const size_t chunk = (std::min)(logs.size() - offset, Constants::Network::kUdpBatchCapacity);
        for (size_t i = 0; i < chunk; ++i) {
            m_iovecs[i].iov_base = const_cast<char*>(logs[offset + i].c_str());
            m_iovecs[i].iov_len  = logs[offset + i].size();

            memset(&m_mmsgHdrs[i], 0, sizeof(m_mmsgHdrs[i]));
            m_mmsgHdrs[i].msg_hdr.msg_name    = &m_addr;
            m_mmsgHdrs[i].msg_hdr.msg_namelen = sizeof(m_addr);
            m_mmsgHdrs[i].msg_hdr.msg_iov     = &m_iovecs[i];
            m_mmsgHdrs[i].msg_hdr.msg_iovlen  = 1;
        }
        int sent = sendmmsg(m_socket, m_mmsgHdrs, static_cast<unsigned int>(chunk), 0);
        if (sent > 0) {
            successCount += static_cast<size_t>(sent);
        } else if (sent < 0) {
            LOG_WARN("NETWORK", "UDP sendmmsg failed: " + m_targetIp + ":" + std::to_string(m_port));
        }
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