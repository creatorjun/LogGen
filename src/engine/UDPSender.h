// src/engine/UDPSender.h
#pragma once

#include "ISender.h"
#include <string>
#include <vector>
#include "core/Constants.h"

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
  using UdpSocket = SOCKET;
  static constexpr UdpSocket kInvalidUdpSocket = INVALID_SOCKET;
#else
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  #include <sys/uio.h>
  #include <linux/errqueue.h>
  using UdpSocket = int;
  static constexpr UdpSocket kInvalidUdpSocket = -1;
#endif

class UDPSender : public ISender {
public:
    static constexpr size_t kBatchCapacity = Constants::Network::kUdpBatchCapacity;

    UDPSender();
    ~UDPSender() override;

    [[nodiscard]] bool openConnection(const std::string& targetIp, uint16_t port) override;
    [[nodiscard]] bool sendLog(const std::string& rawLog)                          override;
    [[nodiscard]] bool sendBatch(const std::vector<std::string>& logs)             override;
    void               closeConnection()                                           override;

    [[nodiscard]] size_t sendBatchGetCount(const std::vector<std::string>& logs);

private:
    UdpSocket        m_socket = kInvalidUdpSocket;
    sockaddr_in      m_addr   = {};
    std::string      m_targetIp;
    uint16_t         m_port   = 0;

#ifdef _WIN32
    WSABUF   m_wsaBufs[kBatchCapacity];
#else
    iovec    m_iovecs[kBatchCapacity];
    mmsghdr  m_mmsgHdrs[kBatchCapacity];
#endif
};
