// src/engine/WorkerContext.h
#pragma once
#include <atomic>
#include <chrono>
#include <flat_map>
#include <string>
#include <vector>
#include "engine/ConnectionManager.h"
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

    ConnectionManager        connMgr;

    LogTemplateEngine        templateEngine;
    FieldGenerator           fieldGen;
    ScenarioSelector         scenarioSelector;
    RateController           rateCtrl;

    std::flat_map<std::string, std::string> tokens;

    std::atomic<uint64_t>*   devCounter{};
    std::atomic<uint32_t>*   devRateFixed{};

    std::chrono::steady_clock::time_point lastRateCalcTime{};

    uint64_t logsSentInThisInterval{};

    char srcPortBuf[8]{};
    char dstPortBuf[8]{};
    char pktBuf[8]{};
    char byteBuf[8]{};

    std::vector<std::string> sendBuf;
    std::vector<LogEntry>    dispatchBuf;
};
