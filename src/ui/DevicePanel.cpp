// src/ui/DevicePanel.cpp
#include "DevicePanel.h"
#include "UIConstants.h"
#include "logging/Logger.h"
#include <imgui.h>
#include <imgui_stdlib.h>
#include <cmath>
#include <cstring>

static const float kPanelPadding  = 12.0f;
static const float kCardPaddingX  = 10.0f;
static const float kCardPaddingY  = 8.0f;
static const float kCardRounding  = 6.0f;
static const float kCardHeight    = 62.0f;
static const float kBtnWidth      = 44.0f;
static const float kBtnHeight     = 22.0f;
static const float kBtnRounding   = 4.0f;
static const float kCardSpacing   = 5.0f;
static const float kReloadBtnSize = 20.0f;

static constexpr float kPi = 3.14159265358979323846f;

static const char* kTemplateModalId = "##TemplateModal";

static void renderSectionHeader(const char* label, ImFont* fontBold) {
    ImGui::PushFont(fontBold);
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
    ImGui::TextUnformatted(label);
    ImGui::PopStyleColor();
    ImGui::PopFont();
}

static void drawReloadIcon(ImDrawList* dl, ImVec2 center, float radius,
                            ImU32 color, bool spinning, float timeSeconds) {
    const int   segments = 32;
    const float arcStart = spinning ? (timeSeconds * 3.0f) : 0.3f;
    const float arcEnd   = arcStart + (kPi * 2.0f - 0.6f);
    for (int i = 0; i < segments; ++i) {
        const float a0 = arcStart + (arcEnd - arcStart) * (static_cast<float>(i)     / segments);
        const float a1 = arcStart + (arcEnd - arcStart) * (static_cast<float>(i + 1) / segments);
        dl->AddLine(
            ImVec2(center.x + cosf(a0) * radius, center.y + sinf(a0) * radius),
            ImVec2(center.x + cosf(a1) * radius, center.y + sinf(a1) * radius),
            color, 1.8f);
    }
    const float arrowAngle = arcEnd;
    const float arrowSize  = radius * 0.55f;
    ImVec2 tip   = ImVec2(center.x + cosf(arrowAngle) * radius,
                           center.y + sinf(arrowAngle) * radius);
    ImVec2 left  = ImVec2(center.x + cosf(arrowAngle - 2.3f) * (radius - arrowSize),
                           center.y + sinf(arrowAngle - 2.3f) * (radius - arrowSize));
    ImVec2 right = ImVec2(center.x + cosf(arrowAngle + 0.4f) * (radius - arrowSize * 0.5f),
                           center.y + sinf(arrowAngle + 0.4f) * (radius - arrowSize * 0.5f));
    dl->AddTriangleFilled(tip, left, right, color);
}

static void drawCardBackground(ImDrawList* dl, ImVec2 pos, ImVec2 size,
                                bool enabled, bool hovered) {
    ImVec4 bg = enabled
        ? (hovered ? UIColors::kAccentDimHover : UIColors::kAccentDim)
        : (hovered ? UIColors::kCardHover      : UIColors::kCardNormal);
    ImVec4 border = enabled ? UIColors::kAccent : UIColors::kCardBorderOff;
    dl->AddRectFilled(pos, ImVec2(pos.x + size.x, pos.y + size.y),
                      ImGui::ColorConvertFloat4ToU32(bg), kCardRounding);
    dl->AddRect(pos, ImVec2(pos.x + size.x, pos.y + size.y),
                ImGui::ColorConvertFloat4ToU32(border), kCardRounding, 0, 1.2f);
}

