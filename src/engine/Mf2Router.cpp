// src/engine/Mf2Router.cpp
#include "Mf2Router.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>
#include <algorithm>

using json = nlohmann::json;

static constexpr int64_t SESSION_TTL = 3600;

Mf2Router::Mf2Router() {
    PolicyEntry defaultDeny;
    defaultDeny.id      = "policy-0001";
    defaultDeny.name    = "DEFAULT_DENY";
    defaultDeny.srcIp   = "any";
    defaultDeny.dstIp   = "any";
    defaultDeny.service = "any";
    defaultDeny.action  = "deny";
    defaultDeny.enabled = true;
    m_policies[defaultDeny.id] = defaultDeny;
}

std::string Mf2Router::makeId() {
    static std::mt19937_64 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    std::ostringstream oss;
    oss << std::hex << std::uppercase << rng();
    return oss.str();
}

int64_t Mf2Router::nowUnix() {
    return static_cast<int64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
}

std::string Mf2Router::createSession(const std::string& userId, const std::string& token) {
    SessionEntry entry;
    entry.userId  = userId;
    entry.expires = nowUnix() + SESSION_TTL;
    std::lock_guard<std::mutex> lk(m_mutex);
    m_sessions[token] = entry;
    return token;
}

void Mf2Router::removeSession(const std::string& token) {
    std::lock_guard<std::mutex> lk(m_mutex);
    m_sessions.erase(token);
}

bool Mf2Router::isAuthenticated(const ApiRequest& req) const {
    auto check = [&](const std::string& key) -> bool {
        const auto it = req.headers.find(key);
        if (it == req.headers.end()) return false;
        const std::string& val = it->second;
        const std::string prefix = "Bearer ";
        const std::string token = (val.rfind(prefix, 0) == 0)
            ? val.substr(prefix.size())
            : val;
        std::lock_guard<std::mutex> lk(m_mutex);
        const auto jt = m_sessions.find(token);
        if (jt == m_sessions.end()) return false;
        return jt->second.expires > nowUnix();
    };
    return check("Authorization") || check("authorization");
}

ApiResponse Mf2Router::handleUnauthorized() {
    ApiResponse resp;
    resp.statusCode = 401;
    resp.body = json{{"code", 401}, {"message", "Unauthorized"}, {"result", "fail"}}.dump();
    return resp;
}

