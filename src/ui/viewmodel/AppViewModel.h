// src/ui/viewmodel/AppViewModel.h
#pragma once

#include <vector>
#include <future>
#include <functional>
#include <memory>
#include "engine/IGeneratorEngine.h"
#include "engine/ISoarMockEngine.h"
#include "core/DeviceProfile.h"
#include "core/channel/LogBuffer.h"
#include "core/channel/ApiRequestBuffer.h"

class AppViewModel {
public:
    AppViewModel(std::unique_ptr<IGeneratorEngine> engine,
                 std::unique_ptr<ISoarMockEngine>  soarEngine,
                 LogBuffer&                        logBuffer,
                 ApiRequestBuffer&                 apiBuffer);
    ~AppViewModel();

    AppViewModel(const AppViewModel&)            = delete;
    AppViewModel& operator=(const AppViewModel&) = delete;

    void tick(std::vector<DeviceProfile>& profiles,
              const std::function<void()>& onSave);

    void requestStart();
    void requestStop();
    void requestReload();
    void markDirty();
    void setDateOffsetDays(int days);

    [[nodiscard]] bool isRunning()   const { return m_isRunning; }
    [[nodiscard]] bool isReloading() const { return m_isReloading; }

    [[nodiscard]] IGeneratorEngine& engine()     { return *m_engine; }
    [[nodiscard]] ISoarMockEngine&  soarEngine() { return *m_soarEngine; }

private:
    void tickEngineState(std::vector<DeviceProfile>& profiles,
                         const std::function<void()>& onSave);
    void tickReload(std::vector<DeviceProfile>& profiles,
                    const std::function<void()>& onSave);

    std::unique_ptr<IGeneratorEngine> m_engine;
    std::unique_ptr<ISoarMockEngine>  m_soarEngine;
    LogBuffer&                        m_logBuffer;
    ApiRequestBuffer&                 m_apiBuffer;

    bool m_isRunning   = false;
    bool m_wasRunning  = false;
    bool m_isReloading = false;
    bool m_isDirty     = false;

    int  m_dateOffsetDays = 0;

    std::future<std::vector<DeviceProfile>> m_reloadFuture;
};