static void drawSmallButton(ImDrawList* dl, ImVec2 pos, ImVec2 size,
                             const char* label, bool enabled,
                             bool btnHovered, bool btnActive) {
    ImVec4 bgNorm = enabled
        ? ImVec4(UIColors::kAccent.x, UIColors::kAccent.y, UIColors::kAccent.z, 0.30f)
        : UIColors::kSmallBtnOffNorm;
    ImVec4 bgHov  = enabled
        ? ImVec4(UIColors::kAccent.x, UIColors::kAccent.y, UIColors::kAccent.z, 0.50f)
        : UIColors::kSmallBtnOffHov;
    ImVec4 bgAct  = enabled
        ? ImVec4(UIColors::kAccent.x, UIColors::kAccent.y, UIColors::kAccent.z, 0.70f)
        : UIColors::kSmallBtnOffAct;
    ImVec4 bg = btnActive ? bgAct : (btnHovered ? bgHov : bgNorm);
    ImVec4 borderColor = enabled
        ? ImVec4(UIColors::kAccent.x, UIColors::kAccent.y, UIColors::kAccent.z, 0.70f)
        : UIColors::kSmallBtnOffBdr;
    ImVec2 br = ImVec2(pos.x + size.x, pos.y + size.y);
    dl->AddRectFilled(pos, br, ImGui::ColorConvertFloat4ToU32(bg), kBtnRounding);
    dl->AddRect(pos, br, ImGui::ColorConvertFloat4ToU32(borderColor), kBtnRounding, 0, 1.0f);
    ImVec2 textSize = ImGui::CalcTextSize(label);
    ImVec2 textPos  = ImVec2(pos.x + (size.x - textSize.x) * 0.5f,
                             pos.y + (size.y - textSize.y) * 0.5f);
    ImVec4 textColor = enabled ? UIColors::kAccent : UIColors::kTextPrimary;
    dl->AddText(textPos, ImGui::ColorConvertFloat4ToU32(textColor), label);
}

void DevicePanel::renderTemplatePopup() {
    if (!m_popupOpen) return;

    ImGuiIO& io = ImGui::GetIO();
    const float popupW = 680.0f;
    const float popupH = 460.0f;
    ImVec2 center = ImVec2(io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f);
    ImGui::SetNextWindowPos(center, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(popupW, popupH), ImGuiCond_Always);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding,  ImVec2(20.0f, 16.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing,    ImVec2(8.0f, 10.0f));
    ImGui::PushStyleColor(ImGuiCol_WindowBg,         UIColors::kSurface);
    ImGui::PushStyleColor(ImGuiCol_Border,           UIColors::kBorderNormal);
    ImGui::PushStyleColor(ImGuiCol_TitleBg,          UIColors::kSurfaceMid);
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive,    UIColors::kSurfaceMid);
    ImGui::PushStyleColor(ImGuiCol_ModalWindowDimBg, UIColors::kModalDimBg);

    constexpr ImGuiWindowFlags kModalFlags =
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar;

    if (ImGui::BeginPopupModal(kTemplateModalId, nullptr, kModalFlags)) {
        ImGui::PushFont(nullptr);
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
        ImGui::TextUnformatted(m_popupTitle.c_str());
        ImGui::PopStyleColor();
        ImGui::PopFont();
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kFrameBg);
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
        ImGui::PushStyleColor(ImGuiCol_Border,         UIColors::kFrameBorder);
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,  ImVec2(10.0f, 8.0f));

        const float usedH = ImGui::GetTextLineHeightWithSpacing()
                          + 1.0f
                          + ImGui::GetStyle().ItemSpacing.y * 4.0f
                          + 30.0f
                          + 16.0f * 2.0f;
        const float textH = popupH - usedH - 24.0f;

        ImGui::InputTextMultiline(
            "##tpl", m_copyBuf, sizeof(m_copyBuf),
            ImVec2(-1.0f, textH), ImGuiInputTextFlags_ReadOnly);

        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(3);
        ImGui::Spacing();

        const float btnW      = 120.0f;
        const float btnH      = 30.0f;
        const float totalBtnW = btnW * 2.0f + 8.0f;
        ImGui::SetCursorPosX((popupW - totalBtnW) * 0.5f);

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,  ImVec2(0.0f, 0.0f));
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kAccent);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kAccentHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kAccentActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
        if (ImGui::Button("\ubcf5\uc0ac", ImVec2(btnW, btnH)))
            ImGui::SetClipboardText(m_copyBuf);
        ImGui::PopStyleColor(4);
        ImGui::PopStyleVar(2);
        ImGui::SameLine(0.0f, 8.0f);

        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,  ImVec2(0.0f, 0.0f));
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kSecondaryBtn);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kSecondaryBtnHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kSecondaryBtnActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextPrimary);
        if (ImGui::Button("\ub2eb\uae30", ImVec2(btnW, btnH))) {
            m_popupOpen = false;
            ImGui::CloseCurrentPopup();
        }
        ImGui::PopStyleColor(4);
        ImGui::PopStyleVar(2);

        ImGui::EndPopup();
    } else {
        m_popupOpen = false;
    }

    ImGui::PopStyleColor(5);
    ImGui::PopStyleVar(3);
}

