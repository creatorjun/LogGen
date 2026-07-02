// src/persistence/DefaultProfileFactory.cpp
#include "DefaultProfileFactory.h"
#include "core/LogFormatUtils.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <algorithm>

using json = nlohmann::json;
namespace fs = std::filesystem;

std::vector<DeviceProfile>
DefaultProfileFactory::buildFromDirectory(const std::string& dirPath) {
    std::vector<DeviceProfile> profiles;

    if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
        LOG_WARN("FACTORY", "Template directory not found: " + dirPath);
        return profiles;
    }

    std::vector<fs::path> jsonFiles;
    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (!entry.is_regular_file()) continue;
        if (entry.path().extension().string() == ".json")
            jsonFiles.push_back(entry.path());
    }
    std::sort(jsonFiles.begin(), jsonFiles.end());

    int idx = 1;
    for (const auto& path : jsonFiles) {
        std::string deviceName = path.stem().string();
        std::string vendor;
        LogFormat   format = LogFormat::PLAIN;
        std::string formatRaw;
        std::string xmlRaw;
        std::vector<EventScenario> scenarios;

        try {
            std::ifstream f(path);
            if (!f.is_open()) {
                LOG_WARN("FACTORY", "Cannot open template file: " + path.string());
                continue;
            }
            json root = json::parse(f);

            deviceName = root.value("device", deviceName);
            vendor     = root.value("vendor", std::string(""));

            if (!root.contains("format") || !root["format"].contains("raw")) {
                LOG_WARN("FACTORY", "Skipping template (missing format.raw): " + path.string());
                continue;
            }

            // format.type 서로 포맷 종류를 읽는다. 없으면 PLAIN
            const std::string fmtType = root["format"].value("type", std::string("PLAIN"));
            format    = LogFormatUtils::fromString(fmtType);
            formatRaw = root["format"]["raw"].get<std::string>();

            if (root.contains("xml") && root["xml"].contains("raw"))
                xmlRaw = root["xml"]["raw"].get<std::string>();

            if (root.contains("scenarios") && root["scenarios"].is_array()) {
                for (const auto& s : root["scenarios"]) {
                    EventScenario es;
                    es.attackName = s.value("attackName", std::string("Normal_Traffic"));
                    es.weight     = s.value("weight", 10);
                    scenarios.push_back(std::move(es));
                }
            }
        } catch (const json::exception& e) {
            LOG_WARN("FACTORY", "JSON parse error, skipping: " + path.string() + ": " + e.what());
            continue;
        }

        DeviceProfile p;
        p.id              = "DEV-" + std::to_string(idx++);
        p.deviceName      = deviceName;
        p.vendor          = vendor;
        p.templateFile    = (fs::path(dirPath) / path.filename()).string();
        p.enabled         = false;
        p.format          = format;
        p.formatRaw       = std::move(formatRaw);
        p.xmlRaw          = std::move(xmlRaw);
        p.event.scenarios = std::move(scenarios);
        profiles.push_back(std::move(p));
    }

    LOG_INFO("FACTORY", "Auto-discovered " + std::to_string(profiles.size())
        + " device profiles from: " + dirPath);
    return profiles;
}

std::vector<DeviceProfile> DefaultProfileFactory::build() {
    return buildFromDirectory("templates");
}
