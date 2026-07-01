// src/ui/MonitorPanel.h
#pragma once

#include <imgui.h>
#include "ui/viewmodel/MonitorPanelViewModel.h"
#include "engine/ISoarMockEngine.h"
#include "core/channel/ApiRequestBuffer.h"
#include "ui/SoarMockPanel.h"

class MonitorPanel {
public:
    void render(MonitorPanelViewModel& vm,
                ISoarMockEngine& soarEngine, ApiRequestBuffer& apiBuffer,
                float width, ImFont* fontBold);

private:
    void renderLogTab(MonitorPanelViewModel& vm);
    void renderDateOffsetBar(MonitorPanelViewModel& vm);
    void renderEpsChart(MonitorPanelViewModel& vm);
    void renderLiveTerminal(MonitorPanelViewModel& vm);
    void renderControlBar();

    SoarMockPanel m_soarPanel;
};