ApiResponse Mf2Router::handleNotFound(const ApiRequest& req) {
    LOG_WARN("MF2", "Unmatched route: " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode = 404;
    resp.body = json{{"code", 404}, {"message", "Not found: " + req.path}, {"result", "fail"}}.dump();
    return resp;
}

ApiResponse Mf2Router::handleBadRequest(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode = 400;
    resp.body = json{{"code", 400}, {"message", msg}, {"result", "fail"}}.dump();
    return resp;
}

ApiResponse Mf2Router::route(const ApiRequest& req) {
    LOG_DEBUG("MF2", "route: " + req.method + " " + req.path);

    const std::string& m = req.method;
    const std::string& p = req.path;

    if (m == "POST" && p == "/mf2/api/v1/login")
        return handleLogin(req);
    if (m == "POST" && p == "/mf2/api/v1/logout")
        return handleLogout(req);
    if (m == "POST" && p == "/mf2/api/v1/refresh")
        return handleRefresh(req);

    if (!isAuthenticated(req))
        return handleUnauthorized();

    if (m == "GET"    && p == "/mf2/api/v1/policy")
        return handlePolicyGet(req);
    if (m == "POST"   && p == "/mf2/api/v1/policy")
        return handlePolicyAdd(req);
    if (m == "DELETE" && p == "/mf2/api/v1/policy")
        return handlePolicyDelete(req);
    if (m == "PUT"    && p == "/mf2/api/v1/policy/enable")
        return handlePolicyEnable(req);

    if (m == "GET"    && p == "/mf2/api/v1/object")
        return handleObjectGet(req);
    if (m == "POST"   && p == "/mf2/api/v1/object")
        return handleObjectAdd(req);
    if (m == "DELETE" && p == "/mf2/api/v1/object")
        return handleObjectDelete(req);

    if (m == "GET"  && p == "/mf2/api/v1/system/info")
        return handleSystemInfo(req);
    if (m == "POST" && p == "/mf2/api/v1/apply")
        return handleApply(req);

    return handleNotFound(req);
}

ApiResponse Mf2Router::handleLogin(const ApiRequest& req) {
    auto extractToken = [&](const std::string& key) -> std::string {
        const auto it = req.headers.find(key);
        if (it == req.headers.end()) return "";
        const std::string prefix = "Bearer ";
        if (it->second.rfind(prefix, 0) == 0)
            return it->second.substr(prefix.size());
        return it->second;
    };

    const std::string token = [&]() -> std::string {
        const std::string t = extractToken("Authorization");
        if (!t.empty()) return t;
        return extractToken("authorization");
    }();

    if (token.empty()) {
        LOG_WARN("MF2", "Login rejected: no Authorization header");
        return handleBadRequest("Authorization header is required");
    }

    int64_t ttl = SESSION_TTL;
    if (!req.body.empty()) {
        try {
            const auto body = json::parse(req.body);
            if (body.contains("timeout"))
                ttl = std::stoll(body["timeout"].get<std::string>());
        } catch (...) {}
    }

    SessionEntry entry;
    entry.userId  = "device";
    entry.expires = nowUnix() + ttl;
    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_sessions[token] = entry;
    }

    LOG_INFO("MF2", "Login succeeded: token=...(" + std::to_string(token.size()) + "chars) ttl=" + std::to_string(ttl));

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"result",       "success"},
        {"access_token", token},
        {"token_type",   "Bearer"},
        {"expires_in",   ttl}
    }.dump();
    return resp;
}

ApiResponse Mf2Router::handleLogout(const ApiRequest& req) {
    auto extract = [&](const std::string& key) -> std::string {
        const auto it = req.headers.find(key);
        if (it == req.headers.end()) return "";
        const std::string prefix = "Bearer ";
        if (it->second.rfind(prefix, 0) != 0) return "";
        return it->second.substr(prefix.size());
    };
    std::string token = extract("Authorization");
    if (token.empty()) token = extract("authorization");
    if (!token.empty()) {
        removeSession(token);
        LOG_INFO("MF2", "Logout: token=...(" + std::to_string(token.size()) + "chars)");
    }
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{{"result", "success"}, {"message", "Logged out"}}.dump();
    return resp;
}

ApiResponse Mf2Router::handleRefresh(const ApiRequest& req) {
    if (!isAuthenticated(req))
        return handleUnauthorized();
    try {
        const auto body  = json::parse(req.body);
        const std::string oldToken = body.value("token", "");
        std::string userId;
        {
            std::lock_guard<std::mutex> lk(m_mutex);
            const auto it = m_sessions.find(oldToken);
            if (it == m_sessions.end()) {
                ApiResponse resp;
                resp.statusCode = 401;
                resp.body = json{{"code", 401}, {"message", "Token not found"}, {"result", "fail"}}.dump();
                return resp;
            }
            userId = it->second.userId;
            m_sessions.erase(it);
        }
        const std::string newToken = makeId();
        createSession(userId, newToken);
        LOG_INFO("MF2", "Token refreshed: user=" + userId);
        ApiResponse resp;
        resp.statusCode = 200;
        resp.body = json{
            {"result",        "success"},
            {"access_token",  newToken},
            {"token_type",    "Bearer"},
            {"expires_in",    SESSION_TTL}
        }.dump();
        return resp;
    } catch (const std::exception& e) {
        LOG_WARN("MF2", "handleRefresh error: " + std::string(e.what()));
        return handleBadRequest("Invalid request body");
    }
}

