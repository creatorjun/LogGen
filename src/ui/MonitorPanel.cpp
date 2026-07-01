// src/ui/MonitorPanel.cpp
#include "MonitorPanel.h"
#include "UIConstants.h"
#include "logging/Logger.h"
#include <imgui.h>
#include <imgui_internal.h>
#include <implot.h>
#include <algorithm>
#include <cinttypes>

static const float kPanelPadding = 12.0f;

static void clipboardSet(const std::string& text) {
    ImGui::SetClipboardText(text.c_str());
}

void MonitorPanel::render(MonitorPanelViewModel& vm,
                          ISoarMockEngine& soarEngine, ApiRequestBuffer& apiBuffer,
                          float width, ImFont* fontBold)
{
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(kPanelPadding, kPanelPadding));
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 6.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, UIColors::kSurface);
    ImGui::BeginChild("MonitorPanel", ImVec2(width, 0), true);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    ImGui::Dummy(ImVec2(0, 2.0f));

    ImGui::PushStyleColor(ImGuiCol_Tab,                 UIColors::kSurfaceSubAlpha);
    ImGui::PushStyleColor(ImGuiCol_TabHovered,          UIColors::kAccentSubtle);
    ImGui::PushStyleColor(ImGuiCol_TabActive,           UIColors::kAccent);
    ImGui::PushStyleColor(ImGuiCol_TabSelectedOverline, UIColors::kAccent);
    ImGui::PushStyleColor(ImGuiCol_Text,                UIColors::kTextPrimary);

    if (ImGui::BeginTabBar("MonitorTabs")) {
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
        if (ImGui::BeginTabItem(UIText::SOAR_TAB_LOG)) {
            ImGui::PopStyleColor();
            ImGui::Spacing();
            renderLogTab(vm);
            ImGui::EndTabItem();
        } else {
            ImGui::PopStyleColor();
        }

        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
        if (ImGui::BeginTabItem(UIText::SOAR_TAB_SOAR)) {
            ImGui::PopStyleColor();
            ImGui::Spacing();
            m_soarPanel.render(soarEngine, apiBuffer,
                               ImGui::GetContentRegionAvail().x, fontBold);
            ImGui::EndTabItem();
        } else {
            ImGui::PopStyleColor();
        }
        ImGui::EndTabBar();
    }
    ImGui::PopStyleColor(5);
    ImGui::EndChild();
}

void MonitorPanel::renderLogTab(MonitorPanelViewModel& vm) {
    const float availH  = ImGui::GetContentRegionAvail().y;
    const float termH   = availH * 0.32f;
    const float statsH  = 32.0f;
    const float btnH    = 44.0f;
    const float dateH   = 32.0f;
    const float spacing = ImGui::GetStyle().ItemSpacing.y;
    const float chartH  = availH - termH - statsH - btnH - dateH - spacing * 6.0f - 8.0f;

    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, UIColors::kSurfaceMid);
    ImGui::BeginChild("TerminalArea", ImVec2(0.0f, termH), false);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    renderLiveTerminal(vm);
    ImGui::EndChild();
    ImGui::Spacing();

    ImGui::PushStyleColor(ImGuiCol_ChildBg, UIColors::kTransparent);
    ImGui::BeginChild("StatsBar", ImVec2(0.0f, statsH), false);
    ImGui::PopStyleColor();
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
    ImGui::TextUnformatted(UIText::STATS_TOTAL_SENT_LABEL);
    ImGui::PopStyleColor();
    ImGui::SameLine();
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kAccent);
    ImGui::Text("%" PRIu64, vm.displayedTotalSent());
    ImGui::PopStyleColor();
    ImGui::EndChild();
    ImGui::Spacing();

    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 4.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, UIColors::kSurface);
    ImGui::BeginChild("ChartArea", ImVec2(0.0f, chartH), false);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar();
    renderEpsChart(vm);
    ImGui::EndChild();
    ImGui::Spacing();

    renderDateOffsetBar(vm);
    ImGui::Spacing();

    if (!vm.isRunning()) {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kAccent);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kAccentHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kAccentActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
        if (ImGui::Button(UIText::BTN_START, ImVec2(-1.0f, btnH)))
            vm.onStartClicked();
        ImGui::PopStyleColor(4);
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kDanger);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kDangerHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kDangerActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
        if (ImGui::Button(UIText::BTN_STOP, ImVec2(-1.0f, btnH)))
            vm.onStopClicked();
        ImGui::PopStyleColor(4);
    }
}

