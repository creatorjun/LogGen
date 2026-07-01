// src/engine/VirusTotalRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <mutex>
#include "core/ApiTypes.h"
#include "engine/ISubRouter.h"

class VirusTotalRouter : public ISubRouter {
public:
    VirusTotalRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    static bool        isValidApiKey(const std::string& key);
    static std::string makeAnalysisId();
    static std::string nowIso8601();
    static std::string sha256Mock(const std::string& input);

    bool isAuthenticated(const ApiRequest& req) const;

    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);

    ApiResponse handleFileReport(const ApiRequest& req);
    ApiResponse handleFileUpload(const ApiRequest& req);
    ApiResponse handleFileRescan(const ApiRequest& req);

    ApiResponse handleUrlScan(const ApiRequest& req);
    ApiResponse handleUrlReport(const ApiRequest& req);

    ApiResponse handleIpReport(const ApiRequest& req);
    ApiResponse handleDomainReport(const ApiRequest& req);

    ApiResponse handleAnalysisGet(const ApiRequest& req);

    struct AnalysisEntry {
        std::string id;
        std::string type;
        std::string target;
        std::string status;
        int         malicious   = 0;
        int         suspicious  = 0;
        int         undetected  = 0;
        int         harmless    = 0;
        int         total       = 72;
        std::string sha256;
        std::string submittedAt;
    };

    mutable std::mutex                                  m_mutex;
    std::unordered_map<std::string, AnalysisEntry>      m_analyses;
    std::unordered_map<std::string, std::string>        m_urlToId;
    std::unordered_map<std::string, std::string>        m_hashToId;
};
