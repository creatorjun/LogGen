// src/ui/viewmodel/EventPanelViewModel.h
#pragma once

#include <vector>
#include <functional>
#include "core/DeviceProfile.h"

class EventPanelViewModel {
public:
    static constexpr uint16_t kDefaultUDPPort   = 514;
    static constexpr uint16_t kDefaultTCPPort   = 9040;
    static constexpr int      kMinEps           = 1;
    static constexpr int      kMaxEps           = 1000000;
    static constexpr int      kMinBurstEps      = 1;
    static constexpr int      kMaxBurstEps      = 1000000;
    static constexpr float    kMinBurstDuration = 1.0f;
    static constexpr float    kMaxBurstDuration = 60.0f;
    static constexpr float    kMinBurstInterval = 5.0f;
    static constexpr float    kMaxBurstInterval = 300.0f;

    struct IpBlockBinding {
        bool&        randomFlag;
        std::string& fixedIp;
        std::string& startIp;
        std::string& endIp;
    };

    EventPanelViewModel() = default;

    explicit EventPanelViewModel(std::vector<DeviceProfile>& profiles,
                                 const std::function<void()>& onDirty);

    void reset(std::vector<DeviceProfile>& profiles,
               const std::function<void()>& onDirty);

    [[nodiscard]] bool hasNoDevice()   const;
    [[nodiscard]] bool hasNoEnabled()  const;
    [[nodiscard]] bool isMultiSelect() const;
    [[nodiscard]] int  targetCount()   const;

    [[nodiscard]] DeviceProfile*              singleTarget();
    [[nodiscard]] std::vector<DeviceProfile*> targets();

    void onEqpIpChanged(const std::string& val);
    void onCollectorIpChanged(const std::string& val);
    void onPortChanged(int port);
    void onProtocolUDP();
    void onProtocolTCP();
    void onNormalRateChanged(int eps);
    void onBurstEnableChanged(bool val);
    void onBurstRateChanged(int eps);
    void onBurstDurationChanged(float sec);
    void onBurstIntervalChanged(float sec);

    void onSrcIpRandomChanged(bool val);
    void onSrcIpFixedChanged(const std::string& val);
    void onSrcIpStartChanged(const std::string& val);
    void onSrcIpEndChanged(const std::string& val);

    void onDstIpRandomChanged(bool val);
    void onDstIpFixedChanged(const std::string& val);
    void onDstIpStartChanged(const std::string& val);
    void onDstIpEndChanged(const std::string& val);

private:
    std::vector<DeviceProfile>*  m_profiles = nullptr;
    std::function<void()>        m_onDirty;
    std::vector<DeviceProfile*>  m_targets;

    void rebuildTargets();
    void dirty(const std::string& tag, const std::string& val);
};
