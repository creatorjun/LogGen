// src/engine/GeneratorEngine.h
#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <memory>
#include <atomic>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <flat_map>
#include <flat_set>
#include <expected>
#include <ranges>
#include "engine/IGeneratorEngine.h"
#include "engine/LogDispatchQueue.h"
#include "engine/TIPool.h"
#include "engine/WorkerContext.h"
#include "engine/WorkerAllocationStrategy.h"
#include "core/Constants.h"

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
    bool         loadTIPool(const std::string& csvPath)                            override;
    [[nodiscard]] uint64_t getTotalSent() const                                    override;
    [[nodiscard]] uint64_t getSentByDevice(const std::string& deviceId) const      override;
    [[nodiscard]] float    getCurrentRateByDevice(const std::string& deviceId) const override;
    [[nodiscard]] bool     isRunning() const override { return m_running.load(std::memory_order_acquire); }

private:
    enum class RefreshState {
        kNoChange,
        kUpdated,
        kConnectionChanged,
    };
    using RefreshResult = std::expected<RefreshState, std::string>;

    void workerLoop(const std::string& profileId, int workerIndex, int totalWorkers);
    void dispatcherLoop();
    void pushWorkerError(std::string_view deviceId,
                         std::string_view deviceName,
                         std::string_view message);

    void spawnWorkers(const std::string& profileId, int count);

    [[nodiscard]] RefreshResult
        refreshProfile(WorkerContext& ctx);

    void buildBatch(WorkerContext& ctx,
                    size_t        batchSize,
                    uint64_t      nowMs);

    [[nodiscard]] uint64_t
        sendAndDispatch(WorkerContext& ctx, size_t batchSize);

    void updateRateStats(WorkerContext& ctx, uint64_t sentCount);

    bool runTokenBatchPath(WorkerContext& ctx,
                           size_t         maxBatch,
                           uint64_t       nowMs,
                           bool           isFastPath);

    static std::string workerKey(const std::string& profileId, int workerIndex) {
        return profileId + ':' + std::to_string(workerIndex);
    }

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
    std::flat_map<std::string, int>                                            m_profileWorkerCount;
    std::atomic<uint64_t>                                                      m_totalSentCount{0};
    std::flat_set<std::string>                                                 m_activeWorkers;

    std::atomic<int> m_dateOffsetDays{0};
    TIPool           m_tiPool;
};
