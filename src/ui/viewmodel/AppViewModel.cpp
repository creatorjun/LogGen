// src/ui/viewmodel/AppViewModel.cpp
#include "AppViewModel.h"
#include "persistence/DefaultProfileFactory.h"
#include "logging/Logger.h"
#include <chrono>

AppViewModel::AppViewModel(std::unique_ptr<IGeneratorEngine> engine,
                           std::unique_ptr<ISoarMockEngine>  soarEngine,
                           LogBuffer&                        logBuffer,
                           ApiRequestBuffer&                 apiBuffer)
    : m_engine(std::move(engine))
    , m_soarEngine(std::move(soarEngine))
    , m_logBuffer(logBuffer)
    , m_apiBuffer(apiBuffer)
{}

AppViewModel::~AppViewModel() {
    if (m_soarEngine && m_soarEngine->isRunning()) m_soarEngine->stop();
    if (m_engine     && m_engine->isRunning())     m_engine->stop();
    if (m_reloadFuture.valid()) m_reloadFuture.wait();
    LOG_INFO("ViewModel", "AppViewModel destroyed");
}

void AppViewModel::requestStart() {
    if (!m_isReloading) m_isRunning = true;
}

void AppViewModel::requestStop() {
    m_isRunning = false;
}

void AppViewModel::requestReload() {
    if (m_isReloading) return;

    if (m_isRunning) {
        m_engine->stop();
        m_isRunning  = false;
        m_wasRunning = false;
        LOG_INFO("ViewModel", "Engine stopped before template reload");
    }

    m_isReloading = true;
    LOG_INFO("ViewModel", "Template reload triggered (background thread)");

    m_reloadFuture = std::async(std::launch::async, []() {
        return DefaultProfileFactory::buildFromDirectory("templates");
    });
}

void AppViewModel::markDirty() {
    m_isDirty = true;
}

void AppViewModel::setDateOffsetDays(int days) {
    m_dateOffsetDays = days;
    if (m_engine) m_engine->setDateOffsetDays(days);
}

void AppViewModel::tick(std::vector<DeviceProfile>& profiles,
                        const std::function<void()>& onSave) {
    tickReload(profiles, onSave);
    tickEngineState(profiles, onSave);
}

void AppViewModel::tickEngineState(std::vector<DeviceProfile>& profiles,
                                   const std::function<void()>& onSave) {
    if (m_isRunning && !m_wasRunning) {
        LOG_INFO("ViewModel", "Engine start");
        m_engine->setLogCallback([this](const LogEntry& entry) {
            m_logBuffer.push(entry);
        });
        m_engine->setDateOffsetDays(m_dateOffsetDays);
        m_engine->start(profiles);
        onSave();
        m_wasRunning = true;
        m_isDirty    = false;
    } else if (!m_isRunning && m_wasRunning) {
        LOG_INFO("ViewModel", "Engine stop");
        m_engine->stop();
        m_wasRunning = false;
        m_isDirty    = false;
    }

    if (m_isRunning && m_isDirty) {
        LOG_DEBUG("ViewModel", "Flushing dirty profiles to engine");
        for (const auto& p : profiles)
            m_engine->updateProfile(p);
        m_isDirty = false;
    }
}

void AppViewModel::tickReload(std::vector<DeviceProfile>& profiles,
                              const std::function<void()>& onSave) {
    if (!m_isReloading || !m_reloadFuture.valid()) return;

    if (m_reloadFuture.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        return;

    profiles      = m_reloadFuture.get();
    m_isReloading = false;
    onSave();

    LOG_INFO("ViewModel", "Template reload complete. profiles="
             + std::to_string(profiles.size()));
}
