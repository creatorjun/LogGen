// src/engine/ApiRouter.h
#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "core/interfaces/IApiRouter.h"
#include "core/interfaces/ISubRouter.h"

class ApiRouter : public IApiRouter {
public:
    struct PrefixEntry {
        std::string prefix;
        ISubRouter* router;
    };

    explicit ApiRouter(std::vector<std::unique_ptr<ISubRouter>> subRouters,
                       std::vector<PrefixEntry>                 prefixMap);
    ~ApiRouter() override;

    ApiResponse route(const ApiRequest& req) override;

private:
    struct RouteEntry {
        using Handler = std::function<ApiResponse(const ApiRequest&)>;
        Handler handler;
    };

    void addExact(const std::string& method, const std::string& path,
                  RouteEntry::Handler handler);

    ApiResponse handleHealth(const ApiRequest& req);
    ApiResponse handleAlerts(const ApiRequest& req);
    ApiResponse handleGetAlert(const ApiRequest& req);
    ApiResponse handleUpdateAlert(const ApiRequest& req);
    ApiResponse handleGetCases(const ApiRequest& req);
    ApiResponse handleCreateCase(const ApiRequest& req);

    std::vector<std::unique_ptr<ISubRouter>>         m_subRouters;
    std::vector<std::pair<std::string, ISubRouter*>> m_prefixRoutes;
    std::unordered_map<std::string, RouteEntry>      m_exactRoutes;
};
