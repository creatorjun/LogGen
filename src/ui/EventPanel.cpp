// src/ui/EventPanel.cpp
#include "EventPanel.h"
#include "UIConstants.h"
#include "logging/Logger.h"
#include <imgui.h>
#include <imgui_stdlib.h>
#include <string>
#include <vector>

static const float kPanelPadding = 12.0f;

static void renderSectionHeader(const char* label, ImFont* fontBold) {
    ImGui::PushFont(fontBold);
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
    ImGui::TextUnformatted(label);
    ImGui::PopStyleColor();
    ImGui::PopFont();
    ImGui::Spacing();
}

static void renderFieldLabel(const char* label, ImFont* fontBold) {
    ImGui::PushFont(fontBold);
    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
    ImGui::TextUnformatted(label);
    ImGui::PopStyleColor();
    ImGui::PopFont();
}

static void renderIpBlock(
    const char* randomLabel, const char* checkId,
    bool& randomFlag,
    const char* fixedLabel,  const char* fixedId,  std::string& fixedIp,
    const char* startLabel,  const char* startId,  std::string& startIp,
    const char* endLabel,    const char* endId,    std::string& endIp,
    std::function<void(bool)>               onRandom,
    std::function<void(const std::string&)> onFixed,
    std::function<void(const std::string&)> onStart,
    std::function<void(const std::string&)> onEnd)
{
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::PushStyleColor(ImGuiCol_CheckMark,      UIColors::kAccent);
    ImGui::PushStyleColor(ImGuiCol_Text,           UIColors::kTextPrimary);
    ImGui::TextUnformatted(randomLabel);
    ImGui::SameLine();
    {
        const bool prev = randomFlag;
        ImGui::Checkbox(checkId, &randomFlag);
        if (randomFlag != prev) onRandom(randomFlag);
    }
    ImGui::PopStyleColor(4);
    ImGui::Spacing();

    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    if (randomFlag) {
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
        ImGui::TextUnformatted(startLabel);
        ImGui::PopStyleColor();
        ImGui::SetNextItemWidth(-1);
        {
            const std::string prev = startIp;
            ImGui::InputText(startId, &startIp);
            if (startIp != prev && ImGui::IsItemDeactivatedAfterEdit()) onStart(startIp);
        }
        ImGui::Spacing();
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
        ImGui::TextUnformatted(endLabel);
        ImGui::PopStyleColor();
        ImGui::SetNextItemWidth(-1);
        {
            const std::string prev = endIp;
            ImGui::InputText(endId, &endIp);
            if (endIp != prev && ImGui::IsItemDeactivatedAfterEdit()) onEnd(endIp);
        }
    } else {
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextPrimary);
        ImGui::TextUnformatted(fixedLabel);
        ImGui::PopStyleColor();
        ImGui::SetNextItemWidth(-1);
        {
            const std::string prev = fixedIp;
            ImGui::InputText(fixedId, &fixedIp);
            if (fixedIp != prev && ImGui::IsItemDeactivatedAfterEdit()) onFixed(fixedIp);
        }
    }
    ImGui::PopStyleColor(2);
}

static void renderProtocolButtons(
    bool useTCP, float width,
    std::function<void()> onUDP,
    std::function<void()> onTCP)
{
    const float half = (width - ImGui::GetStyle().ItemSpacing.x) * 0.5f;
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);

    auto pushActive = []() {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kAccent);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kAccentHover);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kAccentActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextOnAccent);
    };
    auto pushInactive = []() {
        ImGui::PushStyleColor(ImGuiCol_Button,        UIColors::kSurfaceSub);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, UIColors::kFrameBgHovered);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive,  UIColors::kSecondaryBtnActive);
        ImGui::PushStyleColor(ImGuiCol_Text,          UIColors::kTextPrimary);
    };

    if (!useTCP) pushActive(); else pushInactive();
    if (ImGui::Button(UIText::PROTOCOL_UDP, ImVec2(half, 0)) && useTCP) onUDP();
    ImGui::PopStyleColor(4);
    ImGui::SameLine();
    if (useTCP) pushActive(); else pushInactive();
    if (ImGui::Button(UIText::PROTOCOL_TCP, ImVec2(half, 0)) && !useTCP) onTCP();
    ImGui::PopStyleColor(4);

    ImGui::PopStyleVar();
}

