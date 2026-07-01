// src/engine/TCPSender.h
#pragma once

#include "engine/ISender.h"
#include <string>
#include <vector>
#include <cstdint>
#include "core/Constants.h"

#ifdef _WIN32
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #include <winsock2.h>
    #include <ws2tcpip.h>
    using tcp_socket_t = SOCKET;
    static constexpr tcp_socket_t kInvalidTcpSocket = INVALID_SOCKET;
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <fcntl.h>
    using tcp_socket_t = int;
    static constexpr tcp_socket_t kInvalidTcpSocket = -1;
#endif

class TCPSender : public ISender {
public:
    TCPSender();
    ~TCPSender() override;

    [[nodiscard]] bool openConnection(const std::string& targetIp, uint16_t port) override;
    [[nodiscard]] bool sendLog(const std::string& rawLog)                          override;
    [[nodiscard]] bool sendBatch(const std::vector<std::string>& logs)             override;
    void               closeConnection()                                           override;

private:
    [[nodiscard]] bool reconnect();
    [[nodiscard]] bool sendFrame(const std::string& frame);

    static constexpr int kConnectTimeoutMs = Constants::Network::kTcpConnectTimeoutMs;
    static constexpr int kSendTimeoutMs    = Constants::Network::kTcpSendTimeoutMs;

    tcp_socket_t m_socket    = kInvalidTcpSocket;
    std::string  m_targetIp;
    uint16_t     m_port      = 0;
};
