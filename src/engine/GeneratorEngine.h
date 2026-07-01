// src/engine/GeneratorEngine.h
#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
#include <flat_map>
#include <flat_set>
#include <expected>
#include <ranges>
#include "engine/IGeneratorEngine.h"
#include "engine/LogDispatchQueue.h"
#include "engine/TIPool.h"
#include "core/Constants.h"

class ISender;
class UDPSender;
class FieldGenerator;
class ScenarioSelector;
class LogTemplateEngine;

class GeneratorEngine : public IGeneratorEngine {
public:
    explicit GeneratorEngine(
        int    threadPoolSize = Constants::Engine::kDefaultThreadPoolSize,
        size_t queueCapacity  = Constants::Engine::kDefaultQueueCapacity);
    ~GeneratorEngine() override;

    void         setLogCallback(LogCallback cb)                                    override;
    void         start(const std::vector<DeviceProfile>& profiles)                 override;
    void         stop()                                                            override;
    void         updateProfile(const DeviceProfile& profile)                       override;
    void         setDateOffsetDays(int days)                                       override;
    [[nodiscard]] uint64_t getTotalSent() const                                    override;
    [[nodiscard]] uint64_t getSentByDevice(const std::string& deviceId) const      override;
    [[nodiscard]] float    getCurrentRateByDevice(const std::string& deviceId) const override;
    [[nodiscard]] bool     isRunning() const override { return m_running.load(std::memory_order_acquire); }

    [[nodiscard]] bool loadTIPool(const std::string& csvPath) { return m_tiPool.loadFromCSV(csvPath); }

private:
    enum class RefreshState {
        kNoChange,
        kUpdated,
        kConnectionChanged,
    };
    using RefreshResult = std::expected<RefreshState, std::string>;

    void workerLoop(const std::string& profileId);
    void dispatcherLoop();
    void pushWorkerError(std::string_view deviceId,
                         std::string_view deviceName,
                         std::string_view message);

    [[nodiscard]] std::expected<void, std::string>
        initWorkerSender(const DeviceProfile& p,
                         std::unique_ptr<ISender>& senderBase,
                         UDPSender*& udpSender);

    [[nodiscard]] RefreshResult
        refreshProfile(const std::string&        profileId,
                       uint64_t&                 knownVersion,
                       DeviceProfile&            p,
                       std::unique_ptr<ISender>& senderBase,
                       UDPSender*&               udpSender,
                       int&                      consecutiveFails,
                       LogTemplateEngine&        templateEngine,
                       FieldGenerator&           fieldGen,
                       ScenarioSelector&         scenarioSelector,
                       std::flat_map<std::string, std::string>& tokens,
                       bool&                     prevBurstEnable,
                       bool&                     inBurstMode,
                       std::chrono::steady_clock::time_point& burstStartTime);

    void updateBurstState(const DeviceProfile& p,
                          bool& inBurstMode,
                          std::chrono::steady_clock::time_point& burstStartTime,
                          const std::chrono::steady_clock::time_point& now);

    void buildBatch(const DeviceProfile& p,
                    FieldGenerator&      fieldGen,
                    ScenarioSelector&    scenarioSelector,
                    LogTemplateEngine&   templateEngine,
                    std::flat_map<std::string, std::string>& tokens,
                    size_t               batchSize,
                    uint64_t             nowMs,
                    std::vector<std::string>& sendBuf,
                    std::vector<LogEntry>&    dispatchBuf,
                    char* srcPortBuf, char* dstPortBuf,
                    char* pktBuf,     char* byteBuf);

    [[nodiscard]] uint64_t
        sendAndDispatch(const DeviceProfile& p,
                        std::unique_ptr<ISender>& senderBase,
                        UDPSender*               udpSender,
                        int&                     consecutiveFails,
                        std::chrono::steady_clock::time_point& lastReconnectAttempt,
                        size_t                   batchSize,
                        const std::vector<std::string>& sendBuf,
                        const std::vector<LogEntry>&    dispatchBuf);

    void updateRateStats(uint64_t                sentCount,
                         uint64_t&               logsSentInThisInterval,
                         std::chrono::steady_clock::time_point& lastRateCalcTime,
                         std::atomic<uint32_t>*  devRateFixed);

    int                               m_poolSize;
    std::unique_ptr<class ThreadPool> m_threadPool;
    std::atomic<bool>                 m_running{false};

    LogCallback      m_callback;
    LogDispatchQueue m_dispatchQueue;
    std::thread      m_dispatcherThread;

    mutable std::shared_mutex                                                  m_statsMutex;
    std::atomic<uint64_t>                                                      m_profileVersion{0};
    std::flat_map<std::string, DeviceProfile>                                  m_profileMap;
    std::flat_map<std::string, std::unique_ptr<std::atomic<uint64_t>>>         m_deviceCounters;
    std::flat_map<std::string, std::unique_ptr<std::atomic<uint32_t>>>         m_deviceRatesFixed;
    std::atomic<uint64_t>                                                      m_totalSentCount{0};
    std::flat_set<std::string>                                                 m_activeWorkers;

    std::atomic<int> m_dateOffsetDays{0};
    TIPool           m_tiPool;
};
