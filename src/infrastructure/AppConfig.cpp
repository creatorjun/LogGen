// src/infrastructure/AppConfig.cpp
#include "infrastructure/AppConfig.h"
#include "core/Constants.h"
#include <string>
#include <cstdlib>

namespace infrastructure {

AppConfig parseAppConfig(int argc, char* argv[]) {
    AppConfig cfg;
    cfg.queueCapacity = Constants::Engine::kDefaultQueueCapacity;

    for (int i = 1; i < argc - 1; ++i) {
        if (std::string(argv[i]) == "--queue-size") {
            const long val = std::strtol(argv[i + 1], nullptr, 10);
            if (val > 0)
                cfg.queueCapacity = static_cast<size_t>(val);
        }
    }
    return cfg;
}

} // namespace infrastructure
