// src/engine/VirusTotalRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <mutex>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class VirusTotalRouter : public ISubRouter {
public:
    VirusTotalRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    ApiResponse handleFilesReport(const ApiRequest& req);
    ApiResponse handleUrlsReport(const ApiRequest& req);
    ApiResponse handleDomainsReport(const ApiRequest& req);
    ApiResponse handleIpReport(const ApiRequest& req);
    ApiResponse handleCommentCreate(const ApiRequest& req);
    ApiResponse handleNotFound(const ApiRequest& req);

    mutable std::mutex m_mutex;
    std::unordered_map<std::string, std::string> m_cache;
};
