// src/ui/SoarMockPanel.cpp
#include "SoarMockPanel.h"
#include "UIConstants.h"
#include "logging/Logger.h"
#include <imgui.h>
#include <algorithm>
#include <string>

static constexpr ImVec4 kColorLabel  = ImVec4(0.940f, 0.942f, 0.980f, 1.0f);
static constexpr ImVec4 kColorMuted  = ImVec4(0.680f, 0.684f, 0.740f, 1.0f);
static constexpr ImVec4 kColorGreen  = ImVec4(0.200f, 0.900f, 0.400f, 1.0f);
static constexpr ImVec4 kColorRed    = ImVec4(0.950f, 0.300f, 0.300f, 1.0f);

static constexpr float kBtnHeight  = 44.0f;
static constexpr float kBtnMarginB = 4.0f;
static constexpr float kTableMinH  = 40.0f;

void SoarMockPanel::render(ISoarMockEngine& engine,
                            ApiRequestBuffer& apiBuffer,
                            float width, ImFont* fontBold)
{
    const auto prevState = m_lastKnownState;
    SoarEngineState st   = engine.getState();
    m_lastKnownState     = st;

    if (prevState != st) {
        switch (st) {
            case SoarEngineState::Idle:
                LOG_INFO("SOAR", "SOAR engine state -> Idle");
                break;
            case SoarEngineState::Running:
                LOG_INFO("SOAR", "SOAR engine state -> Running");
                break;
            case SoarEngineState::Error:
                LOG_WARN("SOAR", "SOAR engine state -> Error");
                break;
        }
    }

    const size_t prevApiCount = m_lastApiCount;
    const auto entries = apiBuffer.getEntries();
    m_lastApiCount = entries.size();
    if (m_lastApiCount > prevApiCount) {
        const size_t newCount = m_lastApiCount - prevApiCount;
        LOG_INFO("SOAR", "New API requests received: count=" + std::to_string(newCount)
            + ", total=" + std::to_string(m_lastApiCount));
    }

    const bool isRunning = (st == SoarEngineState::Running);

    static char ipBuf[64]  = "0.0.0.0";
    static char portBuf[8] = "8080";
    static bool useTLS     = false;

    ImGui::PushStyleColor(ImGuiCol_Text, kColorMuted);
    ImGui::TextUnformatted(UIText::SOAR_LABEL_ENDPOINT);
    ImGui::PopStyleColor();

    ImGui::SetNextItemWidth(width * 0.55f);
    ImGui::InputText("##soar_ip", ipBuf, sizeof(ipBuf));
    ImGui::SameLine();
    ImGui::SetNextItemWidth(width * 0.20f);
    ImGui::InputText("##soar_port", portBuf, sizeof(portBuf));
    ImGui::SameLine();
    if (ImGui::Checkbox("TLS", &useTLS)) {
        LOG_INFO("SOAR", std::string("TLS toggled: ") + (useTLS ? "ON" : "OFF"));
    }

    if (ImGui::Button(UIText::SOAR_BTN_CONNECT, ImVec2(-1.0f, 0.0f))) {
        LOG_INFO("SOAR", "SOAR connect requested: " + std::string(ipBuf) + ":" + std::string(portBuf) + (useTLS ? " [TLS]" : ""));
        engine.configure(std::string(ipBuf), static_cast<uint16_t>(std::stoi(portBuf)), useTLS);
    }

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    if (fontBold) ImGui::PushFont(fontBold);
    ImGui::PushStyleColor(ImGuiCol_Text, kColorLabel);
    ImGui::TextUnformatted(UIText::SOAR_LABEL_REQUEST_LOG);
    ImGui::PopStyleColor();
    if (fontBold) ImGui::PopFont();

    ImGui::Spacing();

    const float avail  = ImGui::GetContentRegionAvail().y;
    const float needed = kBtnHeight + kBtnMarginB + ImGui::GetStyle().ItemSpacing.y;
    const float tableH = std::max(kTableMinH, avail - needed);

    if (ImGui::BeginTable("ApiRequestTable",
        4,
        ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
        ImGuiTableFlags_ScrollY | ImGuiTableFlags_SizingStretchProp,
        ImVec2(0.0f, tableH)))
    {
        ImGui::TableSetupScrollFreeze(0, 1);
        ImGui::TableSetupColumn(UIText::SOAR_COL_TIME,   ImGuiTableColumnFlags_WidthStretch, 0.20f);
        ImGui::TableSetupColumn(UIText::SOAR_COL_METHOD, ImGuiTableColumnFlags_WidthStretch, 0.15f);
        ImGui::TableSetupColumn(UIText::SOAR_COL_PATH,   ImGuiTableColumnFlags_WidthStretch, 0.45f);
        ImGui::TableSetupColumn(UIText::SOAR_COL_STATUS, ImGuiTableColumnFlags_WidthStretch, 0.20f);
        ImGui::TableHeadersRow();

        for (int i = static_cast<int>(entries.size()) - 1; i >= 0; --i) {
            const ApiRequestEntry& e = entries[static_cast<size_t>(i)];
            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);
            ImGui::TextUnformatted(e.timestamp.c_str());

            ImGui::TableSetColumnIndex(1);
            ImGui::TextUnformatted(e.method.c_str());

            ImGui::TableSetColumnIndex(2);
            ImGui::TextUnformatted(e.path.c_str());

            ImGui::TableSetColumnIndex(3);
            const bool ok = (e.statusCode >= 200 && e.statusCode < 300);
            ImGui::PushStyleColor(ImGuiCol_Text, ok ? kColorGreen : kColorRed);
            ImGui::Text("%d", e.statusCode);
            ImGui::PopStyleColor();
        }

        ImGui::EndTable();
    }

    ImGui::Spacing();

    if (!isRunning) {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kAccent);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kAccentHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kAccentActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
        if (ImGui::Button(UIText::SOAR_BTN_START, ImVec2(-1.0f, kBtnHeight))) {
            LOG_INFO("SOAR", "SOAR start button clicked");
            engine.start();
        }
        ImGui::PopStyleColor(4);
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kDanger);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kDangerHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kDangerActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
        if (ImGui::Button(UIText::SOAR_BTN_STOP, ImVec2(-1.0f, kBtnHeight))) {
            LOG_INFO("SOAR", "SOAR stop button clicked");
            engine.stop();
        }
        ImGui::PopStyleColor(4);
    }
}
