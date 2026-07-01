// src/ui/AppWindow.h
#pragma once

#include <string>
#include <memory>
#include <vector>
#include <functional>
#include <imgui.h>
#include "engine/IGeneratorEngine.h"
#include "engine/ISoarMockEngine.h"
#include "core/DeviceProfile.h"
#include "core/channel/LogBuffer.h"
#include "core/channel/ApiRequestBuffer.h"
#include "ui/DevicePanel.h"
#include "ui/EventPanel.h"
#include "ui/MonitorPanel.h"
#include "ui/viewmodel/AppViewModel.h"
#include "ui/viewmodel/DevicePanelViewModel.h"
#include "ui/viewmodel/EventPanelViewModel.h"
#include "ui/viewmodel/MonitorPanelViewModel.h"

struct GLFWwindow;

class AppWindow {
public:
    AppWindow(int width, int height, const std::string& title,
              std::unique_ptr<IGeneratorEngine> engine,
              std::unique_ptr<ISoarMockEngine>  soarEngine);
    ~AppWindow();

    bool init();
    void mainLoop(std::vector<DeviceProfile>& profiles,
                  std::function<void()> onSaveRequest);
    void markProfilesDirty();

private:
    void renderUI(std::vector<DeviceProfile>& profiles,
                  const std::function<void()>& onSaveRequest);
    void setupFonts();

    int         m_width;
    int         m_height;
    std::string m_title;
    GLFWwindow* m_window = nullptr;

    LogBuffer        m_logBuffer;
    ApiRequestBuffer m_apiBuffer;

    AppViewModel                          m_viewModel;
    std::unique_ptr<MonitorPanelViewModel> m_monitorVM;
    DevicePanelViewModel                  m_deviceVM;
    EventPanelViewModel                   m_eventVM;

    DevicePanel  m_devicePanel;
    EventPanel   m_eventPanel;
    MonitorPanel m_monitorPanel;

    ImFont* m_fontRegular = nullptr;
    ImFont* m_fontBold    = nullptr;

    std::vector<DeviceProfile>* m_profiles = nullptr;
};