// 날짜 오프셋 UI: [\ub85c\uadf8 \uc0dd\uc131\uc77c] [-] [+] [__n__] \uc77c
// - \uc120\ud0dd\ub41c \ubd80\ud638 \ubc84\ud2bc\uc740 \ud30c\ub780\uc0c9(Accent), \uc120\ud0dd\ub418\uc9c0 \uc54a\uc740 \ucabd\uc740 \ud68c\uc0c9(SmallBtnOff)
void MonitorPanel::renderDateOffsetBar(MonitorPanelViewModel& vm) {
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
    ImGui::TextUnformatted(UIText::LOG_DATE_OFFSET_LABEL);
    ImGui::PopStyleColor();
    ImGui::SameLine();

    const bool isPositive = vm.dateSign();   // true = +(\ubbf8\ub798), false = -(\uacfc\uac70)

    // --- [-] \ubc84\ud2bc ---
    if (!isPositive) {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kAccent);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kAccentHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kAccentActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kSmallBtnOffNorm);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kSmallBtnOffHov);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kSmallBtnOffAct);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextPrimary);
    }
    if (ImGui::Button("-##datesign", ImVec2(28.0f, 0.0f)))
        vm.setDateSign(false);
    ImGui::PopStyleColor(4);

    ImGui::SameLine();

    // --- [+] \ubc84\ud2bc ---
    if (isPositive) {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kAccent);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kAccentHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kAccentActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
    } else {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kSmallBtnOffNorm);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kSmallBtnOffHov);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kSmallBtnOffAct);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextPrimary);
    }
    if (ImGui::Button("+##datesign", ImVec2(28.0f, 0.0f)))
        vm.setDateSign(true);
    ImGui::PopStyleColor(4);

    ImGui::SameLine();

    // --- \uc77c\uc218 \uc785\ub825 ---
    int days = vm.dateDays();
    ImGui::SetNextItemWidth(80.0f);
    if (ImGui::InputInt("##dateDays", &days, 1, 10)) {
        if (days < 0)    days = 0;
        if (days > 3650) days = 3650;
        vm.setDateDays(days);
    }

    ImGui::SameLine();
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
    ImGui::TextUnformatted(UIText::LOG_DATE_OFFSET_UNIT);
    ImGui::PopStyleColor();
}

void MonitorPanel::renderControlBar() {}

void MonitorPanel::renderEpsChart(MonitorPanelViewModel& vm) {
    static constexpr float kHistoryRange = 120.0f;
    const float t = vm.chartTime();
    const auto& totalData = vm.totalEpsData();

    if (ImPlot::BeginPlot("##EPS", ImVec2(-1, -1),
                          ImPlotFlags_NoMouseText | ImPlotFlags_NoMenus))
    {
        ImPlot::SetupAxes(
            UIText::CHART_X_AXIS_LABEL,
            UIText::CHART_Y_AXIS_LABEL,
            ImPlotAxisFlags_NoTickLabels | ImPlotAxisFlags_NoHighlight,
            ImPlotAxisFlags_AutoFit      | ImPlotAxisFlags_NoHighlight);
        ImPlot::SetupAxisLimits(ImAxis_X1, t - kHistoryRange, t + 1.0f, ImGuiCond_Always);
        ImPlot::SetupAxisLimits(ImAxis_Y1, 0.0, 100.0, ImGuiCond_Once);

        const int n = totalData.Size();
        if (n >= 2) {
            totalData.getLinear(vm.tmpXs, vm.tmpYs);
            ImPlot::PlotLine(UIText::CHART_TOTAL_EPS_LINE,
                             vm.tmpXs.data(), vm.tmpYs.data(), n);
            ImPlot::PlotShaded("##shade",
                               vm.tmpXs.data(), vm.tmpYs.data(), n, 0.0);
        }
        ImPlot::EndPlot();
    }
}