ApiResponse Mf2Router::handlePolicyGet(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& [id, pol] : m_policies) {
        arr.push_back({
            {"id",      pol.id},
            {"name",    pol.name},
            {"src_ip",  pol.srcIp},
            {"dst_ip",  pol.dstIp},
            {"service", pol.service},
            {"action",  pol.action},
            {"enabled", pol.enabled}
        });
    }
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{{"result", "success"}, {"data", json{{"policies", arr}, {"total", static_cast<int>(arr.size())}}}}.dump(2);
    return resp;
}

ApiResponse Mf2Router::handlePolicyAdd(const ApiRequest& req) {
    try {
        const auto body = json::parse(req.body);
        const std::string name = body.value("name", "");
        if (name.empty()) return handleBadRequest("'name' field is required");
        const std::string action = body.value("action", "");
        if (action != "allow" && action != "deny")
            return handleBadRequest("'action' must be 'allow' or 'deny'");

        std::lock_guard<std::mutex> lk(m_mutex);
        for (const auto& [id, pol] : m_policies) {
            if (pol.name == name) {
                ApiResponse resp;
                resp.statusCode = 409;
                resp.body = json{{"code", 409}, {"message", "Policy name already exists: " + name}, {"result", "fail"}}.dump();
                return resp;
            }
        }
        PolicyEntry pol;
        pol.id      = makeId();
        pol.name    = name;
        pol.srcIp   = body.value("src_ip",  "any");
        pol.dstIp   = body.value("dst_ip",  "any");
        pol.service = body.value("service", "any");
        pol.action  = action;
        pol.enabled = body.value("enabled", true);
        m_policies[pol.id] = pol;
        LOG_INFO("MF2", "Policy added: id=" + pol.id + " name=" + pol.name);
        ApiResponse resp;
        resp.statusCode = 200;
        resp.body = json{{"result", "success"}, {"data", json{{"id", pol.id}, {"name", pol.name}}}}.dump();
        return resp;
    } catch (const std::exception& e) {
        LOG_WARN("MF2", "handlePolicyAdd error: " + std::string(e.what()));
        return handleBadRequest("Invalid request body");
    }
}

ApiResponse Mf2Router::handlePolicyDelete(const ApiRequest& req) {
    try {
        const auto body = json::parse(req.body);
        const std::string id = body.value("id", "");
        if (id.empty()) return handleBadRequest("'id' field is required");
        std::lock_guard<std::mutex> lk(m_mutex);
        if (m_policies.erase(id) == 0) {
            ApiResponse resp;
            resp.statusCode = 404;
            resp.body = json{{"code", 404}, {"message", "Policy not found: " + id}, {"result", "fail"}}.dump();
            return resp;
        }
        LOG_INFO("MF2", "Policy deleted: id=" + id);
        ApiResponse resp;
        resp.statusCode = 200;
        resp.body = json{{"result", "success"}, {"data", json{{"id", id}, {"message", "Deleted"}}}}.dump();
        return resp;
    } catch (const std::exception& e) {
        LOG_WARN("MF2", "handlePolicyDelete error: " + std::string(e.what()));
        return handleBadRequest("Invalid request body");
    }
}

ApiResponse Mf2Router::handlePolicyEnable(const ApiRequest& req) {
    try {
        const auto body      = json::parse(req.body);
        const std::string id = body.value("id", "");
        if (id.empty()) return handleBadRequest("'id' field is required");
        const bool enable    = body.value("enabled", true);
        std::lock_guard<std::mutex> lk(m_mutex);
        const auto it = m_policies.find(id);
        if (it == m_policies.end()) {
            ApiResponse resp;
            resp.statusCode = 404;
            resp.body = json{{"code", 404}, {"message", "Policy not found: " + id}, {"result", "fail"}}.dump();
            return resp;
        }
        it->second.enabled = enable;
        LOG_INFO("MF2", "Policy enable=" + std::to_string(enable) + " id=" + id);
        ApiResponse resp;
        resp.statusCode = 200;
        resp.body = json{{"result", "success"}, {"data", json{{"id", id}, {"enabled", enable}}}}.dump();
        return resp;
    } catch (const std::exception& e) {
        LOG_WARN("MF2", "handlePolicyEnable error: " + std::string(e.what()));
        return handleBadRequest("Invalid request body");
    }
}

