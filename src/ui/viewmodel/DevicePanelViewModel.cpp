// src/ui/viewmodel/DevicePanelViewModel.cpp
#include "DevicePanelViewModel.h"
#include "logging/Logger.h"

DevicePanelViewModel::DevicePanelViewModel(
    std::vector<DeviceProfile>& profiles,
    std::function<bool()>        isReloading,
    const std::function<void()>& onDirty,
    const std::function<void()>& onReload)
    : m_profiles(&profiles)
    , m_isReloading(std::move(isReloading))
    , m_onDirty(onDirty)
    , m_onReload(onReload)
{}

void DevicePanelViewModel::reset(
    std::vector<DeviceProfile>& profiles,
    std::function<bool()>        isReloading,
    const std::function<void()>& onDirty,
    const std::function<void()>& onReload)
{
    m_profiles    = &profiles;
    m_isReloading = std::move(isReloading);
    m_onDirty     = onDirty;
    m_onReload    = onReload;
}

bool DevicePanelViewModel::isReloading() const {
    return m_isReloading ? m_isReloading() : false;
}

const std::vector<DeviceProfile>& DevicePanelViewModel::profiles() const {
    static const std::vector<DeviceProfile> kEmpty;
    return m_profiles ? *m_profiles : kEmpty;
}

void DevicePanelViewModel::onCardClicked(int index) {
    if (!m_profiles) return;
    if (index < 0 || index >= static_cast<int>(m_profiles->size())) return;
    auto& p = (*m_profiles)[static_cast<size_t>(index)];
    p.enabled = !p.enabled;
    LOG_INFO("UI", std::string(p.enabled ? "Device enabled: [" : "Device disabled: [")
             + p.deviceName + "] index=" + std::to_string(index));
    if (m_onDirty) m_onDirty();
}

DevicePanelViewModel::PopupData DevicePanelViewModel::onLogClicked(int index) {
    if (!m_profiles) return {};
    if (index < 0 || index >= static_cast<int>(m_profiles->size()))
        return {};
    const auto& p = (*m_profiles)[static_cast<size_t>(index)];
    LOG_INFO("UI", "LOG button clicked: [" + p.deviceName + "]");
    PopupData d;
    d.title   = p.deviceName + "  -  LOG Format";
    d.content = p.formatRaw.empty() ? "(format.raw \xec\x97\x86\xec\x9d\x8c)" : p.formatRaw;
    return d;
}

DevicePanelViewModel::PopupData DevicePanelViewModel::onXmlClicked(int index) {
    if (!m_profiles) return {};
    if (index < 0 || index >= static_cast<int>(m_profiles->size()))
        return {};
    const auto& p = (*m_profiles)[static_cast<size_t>(index)];
    LOG_INFO("UI", "XML button clicked: [" + p.deviceName + "]");
    PopupData d;
    d.title   = p.deviceName + "  -  XML Template";
    d.content = p.xmlRaw.empty() ? "(xml.raw \xec\x97\x86\xec\x9d\x8c)" : p.xmlRaw;
    return d;
}

void DevicePanelViewModel::onReloadClicked() {
    if (!m_isReloading || m_isReloading()) return;
    if (m_onReload) m_onReload();
}
