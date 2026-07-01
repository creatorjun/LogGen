// src/ui/viewmodel/MonitorPanelViewModel.h
#pragma once

#include <deque>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <chrono>
#include <cstdint>
#include "core/DeviceProfile.h"
#include "engine/IGeneratorEngine.h"
#include "core/channel/LogBuffer.h"
#include "ui/viewmodel/TimeSeriesData.h"
#include "ui/viewmodel/AppViewModel.h"

class MonitorPanelViewModel {
public:
    static constexpr size_t    kMaxTerminalLines = 2000;
    static constexpr float     kEpsHighThreshold = 60.0f;
    static constexpr long long kIntervalLowMs    = 16;
    static constexpr long long kIntervalHighMs   = 500;

    MonitorPanelViewModel(IGeneratorEngine&           engine,
                          std::vector<DeviceProfile>& profiles,
                          LogBuffer&                  logBuffer,
                          AppViewModel&               appViewModel);

    void tick(float deltaTime, bool engineRunning);

    [[nodiscard]] bool     isRunning()          const;
    [[nodiscard]] float    cachedTotalEps()     const;
    [[nodiscard]] uint64_t displayedTotalSent() const;

    [[nodiscard]] const TimeSeriesData&                                  totalEpsData()  const;
    [[nodiscard]] const std::unordered_map<std::string, TimeSeriesData>& deviceEpsData() const;
    [[nodiscard]] float                                                  chartTime()     const;

    [[nodiscard]] const std::deque<std::string>& terminalLines()    const;
    [[nodiscard]] const std::deque<bool>&        terminalSelected() const;
    std::deque<bool>&                            terminalSelected();
    [[nodiscard]] int                            lastClickedLine()  const;
    void                                         setLastClickedLine(int v);
    [[nodiscard]] bool                           scrollToBottom()   const;
    void                                         clearScrollFlag();

    [[nodiscard]] bool dateSign() const { return m_dateSign; }
    [[nodiscard]] int  dateDays() const { return m_dateDays; }
    void setDateSign(bool positive);
    void setDateDays(int days);

    void onStartClicked();
    void onStopClicked();
    void clearTerminal();

    using ClipboardFn = std::function<void(const std::string&)>;
    void copySelectedLines(const ClipboardFn& setClipboard) const;

    std::vector<float> tmpXs;
    std::vector<float> tmpYs;

private:
    IGeneratorEngine&           m_engine;
    std::vector<DeviceProfile>& m_profiles;
    LogBuffer&                  m_logBuffer;
    AppViewModel&               m_appViewModel;

    bool     m_isRunning        = false;
    bool     m_engineWasRunning = false;
    float    m_time             = 0.0f;
    bool     m_chartEverStarted = false;
    float    m_cachedTotalEps   = 0.0f;

    bool     m_dateSign = false;
    int      m_dateDays = 0;

    TimeSeriesData                                  m_totalEpsData;
    std::unordered_map<std::string, TimeSeriesData> m_deviceEpsData;

    std::deque<std::string> m_terminalLines;
    std::deque<bool>        m_terminalSelected;
    int                     m_lastClickedLine = -1;
    bool                    m_scrollToBottom  = false;
    uint64_t                m_logOffset       = 0;
    uint64_t                m_lastVersion     = UINT64_MAX;

    std::chrono::steady_clock::time_point m_lastLogPollTime{};
    uint64_t                              m_displayedTotalSent = 0;
    std::chrono::steady_clock::time_point m_lastTotalSentTime{};

    void applyDateOffset();
    void tickEps(float deltaTime);
    void tickLogPoll();
    void tickTotalSent(bool forceUpdate = false);
};
