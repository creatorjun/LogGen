// src/ui/viewmodel/EventPanelViewModel.cpp
#include "EventPanelViewModel.h"
#include "logging/Logger.h"
#include <algorithm>

EventPanelViewModel::EventPanelViewModel(std::vector<DeviceProfile>& profiles,
                                         const std::function<void()>& onDirty)
    : m_profiles(&profiles)
    , m_onDirty(onDirty)
{
    rebuildTargets();
}

void EventPanelViewModel::reset(std::vector<DeviceProfile>& profiles,
                                const std::function<void()>& onDirty)
{
    m_profiles = &profiles;
    m_onDirty  = onDirty;
    rebuildTargets();
}

void EventPanelViewModel::rebuildTargets() {
    m_targets.clear();
    if (!m_profiles) return;
    for (auto& p : *m_profiles)
        if (p.enabled)
            m_targets.push_back(&p);
}

bool EventPanelViewModel::hasNoDevice()  const {
    return !m_profiles || m_profiles->empty();
}
bool EventPanelViewModel::hasNoEnabled() const {
    return m_profiles && !m_profiles->empty() && m_targets.empty();
}
bool EventPanelViewModel::isMultiSelect() const { return m_targets.size() > 1; }
int  EventPanelViewModel::targetCount()   const { return static_cast<int>(m_targets.size()); }

DeviceProfile* EventPanelViewModel::singleTarget() {
    return m_targets.size() == 1 ? m_targets[0] : nullptr;
}

std::vector<DeviceProfile*> EventPanelViewModel::targets() {
    rebuildTargets();
    return m_targets;
}

void EventPanelViewModel::dirty(const std::string& tag, const std::string& val) {
    LOG_INFO("UI", tag + " -> " + val);
    if (m_onDirty) m_onDirty();
}

void EventPanelViewModel::onEqpIpChanged(const std::string& val) {
    for (auto* t : m_targets) t->eqpIp = val;
    dirty("[MULTI] eqpIp", val);
}

void EventPanelViewModel::onCollectorIpChanged(const std::string& val) {
    for (auto* t : m_targets) t->collector.ip = val;
    dirty("[MULTI] collectorIp", val);
}

void EventPanelViewModel::onPortChanged(int port) {
    const auto p16 = static_cast<uint16_t>(port);
    for (auto* t : m_targets) t->collector.port = p16;
    dirty("[MULTI] port", std::to_string(port));
}

void EventPanelViewModel::onProtocolUDP() {
    for (auto* t : m_targets) {
        t->collector.useTCP = false;
        t->collector.port   = kDefaultUDPPort;
    }
    dirty("[MULTI] protocol", "UDP");
}

void EventPanelViewModel::onProtocolTCP() {
    for (auto* t : m_targets) {
        t->collector.useTCP = true;
        t->collector.port   = kDefaultTCPPort;
    }
    dirty("[MULTI] protocol", "TCP");
}

void EventPanelViewModel::onNormalRateChanged(int eps) {
    eps = std::clamp(eps, kMinEps, kMaxEps);
    const float f = static_cast<float>(eps);
    for (auto* t : m_targets) t->scheduler.normalRate = f;
    dirty("[MULTI] normalRate", std::to_string(eps));
}

void EventPanelViewModel::onBurstEnableChanged(bool val) {
    for (auto* t : m_targets) t->scheduler.burstEnable = val;
    dirty("[MULTI] burstEnable", val ? "ON" : "OFF");
}

void EventPanelViewModel::onBurstRateChanged(int eps) {
    eps = std::clamp(eps, kMinBurstEps, kMaxBurstEps);
    const float f = static_cast<float>(eps);
    for (auto* t : m_targets) t->scheduler.burstRate = f;
    dirty("[MULTI] burstRate", std::to_string(eps));
}

void EventPanelViewModel::onBurstDurationChanged(float sec) {
    sec = std::clamp(sec, kMinBurstDuration, kMaxBurstDuration);
    for (auto* t : m_targets) t->scheduler.burstDurationSec = sec;
    dirty("[MULTI] burstDuration", std::to_string(sec));
}

void EventPanelViewModel::onBurstIntervalChanged(float sec) {
    sec = std::clamp(sec, kMinBurstInterval, kMaxBurstInterval);
    for (auto* t : m_targets) t->scheduler.burstIntervalSec = sec;
    dirty("[MULTI] burstInterval", std::to_string(sec));
}

void EventPanelViewModel::onSrcIpRandomChanged(bool val) {
    for (auto* t : m_targets) t->event.srcIpRandom = val;
    dirty("[MULTI] srcIpRandom", val ? "ON" : "OFF");
}

void EventPanelViewModel::onSrcIpFixedChanged(const std::string& val) {
    for (auto* t : m_targets) t->event.srcIp = val;
    dirty("[MULTI] srcIp", val);
}

void EventPanelViewModel::onSrcIpStartChanged(const std::string& val) {
    for (auto* t : m_targets) t->event.srcIpStart = val;
    dirty("[MULTI] srcIpStart", val);
}

void EventPanelViewModel::onSrcIpEndChanged(const std::string& val) {
    for (auto* t : m_targets) t->event.srcIpEnd = val;
    dirty("[MULTI] srcIpEnd", val);
}

void EventPanelViewModel::onDstIpRandomChanged(bool val) {
    for (auto* t : m_targets) t->event.dstIpRandom = val;
    dirty("[MULTI] dstIpRandom", val ? "ON" : "OFF");
}

void EventPanelViewModel::onDstIpFixedChanged(const std::string& val) {
    for (auto* t : m_targets) t->event.dstIpFixed = val;
    dirty("[MULTI] dstIp", val);
}

void EventPanelViewModel::onDstIpStartChanged(const std::string& val) {
    for (auto* t : m_targets) t->event.dstIpStart = val;
    dirty("[MULTI] dstIpStart", val);
}

void EventPanelViewModel::onDstIpEndChanged(const std::string& val) {
    for (auto* t : m_targets) t->event.dstIpEnd = val;
    dirty("[MULTI] dstIpEnd", val);
}
