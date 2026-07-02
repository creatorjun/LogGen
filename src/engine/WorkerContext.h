// src/engine/WorkerContext.h
#pragma once
#include <memory>
#include <atomic>
#include <chrono>
#include <flat_map>
#include <string>
#include <vector>
#include "engine/ISender.h"
#include "engine/UDPSender.h"
#include "engine/FieldGenerator.h"
#include "engine/LogTemplateEngine.h"
#include "engine/ScenarioSelector.h"
#include "engine/RateController.h"
#include "core/DeviceProfile.h"
#include "core/LogEntry.h"

struct WorkerContext {
    std::string              profileId;
    int                      workerIndex{};
    int                      totalWorkers{1};

    DeviceProfile            profile;
    uint64_t                 knownVersion{};

    std::unique_ptr<ISender> sender;
    UDPSender*               udpSender{};

    LogTemplateEngine        templateEngine;
    FieldGenerator           fieldGen;
    ScenarioSelector         scenarioSelector;
    RateController           rateCtrl;

    std::flat_map<std::string, std::string> tokens;

    std::atomic<uint64_t>*   devCounter{};
    std::atomic<uint32_t>*   devRateFixed{};

    std::chrono::steady_clock::time_point lastRateCalcTime{};
    std::chrono::steady_clock::time_point lastReconnectAttempt{};

    uint64_t logsSentInThisInterval{};
    int      consecutiveFails{};

    char srcPortBuf[8]{};
    char dstPortBuf[8]{};
    char pktBuf[8]{};
    char byteBuf[8]{};

    std::vector<std::string> sendBuf;
    std::vector<LogEntry>    dispatchBuf;
};