static void renderSchedulerSection(
    DeviceProfile* target,
    EventPanelViewModel& vm,
    ImFont* fontBold)
{
    renderSectionHeader(UIText::SCHEDULER_SECTION, fontBold);

    renderFieldLabel(UIText::BURST_ENABLE_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::PushStyleColor(ImGuiCol_CheckMark,      UIColors::kAccent);
    {
        const bool prev = target->scheduler.burstEnable;
        ImGui::Checkbox("##burst", &target->scheduler.burstEnable);
        if (target->scheduler.burstEnable != prev)
            vm.onBurstEnableChanged(target->scheduler.burstEnable);
    }
    ImGui::PopStyleColor(3);
    ImGui::Spacing();

    renderFieldLabel(UIText::BURST_EPS_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        int v = static_cast<int>(target->scheduler.burstRate);
        const int prev = v;
        if (ImGui::InputInt("##burstRate", &v, 100, 10000, ImGuiInputTextFlags_CharsDecimal)
            && ImGui::IsItemDeactivatedAfterEdit() && v != prev)
            vm.onBurstRateChanged(v);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();

    renderFieldLabel(UIText::BURST_DURATION_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        float v = target->scheduler.burstDurationSec;
        const float prev = v;
        if (ImGui::InputFloat("##burstDur", &v, 1.0f, 10.0f, "%.1f s")
            && ImGui::IsItemDeactivatedAfterEdit() && v != prev)
            vm.onBurstDurationChanged(v);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();

    renderFieldLabel(UIText::BURST_INTERVAL_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        float v = target->scheduler.burstIntervalSec;
        const float prev = v;
        if (ImGui::InputFloat("##burstInt", &v, 1.0f, 10.0f, "%.1f s")
            && ImGui::IsItemDeactivatedAfterEdit() && v != prev)
            vm.onBurstIntervalChanged(v);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();

    ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
    ImGui::Text(UIText::CURRENT_EPS_FMT, target->scheduler.normalRate);
    ImGui::PopStyleColor();
}

void EventPanel::render(EventPanelViewModel& vm, float width, ImFont* fontBold) {
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(kPanelPadding, kPanelPadding));
    ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 6.0f);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, UIColors::kSurface);
    ImGui::BeginChild("EventPanel", ImVec2(width, 0), true);
    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    ImGui::Dummy(ImVec2(0, 2.0f));

    if (vm.hasNoDevice()) {
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
        ImGui::TextUnformatted(UIText::EVENT_NO_DEVICE);
        ImGui::PopStyleColor();
        ImGui::EndChild();
        return;
    }

    auto targets = vm.targets();

    if (targets.empty()) {
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
        ImGui::TextUnformatted(UIText::EVENT_SELECT_DEVICE);
        ImGui::PopStyleColor();
        ImGui::EndChild();
        return;
    }

    DeviceProfile* ref = targets[0];
    const float contentWidth = ImGui::GetContentRegionAvail().x;

    if (!vm.isMultiSelect()) {
        renderSectionHeader(UIText::DEVICE_PROFILE_SECTION, fontBold);

        renderFieldLabel(UIText::DEVICE_NAME_LABEL, fontBold);
        ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kFrameBgHovered);
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
        ImGui::PushStyleColor(ImGuiCol_Text,           UIColors::kTextMuted);
        ImGui::SetNextItemWidth(-1);
        ImGui::InputText("##deviceName", &ref->deviceName, ImGuiInputTextFlags_ReadOnly);
        ImGui::PopStyleColor(3);
        ImGui::Spacing();
    } else {
        ImGui::PushFont(fontBold);
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kOrange);
        ImGui::Text("%d\xEA\xB0\x9C \xEC\x9E\xA5\xEB\xB9\x84 \xEC\x9D\xBC\xEA\xB4\x84 \xEC\x84\xA4\xEC\xa0\x95",
                    vm.targetCount());
        ImGui::PopStyleColor();
        ImGui::PopFont();
        ImGui::PushStyleColor(ImGuiCol_Text, UIColors::kTextMuted);
        ImGui::TextUnformatted("\xEB\xB3\x80\xEA\xB2\xBD \xEC\x82\xAC\xED\x95\xAD\xEC\x9D\x80 \xEC\x84\xA0\xED\x83\x9D\xEB\x90\x9C \xEB\xAA\xA8\xEB\x93\xA0 \xEC\x9E\xA5\xEB\xB9\x84\xEC\x97\x90 \xEB\x8F\x99\xEC\x8B\x9C \xEC\xa0\x81\xEC\x9A\xA9\xEB\x90\xA9\xEB\x8B\x88\xEB\x8B\xA4.");
        ImGui::PopStyleColor();
        ImGui::Spacing();
    }

    renderFieldLabel(UIText::DEVICE_IP_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        const std::string prev = ref->eqpIp;
        ImGui::InputText("##eqpIp", &ref->eqpIp);
        if (ref->eqpIp != prev && ImGui::IsItemDeactivatedAfterEdit())
            vm.onEqpIpChanged(ref->eqpIp);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();

    renderFieldLabel(UIText::COLLECTOR_IP_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        const std::string prev = ref->collector.ip;
        ImGui::InputText("##collectorIp", &ref->collector.ip);
        if (ref->collector.ip != prev && ImGui::IsItemDeactivatedAfterEdit())
            vm.onCollectorIpChanged(ref->collector.ip);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();

    renderIpBlock(
        UIText::SRC_IP_RANDOM_LABEL, "##srcIpRandom",
        ref->event.srcIpRandom,
        UIText::SRC_IP_LABEL,       "##srcIp",      ref->event.srcIp,
        UIText::SRC_IP_START_LABEL, "##srcIpStart", ref->event.srcIpStart,
        UIText::SRC_IP_END_LABEL,   "##srcIpEnd",   ref->event.srcIpEnd,
        [&vm](bool v)               { vm.onSrcIpRandomChanged(v); },
        [&vm](const std::string& v) { vm.onSrcIpFixedChanged(v); },
        [&vm](const std::string& v) { vm.onSrcIpStartChanged(v); },
        [&vm](const std::string& v) { vm.onSrcIpEndChanged(v); }
    );
    ImGui::Spacing();

    renderIpBlock(
        UIText::DST_IP_RANDOM_LABEL, "##dstIpRandom",
        ref->event.dstIpRandom,
        UIText::DST_IP_LABEL,       "##dstIp",      ref->event.dstIpFixed,
        UIText::DST_IP_START_LABEL, "##dstIpStart", ref->event.dstIpStart,
        UIText::DST_IP_END_LABEL,   "##dstIpEnd",   ref->event.dstIpEnd,
        [&vm](bool v)               { vm.onDstIpRandomChanged(v); },
        [&vm](const std::string& v) { vm.onDstIpFixedChanged(v); },
        [&vm](const std::string& v) { vm.onDstIpStartChanged(v); },
        [&vm](const std::string& v) { vm.onDstIpEndChanged(v); }
    );
    ImGui::Spacing();

    renderFieldLabel(UIText::PORT_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        int port = static_cast<int>(ref->collector.port);
        const int prev = port;
        if (ImGui::InputInt("##port", &port, 0, 0)
            && ImGui::IsItemDeactivatedAfterEdit() && port != prev)
            vm.onPortChanged(port);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();

    renderFieldLabel(UIText::PROTOCOL_LABEL, fontBold);
    renderProtocolButtons(
        ref->collector.useTCP, contentWidth,
        [&vm]() { vm.onProtocolUDP(); },
        [&vm]() { vm.onProtocolTCP(); }
    );
    ImGui::Spacing();

    renderFieldLabel(UIText::BASE_EPS_LABEL, fontBold);
    ImGui::PushStyleColor(ImGuiCol_FrameBg,        UIColors::kSurfaceSub);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, UIColors::kFrameBgHovered);
    ImGui::SetNextItemWidth(-1);
    {
        int eps = static_cast<int>(ref->scheduler.normalRate);
        const int prev = eps;
        if (ImGui::InputInt("##eps", &eps, 100, 10000, ImGuiInputTextFlags_CharsDecimal)
            && ImGui::IsItemDeactivatedAfterEdit() && eps != prev)
            vm.onNormalRateChanged(eps);
    }
    ImGui::PopStyleColor(2);
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    renderSchedulerSection(ref, vm, fontBold);

    ImGui::EndChild();
}
