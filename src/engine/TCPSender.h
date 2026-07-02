// src/engine/TCPSender.h
#pragma once

#ifdef _WIN32
#  ifndef NOMINMAX
#    define NOMINMAX
#  endif
#  include <winsock2.h>
#  include <ws2tcpip.h>
#  pragma comment(lib, "ws2_32.lib")
   using TcpSocket = SOCKET;
   static constexpr TcpSocket kInvalidTcpSocket = INVALID_SOCKET;
#else
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <netinet/tcp.h>
#  include <arpa/inet.h>
#  include <unistd.h>
   using TcpSocket = int;
   static constexpr TcpSocket kInvalidTcpSocket = -1;
#endif

#include <string>
#include <vector>
#include "ISender.h"

class TCPSender : public ISender {
public:
    TCPSender();
    ~TCPSender() override;

    bool openConnection(const std::string& targetIp, uint16_t port) override;
    bool sendLog(const std::string& rawLog)                          override;
    bool sendBatch(const std::vector<std::string>& logs)             override;
    void closeConnection()                                           override;

private:
    static constexpr int kConnectTimeoutMs = 3000;

    bool reconnect();
    bool sendRaw(const char* data, size_t len);

    TcpSocket   m_socket    = kInvalidTcpSocket;
    std::string m_targetIp;
    uint16_t    m_port      = 0;

    // batch coalesce buffer — reused across sendBatch calls
    std::string m_coalesceBuf;
};
