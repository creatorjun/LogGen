// src/engine/ApiRouter.h
#pragma once

#include <memory>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "engine/IApiRouter.h"
#include "engine/ISubRouter.h"

class NexGfwRouter;
class VirusTotalRouter;
class SpamhausRouter;
class SecuiRouter;
class FortinetRouter;
class Mf2Router;
class WinsTaxiiRouter;

class ApiRouter : public IApiRouter {
public:
    ApiRouter();
    ~ApiRouter() override;

    ApiResponse route(const ApiRequest& req) override;

private:
    struct RouteEntry {
        using Handler = std::function<ApiResponse(const ApiRequest&)>;
        Handler handler;
    };

    void addExact(const std::string& method, const std::string& path,
                  RouteEntry::Handler handler);
    void addPrefix(const std::string& prefix, ISubRouter* subRouter);

    ApiResponse handleHealth(const ApiRequest& req);
    ApiResponse handleAlerts(const ApiRequest& req);
    ApiResponse handleGetAlert(const ApiRequest& req);
    ApiResponse handleUpdateAlert(const ApiRequest& req);
    ApiResponse handleGetCases(const ApiRequest& req);
    ApiResponse handleCreateCase(const ApiRequest& req);

    std::unordered_map<std::string, RouteEntry>          m_exactRoutes;
    std::vector<std::pair<std::string, ISubRouter*>>     m_prefixRoutes;

    std::unique_ptr<NexGfwRouter>     m_nexgfw;
    std::unique_ptr<VirusTotalRouter> m_virustotal;
    std::unique_ptr<SpamhausRouter>   m_spamhaus;
    std::unique_ptr<SecuiRouter>      m_secui;
    std::unique_ptr<FortinetRouter>   m_fortinet;
    std::unique_ptr<Mf2Router>        m_mf2;
    std::unique_ptr<WinsTaxiiRouter>  m_winsTaxii;
};
