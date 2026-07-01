// src/engine/ApiRouter.cpp
#include "ApiRouter.h"
#include "NexGfwRouter.h"
#include "VirusTotalRouter.h"
#include "SpamhausRouter.h"
#include "SecuiRouter.h"
#include "FortinetRouter.h"
#include "Mf2Router.h"
#include "WinsTaxiiRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <sstream>

using json = nlohmann::json;

ApiRouter::ApiRouter()
    : m_nexgfw    (std::make_unique<NexGfwRouter>())
    , m_virustotal(std::make_unique<VirusTotalRouter>())
    , m_spamhaus  (std::make_unique<SpamhausRouter>())
    , m_secui     (std::make_unique<SecuiRouter>())
    , m_fortinet  (std::make_unique<FortinetRouter>())
    , m_mf2       (std::make_unique<Mf2Router>())
    , m_winsTaxii (std::make_unique<WinsTaxiiRouter>())
{
    addPrefix("/nexgfw/",     m_nexgfw.get());
    addPrefix("/vtapi/",      m_virustotal.get());
    addPrefix("/spamhaus/",   m_spamhaus.get());
    addPrefix("/secui/",      m_secui.get());
    addPrefix("/api/v2/",     m_fortinet.get());
    addPrefix("/logincheck",  m_fortinet.get());
    addPrefix("/logout",      m_fortinet.get());
    addPrefix("/fortinet/",   m_fortinet.get());
    addPrefix("/mf2/",        m_mf2.get());
    addPrefix("/api/taxii2/", m_winsTaxii.get());
    addPrefix("/wins/",       m_winsTaxii.get());

    addExact("GET",  "/api/v1/health", [this](const ApiRequest& r){ return handleHealth(r); });
    addExact("POST", "/api/v1/alerts", [this](const ApiRequest& r){ return handleAlerts(r); });
    addExact("GET",  "/api/v1/cases",  [this](const ApiRequest& r){ return handleGetCases(r); });
    addExact("POST", "/api/v1/cases",  [this](const ApiRequest& r){ return handleCreateCase(r); });
}

ApiRouter::~ApiRouter() = default;

void ApiRouter::addExact(const std::string& method, const std::string& path,
                          RouteEntry::Handler handler) {
    m_exactRoutes[method + ":" + path] = RouteEntry{ std::move(handler) };
}

void ApiRouter::addPrefix(const std::string& prefix, ISubRouter* subRouter) {
    m_prefixRoutes.emplace_back(prefix, subRouter);
}

static void logRawRequest(const ApiRequest& req) {
    std::ostringstream oss;
    oss << "\n";
    oss << ">>> " << req.method << " " << req.path << "\n";
    for (const auto& [k, v] : req.headers)
        oss << "    " << k << ": " << v << "\n";
    if (!req.body.empty())
        oss << "    [body] " << req.body;
    else
        oss << "    [body] (empty)";
    LOG_DEBUG("RAW", oss.str());
}

static std::string cleanPath(const std::string& path) {
    const auto pos = path.find('?');
    return (pos == std::string::npos) ? path : path.substr(0, pos);
}

ApiResponse ApiRouter::route(const ApiRequest& req) {
    logRawRequest(req);
    LOG_DEBUG("SOAR", "ApiRouter routing: " + req.method + " " + req.path);

    const std::string cp = cleanPath(req.path);

    for (const auto& [prefix, subRouter] : m_prefixRoutes) {
        if (cp.rfind(prefix, 0) == 0)
            return subRouter->route(req);
    }

    const std::string key = req.method + ":" + cp;
    if (const auto it = m_exactRoutes.find(key); it != m_exactRoutes.end())
        return it->second.handler(req);

    if (req.method == "GET" && cp.rfind("/api/v1/alerts/", 0) == 0) return handleGetAlert(req);
    if (req.method == "PUT" && cp.rfind("/api/v1/alerts/", 0) == 0) return handleUpdateAlert(req);

    LOG_WARN("SOAR", "ApiRouter: unmatched route " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode = 404;
    resp.body       = R"({"error":"not found"})";
    return resp;
}

ApiResponse ApiRouter::handleHealth(const ApiRequest&) {
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body       = R"({"status":"ok"})";
    return resp;
}

ApiResponse ApiRouter::handleAlerts(const ApiRequest& req) {
    ApiResponse resp;
    try {
        auto body = json::parse(req.body);
        (void)body;
        resp.statusCode = 201;
        resp.body       = R"({"id":"alert-mock-001","status":"created"})";
        LOG_DEBUG("SOAR", "Alert created (mock)");
    } catch (const std::exception& e) {
        LOG_WARN("SOAR", "handleAlerts JSON parse error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body       = R"({"error":"invalid json"})";
    }
    return resp;
}

ApiResponse ApiRouter::handleGetAlert(const ApiRequest& req) {
    const std::string id = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("SOAR", "GetAlert id=" + id);
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body       = R"({"id":")" + id + R"(","status":"open"})";
    return resp;
}

ApiResponse ApiRouter::handleUpdateAlert(const ApiRequest& req) {
    const std::string id = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("SOAR", "UpdateAlert id=" + id);
    ApiResponse resp;
    try {
        auto body = json::parse(req.body);
        (void)body;
        resp.statusCode = 200;
        resp.body       = R"({"id":")" + id + R"(","status":"updated"})";
    } catch (const std::exception& e) {
        LOG_WARN("SOAR", "handleUpdateAlert JSON parse error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body       = R"({"error":"invalid json"})";
    }
    return resp;
}

ApiResponse ApiRouter::handleGetCases(const ApiRequest&) {
    LOG_DEBUG("SOAR", "GetCases called");
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body       = R"({"cases":[]})";
    return resp;
}

ApiResponse ApiRouter::handleCreateCase(const ApiRequest& req) {
    ApiResponse resp;
    try {
        auto body = json::parse(req.body);
        (void)body;
        resp.statusCode = 201;
        resp.body       = R"({"id":"case-mock-001","status":"created"})";
        LOG_DEBUG("SOAR", "Case created (mock)");
    } catch (const std::exception& e) {
        LOG_WARN("SOAR", "handleCreateCase JSON parse error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body       = R"({"error":"invalid json"})";
    }
    return resp;
}
