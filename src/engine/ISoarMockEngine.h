// src/engine/ISoarMockEngine.h
#pragma once

#include <cstdint>
#include <string>
#include "core/Callbacks.h"

enum class SoarEngineState {
    Idle,
    Running,
    Error
};

class ISoarMockEngine {
public:
    virtual ~ISoarMockEngine() = default;

    virtual void configure(const std::string& ip, uint16_t port, bool useTLS) = 0;
    virtual void setRequestCallback(RequestCallback cb)                       = 0;
    virtual void start()                                                      = 0;
    virtual void stop()                                                       = 0;
    [[nodiscard]] virtual SoarEngineState getState()  const                   = 0;
    [[nodiscard]] virtual bool            isRunning() const                   = 0;
};
