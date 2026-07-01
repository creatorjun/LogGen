// src/engine/ISender.h
#pragma once

#include <string>
#include <vector>
#include <cstdint>

class ISender {
public:
    virtual ~ISender() = default;

    [[nodiscard]] virtual bool openConnection(const std::string& targetIp, uint16_t port) = 0;
    [[nodiscard]] virtual bool sendLog(const std::string& rawLog)                         = 0;
    [[nodiscard]] virtual bool sendBatch(const std::vector<std::string>& logs)            = 0;
    virtual void               closeConnection()                                          = 0;
};
