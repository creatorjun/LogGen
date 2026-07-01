// src/persistence/DefaultProfileFactory.h
#pragma once

#include "core/DeviceProfile.h"
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class DefaultProfileFactory {
public:
    [[nodiscard]] static std::vector<DeviceProfile> buildFromDirectory(
        const std::string& dirPath = "templates");
    [[nodiscard]] static std::vector<DeviceProfile> build();
};
