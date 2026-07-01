// src/main.cpp
#include "ui/AppWindow.h"
#include "ui/UIConstants.h"
#include "persistence/SessionManager.h"
#include "engine/GeneratorEngine.h"
#include "engine/ApiRouter.h"
#include "engine/SoarMockEngine.h"
#include "logging/Logger.h"
#include "core/Constants.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <cstddef>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winsock2.h>

class WSAInitializer {
public:
    WSAInitializer() {
        WSADATA wsaData;
        m_initialized = (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0);
    }
    ~WSAInitializer() {
        if (m_initialized) WSACleanup();
    }
    bool isInitialized() const { return m_initialized; }
private:
    bool m_initialized = false;
};
#endif

static size_t parseQueueSize(int argc, char* argv[],
    size_t defaultVal = Constants::Engine::kDefaultQueueCapacity)
{
    for (int i = 1; i < argc - 1; ++i) {
        if (std::string(argv[i]) == "--queue-size") {
            const long val = std::strtol(argv[i + 1], nullptr, 10);
            if (val > 0) return static_cast<size_t>(val);
        }
    }
    return defaultVal;
}

int main(int argc, char* argv[]) {
#ifdef _WIN32
    WSAInitializer wsaInit;
    if (!wsaInit.isInitialized()) {
        std::cerr << "WSAStartup failed\n";
        return -1;
    }
#endif

    const size_t queueCapacity = parseQueueSize(argc, argv);

    logging::Logger::instance().initialize("logs", logging::LogLevel::Info);
    LOG_INFO("SYSTEM", "Initializing SIM Log Generator Phase 1 System");
    LOG_INFO("SYSTEM", "Dispatch queue capacity: " + std::to_string(queueCapacity));

    std::string configPath = "config/last_session.json";
    SessionManager sessionMgr(configPath);
    std::vector<DeviceProfile> profiles;

    if (sessionMgr.loadSession(profiles) && !profiles.empty()) {
        LOG_INFO("SESSION", "Restored last session profiles. Count=" + std::to_string(profiles.size()));
    } else {
        profiles.clear();
        LOG_WARN("SESSION", "No previous session found. Starting with empty profiles.");
    }

    auto apiRouter  = std::make_unique<ApiRouter>();
    auto genEngine  = std::make_unique<GeneratorEngine>(
        Constants::Engine::kDefaultThreadPoolSize, queueCapacity);
    auto soarEngine = std::make_unique<SoarMockEngine>(*apiRouter);

    int exitCode = 0;
    {
        const std::string windowTitle =
            std::string(UIText::APP_TITLE) + " - " + UIText::APP_DESCRIPTION;

        AppWindow app(
            UIConstants::kWindowWidth,
            UIConstants::kWindowHeight,
            windowTitle,
            std::move(genEngine),
            std::move(soarEngine));

        if (!app.init()) {
            LOG_ERROR("UI", "Graphic context initialization aborted");
            logging::Logger::instance().shutdown();
            return -1;
        }

        LOG_INFO("UI", "Application window initialized successfully");

        app.mainLoop(profiles, [&]() {
            if (!sessionMgr.saveSession(profiles))
                LOG_WARN("SESSION", "Autosave failed");
            else
                LOG_INFO("SESSION", "Session autosaved");
        });

        LOG_INFO("SYSTEM", "Window closing detected. Autosaving final state");
        if (!sessionMgr.saveSession(profiles))
            LOG_WARN("SESSION", "Final autosave failed");
    }

    LOG_INFO("SYSTEM", "Application terminated cleanly");
    logging::Logger::instance().shutdown();
    return exitCode;
}
