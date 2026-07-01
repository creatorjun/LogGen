// src/ui/viewmodel/MonitorPanelViewModel.cpp
#include "MonitorPanelViewModel.h"
#include "logging/Logger.h"
#include <algorithm>

MonitorPanelViewModel::MonitorPanelViewModel(
    IGeneratorEngine& engine,
    std::vector<DeviceProfile>& profiles,
    LogBuffer& logBuffer,
    AppViewModel& appViewModel)
    : m_engine(engine)
    , m_profiles(profiles)
    , m_logBuffer(logBuffer)
    , m_appViewModel(appViewModel)
{}

// m_dateSign: true = 미래(+), false = 과거(-)
// 실제 전달값: 양수(오늘 + days) 또는 음수(오늘 - days)
void MonitorPanelViewModel::applyDateOffset() {
    const int sign   = m_dateSign ? 1 : -1;
    const int offset = sign * m_dateDays;
    m_appViewModel.setDateOffsetDays(offset);
}

void MonitorPanelViewModel::setDateSign(bool positive) {
    m_dateSign = positive;
    applyDateOffset();
}

void MonitorPanelViewModel::setDateDays(int days) {
    m_dateDays = days;
    applyDateOffset();
}

void MonitorPanelViewModel::tick(float deltaTime, bool engineRunning) {
    if (m_isRunning && !engineRunning && m_engineWasRunning) {
        m_isRunning = false;
    }

    const bool stoppedThisFrame = (m_engineWasRunning && !engineRunning);
    m_engineWasRunning = engineRunning;

    if (engineRunning) {
        tickEps(deltaTime);
    } else {
        m_cachedTotalEps = 0.0f;
    }
    tickLogPoll();
    tickTotalSent(stoppedThisFrame);
}

void MonitorPanelViewModel::tickEps(float deltaTime) {
    m_time += deltaTime;
    float total = 0.0f;
    for (const auto& p : m_profiles) {
        if (!p.enabled) continue;
        float rate = m_engine.getCurrentRateByDevice(p.id);
        m_deviceEpsData[p.id].AddPoint(m_time, rate);
        total += rate;
    }
    m_totalEpsData.AddPoint(m_time, total);
    m_cachedTotalEps = total;
}

void MonitorPanelViewModel::tickLogPoll() {
    const long long pollMs = (m_cachedTotalEps < kEpsHighThreshold)
        ? kIntervalLowMs : kIntervalHighMs;
    const auto now     = std::chrono::steady_clock::now();
    const auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
        now - m_lastLogPollTime).count();
    if (elapsed < pollMs) return;

    const uint64_t ver = m_logBuffer.getVersion();
    if (ver != m_lastVersion) {
        auto newLogs = m_logBuffer.getNewLogs(m_logOffset);
        if (!newLogs.empty()) {
            for (const auto& log : newLogs) {
                std::string line;
                line.reserve(log.deviceName.size() + log.rawLog.size() + 4);
                line += '[';
                line += log.deviceName;
                line += "] ";
                line += log.rawLog;
                m_terminalLines.push_back(std::move(line));
                m_terminalSelected.push_back(false);
            }
            while (m_terminalLines.size() > kMaxTerminalLines) {
                m_terminalLines.pop_front();
                m_terminalSelected.pop_front();
                if (m_lastClickedLine > 0) --m_lastClickedLine;
                else                       m_lastClickedLine = -1;
            }
            m_scrollToBottom = true;
        }
        if (m_logBuffer.getTotalPushed() == 0 && !m_terminalLines.empty()) {
            m_terminalLines.clear();
            m_terminalSelected.clear();
            m_lastClickedLine = -1;
            m_logOffset       = 0;
            LOG_DEBUG("UI", "Terminal buffer cleared");
        }
        m_lastVersion = ver;
    }
    m_lastLogPollTime = now;
}

void MonitorPanelViewModel::tickTotalSent(bool forceUpdate) {
    const auto   now        = std::chrono::steady_clock::now();
    const double elapsedSec = std::chrono::duration_cast<std::chrono::duration<double>>(
        now - m_lastTotalSentTime).count();
    const bool needUpdate = forceUpdate
        || (m_cachedTotalEps < kEpsHighThreshold)
        || (elapsedSec >= 0.5)
        || (m_lastTotalSentTime == std::chrono::steady_clock::time_point{});
    if (needUpdate) {
        m_displayedTotalSent = m_engine.getTotalSent();
        m_lastTotalSentTime  = now;
    }
}

bool     MonitorPanelViewModel::isRunning()          const { return m_isRunning; }
float    MonitorPanelViewModel::cachedTotalEps()     const { return m_cachedTotalEps; }
uint64_t MonitorPanelViewModel::displayedTotalSent() const { return m_displayedTotalSent; }
float    MonitorPanelViewModel::chartTime()          const { return m_time; }

const TimeSeriesData& MonitorPanelViewModel::totalEpsData() const { return m_totalEpsData; }
const std::unordered_map<std::string, TimeSeriesData>& MonitorPanelViewModel::deviceEpsData() const {
    return m_deviceEpsData;
}

const std::deque<std::string>& MonitorPanelViewModel::terminalLines()    const { return m_terminalLines; }
const std::deque<bool>&        MonitorPanelViewModel::terminalSelected() const { return m_terminalSelected; }
std::deque<bool>&              MonitorPanelViewModel::terminalSelected()       { return m_terminalSelected; }
int                            MonitorPanelViewModel::lastClickedLine()  const { return m_lastClickedLine; }
void                           MonitorPanelViewModel::setLastClickedLine(int v) { m_lastClickedLine = v; }
bool                           MonitorPanelViewModel::scrollToBottom()   const { return m_scrollToBottom; }
void                           MonitorPanelViewModel::clearScrollFlag()        { m_scrollToBottom = false; }

void MonitorPanelViewModel::onStartClicked() {
    // START 직전 현재 설정된 날짜 오프셋을 AppViewModel → 엔진에 전달
    applyDateOffset();
    m_isRunning = true;
    if (!m_chartEverStarted) {
        m_time = 0.0f;
        m_totalEpsData.Erase();
        for (auto& [k, d] : m_deviceEpsData) d.Erase();
        m_chartEverStarted = true;
    }
    LOG_INFO("UI", "START button clicked - date offset applied (sign="
             + std::string(m_dateSign ? "+" : "-")
             + ", days=" + std::to_string(m_dateDays) + ")");
}

void MonitorPanelViewModel::onStopClicked() {
    m_isRunning = false;
    LOG_INFO("UI", "STOP button clicked - engine stop requested");
}

void MonitorPanelViewModel::clearTerminal() {
    m_terminalLines.clear();
    m_terminalSelected.clear();
    m_lastClickedLine = -1;
    m_logOffset       = 0;
    m_lastVersion     = UINT64_MAX;
}

void MonitorPanelViewModel::copySelectedLines(const ClipboardFn& setClipboard) const {
    std::string buf;
    buf.reserve(m_terminalLines.size() * 80);
    const size_t total = m_terminalLines.size();
    for (size_t i = 0; i < total; ++i) {
        if (i < m_terminalSelected.size() && m_terminalSelected[i]) {
            buf += m_terminalLines[i];
            buf += '\n';
        }
    }
    if (!buf.empty())
        setClipboard(buf);
}
