// src/infrastructure/AppConfig.h
#pragma once

#include <cstddef>

namespace infrastructure {

struct AppConfig {
    size_t queueCapacity;
};

[[nodiscard]] AppConfig parseAppConfig(int argc, char* argv[]);

} // namespace infrastructure
