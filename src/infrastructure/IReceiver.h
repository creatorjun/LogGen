// src/infrastructure/IReceiver.h
#pragma once

#include <cstdint>
#include "core/Callbacks.h"

class IReceiver {
public:
    virtual ~IReceiver() = default;
    [[nodiscard]] virtual bool start(uint16_t port, RequestCallback cb,
                                     int threadCount = 4)             = 0;
    virtual void               stop()                                 = 0;
    [[nodiscard]] virtual bool isRunning() const                      = 0;
};
