// src/engine/IGeneratorEngine.h
#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include "core/DeviceProfile.h"
#include "core/Callbacks.h"

class IGeneratorEngine {
public:
    virtual ~IGeneratorEngine() = default;

    virtual void         setLogCallback(LogCallback cb)                                    = 0;
    virtual void         start(const std::vector<DeviceProfile>& profiles)                 = 0;
    virtual void         stop()                                                            = 0;
    virtual void         updateProfile(const DeviceProfile& profile)                       = 0;
    virtual void         setDateOffsetDays(int days)                                       = 0;
    virtual bool         loadTIPool(const std::string& csvPath)                            = 0;
    [[nodiscard]] virtual uint64_t getTotalSent() const                                    = 0;
    [[nodiscard]] virtual uint64_t getSentByDevice(const std::string& deviceId) const      = 0;
    [[nodiscard]] virtual float    getCurrentRateByDevice(const std::string& deviceId) const = 0;
    [[nodiscard]] virtual bool     isRunning() const                                       = 0;
};