void DevicePanel::render(DevicePanelViewModel& vm, float width, ImFont* fontBold) {
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(kPanelPadding, kPanelPadding));
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 6.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, UIColors::kSurface);
    ImGui::BeginChild("DeviceListPanel", ImVec2(width, 0), true);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    ImGui::Dummy(ImVec2(0, 2.0f));

    {
        const float lineH  = ImGui::GetTextLineHeight();
        const float totalH = (kReloadBtnSize > lineH) ? kReloadBtnSize : lineH;
        const float btnR   = kReloadBtnSize * 0.5f;

        ImVec2 headerCursor = ImGui::GetCursorScreenPos();
        ImGui::SetCursorScreenPos(
            ImVec2(headerCursor.x, headerCursor.y + (totalH - lineH) * 0.5f));
        renderSectionHeader(UIText::DEVICE_PANEL_SECTION, fontBold);

        const float btnX = headerCursor.x
                         + ImGui::CalcTextSize(UIText::DEVICE_PANEL_SECTION).x + 8.0f;
        const float btnY = headerCursor.y + (totalH - kReloadBtnSize) * 0.5f;
        ImVec2 rTL = ImVec2(btnX, btnY);

        ImDrawList* dlHeader = ImGui::GetWindowDrawList();
        ImGui::SetCursorScreenPos(rTL);
        ImGui::InvisibleButton("##reload", ImVec2(kReloadBtnSize, kReloadBtnSize));
        const bool reloadHov   = ImGui::IsItemHovered();
        const bool reloadAct   = ImGui::IsItemActive();
        const bool reloadClick = ImGui::IsItemClicked(ImGuiMouseButton_Left);

        if (reloadHov) {
            dlHeader->AddCircleFilled(
                ImVec2(btnX + btnR, btnY + btnR), btnR + 2.0f,
                IM_COL32(0, 120, 212, reloadAct ? 50 : 25));
        }

        const float t = static_cast<float>(ImGui::GetTime());
        const bool  reloading = vm.isReloading();
        ImU32 iconColor = reloading
            ? IM_COL32(0, 120, 212, 220)
            : (reloadHov ? IM_COL32(0, 120, 212, 230) : IM_COL32(80, 80, 80, 200));
        drawReloadIcon(dlHeader, ImVec2(btnX + btnR, btnY + btnR),
                       btnR - 2.0f, iconColor, reloading, t);

        if (reloadHov) ImGui::SetTooltip("%s", UIText::DEVICE_RELOAD_TOOLTIP);
        if (reloadClick) vm.onReloadClicked();

        ImGui::SetCursorScreenPos(ImVec2(headerCursor.x, headerCursor.y + totalH));
        ImGui::Dummy(ImVec2(0, 0));
    }

    ImGui::Spacing();

    if (vm.isReloading()) {
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kAccent);
        ImGui::TextUnformatted(UIText::DEVICE_RELOADING_LABEL);
        ImGui::PopStyleColor();
        ImGui::EndChild();
        if (m_popupPending) {
            ImGui::OpenPopup(kTemplateModalId);
            m_popupPending = false;
            m_popupOpen    = true;
        }
        renderTemplatePopup();
        return;
    }

    ImDrawList* dl = ImGui::GetWindowDrawList();
    const float availW = ImGui::GetContentRegionAvail().x;
    const auto& profiles = vm.profiles();

    for (int i = 0; i < static_cast<int>(profiles.size()); ++i) {
        const auto& p = profiles[static_cast<size_t>(i)];
        ImGui::PushID(i);

        ImVec2 cardPos  = ImGui::GetCursorScreenPos();
        ImVec2 cardSize = ImVec2(availW, kCardHeight);

        const float btnAreaY = cardPos.y + kCardPaddingY + ImGui::GetTextLineHeight() + 6.0f;
        const float btn1X    = cardPos.x + kCardPaddingX;
        const float btn2X    = btn1X + kBtnWidth + 6.0f;
        ImVec2 btn1TL = ImVec2(btn1X, btnAreaY);
        ImVec2 btn2TL = ImVec2(btn2X, btnAreaY);
        ImVec2 btnSz  = ImVec2(kBtnWidth, kBtnHeight);

        ImGui::SetCursorScreenPos(btn1TL);
        ImGui::InvisibleButton("##log", btnSz);
        const bool btn1Hov     = ImGui::IsItemHovered();
        const bool btn1Act     = ImGui::IsItemActive();
        const bool btn1Clicked = ImGui::IsItemClicked(ImGuiMouseButton_Left);

        ImGui::SetCursorScreenPos(btn2TL);
        ImGui::InvisibleButton("##xml", btnSz);
        const bool btn2Hov     = ImGui::IsItemHovered();
        const bool btn2Act     = ImGui::IsItemActive();
        const bool btn2Clicked = ImGui::IsItemClicked(ImGuiMouseButton_Left);

        const bool overAnyBtn = btn1Hov || btn2Hov || btn1Act || btn2Act;
        ImGui::SetCursorScreenPos(cardPos);
        ImGui::InvisibleButton("##card", cardSize);
        const bool cardHovered = ImGui::IsItemHovered() && !overAnyBtn;
        const bool cardClicked = ImGui::IsItemClicked(ImGuiMouseButton_Left) && !overAnyBtn;

        if (btn1Clicked) {
            auto d = vm.onLogClicked(i);
            m_popupTitle   = std::move(d.title);
            m_popupContent = std::move(d.content);
            const std::size_t copyLen = m_popupContent.size() < sizeof(m_copyBuf) - 1
                ? m_popupContent.size() : sizeof(m_copyBuf) - 1;
            std::memcpy(m_copyBuf, m_popupContent.c_str(), copyLen);
            m_copyBuf[copyLen] = '\0';
            m_popupPending = true;
        }
        if (btn2Clicked) {
            auto d = vm.onXmlClicked(i);
            m_popupTitle   = std::move(d.title);
            m_popupContent = std::move(d.content);
            const std::size_t copyLen = m_popupContent.size() < sizeof(m_copyBuf) - 1
                ? m_popupContent.size() : sizeof(m_copyBuf) - 1;
            std::memcpy(m_copyBuf, m_popupContent.c_str(), copyLen);
            m_copyBuf[copyLen] = '\0';
            m_popupPending = true;
        }
        if (cardClicked) vm.onCardClicked(i);

        drawCardBackground(dl, cardPos, cardSize, p.enabled, cardHovered);

        const float textX = cardPos.x + kCardPaddingX;
        const float textY = cardPos.y + kCardPaddingY;
        ImVec4 textColor = p.enabled ? UIColors::kAccent : UIColors::kTextPrimary;
        dl->AddText(ImVec2(textX, textY),
                    ImGui::ColorConvertFloat4ToU32(textColor),
                    p.deviceName.c_str());
        drawSmallButton(dl, btn1TL, btnSz, "LOG", p.enabled, btn1Hov, btn1Act);
        drawSmallButton(dl, btn2TL, btnSz, "XML", p.enabled, btn2Hov, btn2Act);

        ImGui::SetCursorScreenPos(ImVec2(cardPos.x, cardPos.y + kCardHeight + kCardSpacing));
        ImGui::Dummy(ImVec2(0, 0));
        ImGui::PopID();
    }

    ImGui::EndChild();

    if (m_popupPending) {
        ImGui::OpenPopup(kTemplateModalId);
        m_popupPending = false;
        m_popupOpen    = true;
    }
    renderTemplatePopup();
}
