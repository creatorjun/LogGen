// src/ui/viewmodel/DevicePanelViewModel.h
#pragma once

#include <vector>
#include <functional>
#include <string>
#include "core/DeviceProfile.h"

class DevicePanelViewModel {
public:
    struct PopupData {
        std::string title;
        std::string content;
    };

    DevicePanelViewModel() = default;

    DevicePanelViewModel(std::vector<DeviceProfile>& profiles,
                         std::function<bool()>        isReloading,
                         const std::function<void()>& onDirty,
                         const std::function<void()>& onReload);

    void reset(std::vector<DeviceProfile>& profiles,
               std::function<bool()>        isReloading,
               const std::function<void()>& onDirty,
               const std::function<void()>& onReload);

    [[nodiscard]] bool isReloading() const;

    void onCardClicked(int index);
    [[nodiscard]] PopupData onLogClicked(int index);
    [[nodiscard]] PopupData onXmlClicked(int index);
    void onReloadClicked();

    [[nodiscard]] const std::vector<DeviceProfile>& profiles() const;

private:
    std::vector<DeviceProfile>* m_profiles   = nullptr;
    std::function<bool()>       m_isReloading;
    std::function<void()>       m_onDirty;
    std::function<void()>       m_onReload;
};
