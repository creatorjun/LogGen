// src/ui/EventPanel.h
#pragma once

#include <imgui.h>
#include "ui/viewmodel/EventPanelViewModel.h"

class EventPanel {
public:
    void render(EventPanelViewModel& vm, float width, ImFont* fontBold);
};
