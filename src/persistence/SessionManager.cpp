// src/persistence/SessionManager.cpp
#include "persistence/SessionManager.h"
#include "core/LogFormatUtils.h"
#include <fstream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "logging/Logger.h"

using json = nlohmann::json;

SessionManager::SessionManager(const std::string& sessionFile)
    : m_sessionFile(sessionFile) {}

bool SessionManager::loadSession(std::vector<DeviceProfile>& profiles) {
    std::ifstream in(m_sessionFile);
    if (!in.is_open()) {
        LOG_WARN("SESSION", "Session file open failed: " + m_sessionFile);
        return false;
    }

    try {
        json root;
        in >> root;
        profiles.clear();

        if (!root.is_array()) {
            LOG_ERROR("SESSION", "Session file format invalid (root is not array): " + m_sessionFile);
            return false;
        }

        for (const auto& item : root) {
            DeviceProfile p;
            p.id           = item.value("id",           std::string(""));
            p.deviceName   = item.value("deviceName",   std::string("Device"));
            p.vendor       = item.value("vendor",       std::string(""));
            p.enabled      = item.value("enabled",      true);
            p.eqpIp        = item.value("eqpIp",        std::string("127.0.0.1"));
            p.templateFile = item.value("templateFile", std::string(""));
            p.format       = LogFormatUtils::fromString(item.value("format", std::string("PLAIN")));
            p.formatRaw    = item.value("formatRaw",    std::string(""));
            p.xmlRaw       = item.value("xmlRaw",       std::string(""));

            if (item.contains("collector")) {
                p.collector.ip     = item["collector"].value("ip",     std::string("127.0.0.1"));
                p.collector.port   = static_cast<uint16_t>(item["collector"].value("port", 514));
                p.collector.useTCP = item["collector"].value("useTCP", false);
            }

            if (item.contains("scheduler")) {
                const std::string rateModeStr    = item["scheduler"].value("rateMode", std::string("EPM"));
                p.scheduler.rateMode             = (rateModeStr == "EPS") ? RateMode::EPS : RateMode::EPM;
                p.scheduler.normalRate           = static_cast<float>(item["scheduler"].value("normalRate",       1.0));
                p.scheduler.burstEnable          = item["scheduler"].value("burstEnable", false);
                p.scheduler.burstRate            = static_cast<float>(item["scheduler"].value("burstRate",        10.0));
                p.scheduler.burstDurationSec     = static_cast<float>(item["scheduler"].value("burstDurationSec",  5.0));
                p.scheduler.burstIntervalSec     = static_cast<float>(item["scheduler"].value("burstIntervalSec", 30.0));
            }

            if (item.contains("event")) {
                p.event.srcIp       = item["event"].value("srcIp",       std::string("10.0.0.1"));
                p.event.srcIpRandom = item["event"].value("srcIpRandom", false);
                p.event.srcIpStart  = item["event"].value("srcIpStart",  std::string("10.0.0.1"));
                p.event.srcIpEnd    = item["event"].value("srcIpEnd",    std::string("10.0.255.255"));
                p.event.dstIpFixed  = item["event"].value("dstIpFixed",  std::string("192.168.1.1"));
                p.event.dstIpRandom = item["event"].value("dstIpRandom", false);
                p.event.dstIpStart  = item["event"].value("dstIpStart",  std::string("192.168.0.1"));
                p.event.dstIpEnd    = item["event"].value("dstIpEnd",    std::string("192.168.255.255"));
                p.event.allowPct    = item["event"].value("allowPct", 80);

                if (item["event"].contains("scenarios")) {
                    for (const auto& s : item["event"]["scenarios"]) {
                        EventScenario es;
                        es.attackName = s.value("attackName", std::string("Normal_Traffic"));
                        es.weight     = s.value("weight", 10);
                        p.event.scenarios.push_back(std::move(es));
                    }
                }
            }

            profiles.push_back(std::move(p));
        }

        LOG_INFO("SESSION", "Session loaded successfully from " + m_sessionFile
            + ", count=" + std::to_string(profiles.size()));
        return true;
    } catch (const std::exception& ex) {
        LOG_ERROR("SESSION", std::string("Session load failed: ") + ex.what());
        return false;
    }
}

bool SessionManager::saveSession(const std::vector<DeviceProfile>& profiles) {
    try {
        const auto parentDir = std::filesystem::path(m_sessionFile).parent_path();
        if (!parentDir.empty() && !std::filesystem::exists(parentDir)) {
            std::error_code ec;
            std::filesystem::create_directories(parentDir, ec);
            if (ec) {
                LOG_ERROR("SESSION", "Failed to create directory: " + parentDir.string()
                    + " - " + ec.message());
                return false;
            }
            LOG_INFO("SESSION", "Created directory: " + parentDir.string());
        }

        json root = json::array();
        for (const auto& p : profiles) {
            json scenariosArr = json::array();
            for (const auto& s : p.event.scenarios) {
                scenariosArr.push_back({
                    {"attackName", s.attackName},
                    {"weight",     s.weight}
                });
            }

            root.push_back({
                {"id",           p.id},
                {"deviceName",   p.deviceName},
                {"vendor",       p.vendor},
                {"enabled",      p.enabled},
                {"eqpIp",        p.eqpIp},
                {"templateFile", p.templateFile},
                {"format",       LogFormatUtils::toString(p.format)},
                {"formatRaw",    p.formatRaw},
                {"xmlRaw",       p.xmlRaw},
                {"collector", {
                    {"ip",     p.collector.ip},
                    {"port",   p.collector.port},
                    {"useTCP", p.collector.useTCP}
                }},
                {"scheduler", {
                    {"rateMode",         (p.scheduler.rateMode == RateMode::EPS) ? "EPS" : "EPM"},
                    {"normalRate",       p.scheduler.normalRate},
                    {"burstEnable",      p.scheduler.burstEnable},
                    {"burstRate",        p.scheduler.burstRate},
                    {"burstDurationSec", p.scheduler.burstDurationSec},
                    {"burstIntervalSec", p.scheduler.burstIntervalSec}
                }},
                {"event", {
                    {"srcIp",       p.event.srcIp},
                    {"srcIpRandom", p.event.srcIpRandom},
                    {"srcIpStart",  p.event.srcIpStart},
                    {"srcIpEnd",    p.event.srcIpEnd},
                    {"dstIpFixed",  p.event.dstIpFixed},
                    {"dstIpRandom", p.event.dstIpRandom},
                    {"dstIpStart",  p.event.dstIpStart},
                    {"dstIpEnd",    p.event.dstIpEnd},
                    {"allowPct",    p.event.allowPct},
                    {"scenarios",   scenariosArr}
                }}
            });
        }

        std::ofstream out(m_sessionFile);
        if (!out.is_open()) {
            LOG_ERROR("SESSION", "Session file write open failed: " + m_sessionFile);
            return false;
        }

        out << root.dump(2);
        LOG_INFO("SESSION", "Session saved successfully to " + m_sessionFile
            + ", count=" + std::to_string(profiles.size()));
        return true;
    } catch (const std::exception& ex) {
        LOG_ERROR("SESSION", std::string("Session save failed: ") + ex.what());
        return false;
    }
}