void MonitorPanel::renderLiveTerminal(MonitorPanelViewModel& vm) {
    const ImVec2 avail = ImGui::GetContentRegionAvail();
    const int    total = static_cast<int>(vm.terminalLines().size());
    const bool ctrlHeld  = ImGui::GetIO().KeyCtrl;
    const bool shiftHeld = ImGui::GetIO().KeyShift;

    ImGui::PushStyleColor(ImGuiCol_ChildBg,       UIColors::kTransparent);
    ImGui::PushStyleColor(ImGuiCol_Header,        UIColors::kAccentSelect);
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, UIColors::kAccentSelectHov);
    ImGui::PushStyleColor(ImGuiCol_HeaderActive,  UIColors::kAccentSelectAct);
    ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextGreen);
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0.0f, 0.0f));

    ImGui::BeginChild("##terminal_lines", avail, false,
                      ImGuiWindowFlags_HorizontalScrollbar);

    if (ctrlHeld && ImGui::IsWindowFocused(ImGuiFocusedFlags_ChildWindows)
                 && ImGui::IsKeyPressed(ImGuiKey_C, false)) {
        bool anySelected = false;
        for (bool s : vm.terminalSelected()) if (s) { anySelected = true; break; }
        if (anySelected) {
            vm.copySelectedLines(clipboardSet);
        } else {
            std::string all;
            all.reserve(vm.terminalLines().size() * 80);
            for (const auto& l : vm.terminalLines()) { all += l; all += '\n'; }
            if (!all.empty()) clipboardSet(all);
        }
    }

    auto& sel = vm.terminalSelected();
    ImGuiListClipper clipper;
    clipper.Begin(total);
    while (clipper.Step()) {
        for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; ++i) {
            const bool isSelected = (i < static_cast<int>(sel.size())) && sel[static_cast<size_t>(i)];
            ImGui::PushID(i);
            if (ImGui::Selectable(vm.terminalLines()[static_cast<size_t>(i)].c_str(),
                                  isSelected, ImGuiSelectableFlags_None, ImVec2(0.0f, 0.0f)))
            {
                if (i < static_cast<int>(sel.size())) {
                    if (shiftHeld && vm.lastClickedLine() >= 0) {
                        const int lo = std::min(vm.lastClickedLine(), i);
                        const int hi = std::max(vm.lastClickedLine(), i);
                        for (int j = lo; j <= hi; ++j)
                            if (j < static_cast<int>(sel.size()))
                                sel[static_cast<size_t>(j)] = true;
                    } else if (ctrlHeld) {
                        sel[static_cast<size_t>(i)] = !sel[static_cast<size_t>(i)];
                        vm.setLastClickedLine(i);
                    } else {
                        std::fill(sel.begin(), sel.end(), false);
                        sel[static_cast<size_t>(i)] = true;
                        vm.setLastClickedLine(i);
                    }
                }
            }
            ImGui::PopID();
        }
    }
    clipper.End();

    if (vm.scrollToBottom()) {
        ImGui::SetScrollHereY(1.0f);
        vm.clearScrollFlag();
    }

    if (ImGui::BeginPopupContextWindow("##terminal_ctx", ImGuiPopupFlags_MouseButtonRight)) {
        bool anySelected = false;
        for (bool s : sel) if (s) { anySelected = true; break; }

        if (ImGui::MenuItem("Copy Selected", "Ctrl+C", false, anySelected))
            vm.copySelectedLines(clipboardSet);
        if (ImGui::MenuItem("Copy All")) {
            std::string all;
            all.reserve(vm.terminalLines().size() * 80);
            for (const auto& line : vm.terminalLines()) { all += line; all += '\n'; }
            clipboardSet(all);
        }
        ImGui::Separator();
        if (ImGui::MenuItem("Select All"))
            std::fill(sel.begin(), sel.end(), true);
        if (ImGui::MenuItem("Deselect All", nullptr, false, anySelected))
            std::fill(sel.begin(), sel.end(), false);
        ImGui::Separator();
        if (ImGui::MenuItem("Clear"))
            vm.clearTerminal();
        ImGui::EndPopup();
    }

    ImGui::EndChild();
    ImGui::PopStyleVar();
    ImGui::PopStyleColor(5);
}
