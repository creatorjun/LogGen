// src/persistence/SessionManager.h
#pragma once

#include "core/DeviceProfile.h"
#include <vector>
#include <string>

class SessionManager {
public:
    explicit SessionManager(const std::string& sessionFile);
    ~SessionManager() = default;

    [[nodiscard]] bool saveSession(const std::vector<DeviceProfile>& profiles);
    [[nodiscard]] bool loadSession(std::vector<DeviceProfile>& outProfiles);

private:
    std::string m_sessionFile;
};
