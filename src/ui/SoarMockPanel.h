// src/ui/SoarMockPanel.h
#pragma once

#include "engine/ISoarMockEngine.h"
#include "core/channel/ApiRequestBuffer.h"
#include <imgui.h>
#include <cstddef>

class SoarMockPanel {
public:
    void render(ISoarMockEngine& engine, ApiRequestBuffer& apiBuffer,
                float width, ImFont* fontBold);

private:
    SoarEngineState m_lastKnownState = SoarEngineState::Idle;
    size_t          m_lastApiCount   = 0;
};