ApiResponse Mf2Router::handleObjectGet(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& [id, obj] : m_objects) {
        arr.push_back({
            {"id",    obj.id},
            {"name",  obj.name},
            {"type",  obj.type},
            {"value", obj.value}
        });
    }
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{{"result", "success"}, {"data", json{{"objects", arr}, {"total", static_cast<int>(arr.size())}}}}.dump(2);
    return resp;
}

ApiResponse Mf2Router::handleObjectAdd(const ApiRequest& req) {
    try {
        const auto body        = json::parse(req.body);
        const std::string name = body.value("name",  "");
        const std::string type = body.value("type",  "");
        const std::string val  = body.value("value", "");
        if (name.empty()) return handleBadRequest("'name' field is required");
        if (type.empty()) return handleBadRequest("'type' field is required");
        if (val.empty())  return handleBadRequest("'value' field is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        for (const auto& [id, obj] : m_objects) {
            if (obj.name == name) {
                ApiResponse resp;
                resp.statusCode = 409;
                resp.body = json{{"code", 409}, {"message", "Object name already exists: " + name}, {"result", "fail"}}.dump();
                return resp;
            }
        }
        ObjectEntry obj;
        obj.id    = makeId();
        obj.name  = name;
        obj.type  = type;
        obj.value = val;
        m_objects[obj.id] = obj;
        LOG_INFO("MF2", "Object added: id=" + obj.id + " name=" + obj.name);
        ApiResponse resp;
        resp.statusCode = 200;
        resp.body = json{{"result", "success"}, {"data", json{{"id", obj.id}, {"name", obj.name}}}}.dump();
        return resp;
    } catch (const std::exception& e) {
        LOG_WARN("MF2", "handleObjectAdd error: " + std::string(e.what()));
        return handleBadRequest("Invalid request body");
    }
}

ApiResponse Mf2Router::handleObjectDelete(const ApiRequest& req) {
    try {
        const auto body      = json::parse(req.body);
        const std::string id = body.value("id", "");
        if (id.empty()) return handleBadRequest("'id' field is required");
        std::lock_guard<std::mutex> lk(m_mutex);
        if (m_objects.erase(id) == 0) {
            ApiResponse resp;
            resp.statusCode = 404;
            resp.body = json{{"code", 404}, {"message", "Object not found: " + id}, {"result", "fail"}}.dump();
            return resp;
        }
        LOG_INFO("MF2", "Object deleted: id=" + id);
        ApiResponse resp;
        resp.statusCode = 200;
        resp.body = json{{"result", "success"}, {"data", json{{"id", id}, {"message", "Deleted"}}}}.dump();
        return resp;
    } catch (const std::exception& e) {
        LOG_WARN("MF2", "handleObjectDelete error: " + std::string(e.what()));
        return handleBadRequest("Invalid request body");
    }
}

ApiResponse Mf2Router::handleSystemInfo(const ApiRequest& req) {
    (void)req;
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"result", "success"},
        {"data", json{
            {"model",      "MF2 Firewall Mock"},
            {"version",    "2.0.0-mock"},
            {"hostname",   "mf2-fw-01"},
            {"uptime",     86400},
            {"cpu_usage",  8},
            {"mem_usage",  32}
        }}
    }.dump(2);
    return resp;
}

ApiResponse Mf2Router::handleApply(const ApiRequest& req) {
    (void)req;
    LOG_INFO("MF2", "Apply called");
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{{"result", "success"}, {"message", "Configuration applied"}}.dump();
    return resp;
}
