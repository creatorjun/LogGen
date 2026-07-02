// src/core/DeviceProfile.h
#pragma once

#include "core/LogFormat.h"
#include <string>
#include <vector>
#include <cstdint>

enum class RateMode {
    EPS,
    EPM
};

struct CollectorTarget {
    std::string ip     = "127.0.0.1";
    uint16_t    port   = 514;
    bool        useTCP = false;
};

struct SchedulerConfig {
    RateMode rateMode         = RateMode::EPS;
    float    normalRate       = 1.0f;
    bool     burstEnable      = false;
    float    burstRate        = 10.0f;
    float    burstDurationSec = 5.0f;
    float    burstIntervalSec = 30.0f;

    [[nodiscard]] float normalRateToEps() const {
        return (rateMode == RateMode::EPM) ? normalRate / 60.0f : normalRate;
    }
    [[nodiscard]] float burstRateToEps() const {
        return (rateMode == RateMode::EPM) ? burstRate / 60.0f : burstRate;
    }
};

struct EventScenario {
    std::string attackName;
    int         weight = 10;
};

struct EventConfig {
    std::string           srcIp       = "10.0.0.1";
    std::string           dstIp       = "192.168.1.1";
    std::string           srcIpStart  = "10.0.0.1";
    std::string           srcIpEnd    = "10.0.255.255";
    std::string           dstIpFixed  = "192.168.1.1";
    std::string           dstIpStart  = "192.168.0.1";
    std::string           dstIpEnd    = "192.168.255.255";
    bool                  srcIpRandom = false;
    bool                  dstIpRandom = false;
    std::vector<uint16_t> dstPorts    = {80, 443, 22};
    std::string           protocol    = "TCP";
    int                   allowPct    = 70;
    bool                  useTIPool   = false;
    std::vector<EventScenario> scenarios;
};

struct DeviceProfile {
    std::string     id;
    std::string     templateFile;
    std::string     deviceName;
    std::string     vendor;
    std::string     eqpIp     = "192.168.0.1";
    bool            enabled   = false;
    LogFormat       format    = LogFormat::PLAIN;
    std::string     formatRaw;
    std::string     xmlRaw;
    CollectorTarget collector;
    SchedulerConfig scheduler;
    EventConfig     event;
};
