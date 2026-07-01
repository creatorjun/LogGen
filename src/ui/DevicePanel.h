// src/ui/DevicePanel.h
#pragma once

#include <string>
#include <imgui.h>
#include "ui/viewmodel/DevicePanelViewModel.h"

class DevicePanel {
public:
    void render(DevicePanelViewModel& vm, float width, ImFont* fontBold);

private:
    void renderTemplatePopup();

    bool        m_popupPending  = false;
    bool        m_popupOpen     = false;
    std::string m_popupTitle;
    std::string m_popupContent;
    char        m_copyBuf[65536] = {};
};
