// src/engine/SecuiRouter.cpp
#include "SecuiRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>

using json = nlohmann::json;

static constexpr const char* SECUI_CLIENT_ID     = "secui-client-01";
static constexpr const char* SECUI_CLIENT_SECRET = "SecuiSecret1234!";
static constexpr int64_t     TOKEN_TTL_SEC        = 3600;

SecuiRouter::SecuiRouter() {
    AddressGroupEntry defaultGroup;
    defaultGroup.groupName = "SOAR_BLOCK";
    defaultGroup.zone      = "external";
    m_addressGroups["SOAR_BLOCK"] = defaultGroup;
}

std::string SecuiRouter::makeToken() {
    static std::mt19937_64 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    static const char ALPHA[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::string tok;
    tok.reserve(64);
    std::uniform_int_distribution<int> dist(0, sizeof(ALPHA) - 2);
    for (int i = 0; i < 64; ++i)
        tok += ALPHA[dist(rng)];
    return tok;
}

int64_t SecuiRouter::nowUnix() {
    return static_cast<int64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
}

std::string SecuiRouter::createToken(const std::string& clientId) {
    const std::string tok = makeToken();
    TokenEntry entry;
    entry.clientId = clientId;
    entry.expires  = nowUnix() + TOKEN_TTL_SEC;
    std::lock_guard<std::mutex> lk(m_mutex);
    m_tokens[tok] = entry;
    return tok;
}

void SecuiRouter::removeToken(const std::string& token) {
    std::lock_guard<std::mutex> lk(m_mutex);
    m_tokens.erase(token);
}

bool SecuiRouter::isAuthenticated(const ApiRequest& req) const {
    auto check = [&](const std::string& key) -> bool {
        const auto it = req.headers.find(key);
        if (it == req.headers.end()) return false;
        const std::string prefix = "Bearer ";
        if (it->second.rfind(prefix, 0) != 0) return false;
        const std::string token = it->second.substr(prefix.size());
        std::lock_guard<std::mutex> lk(m_mutex);
        const auto jt = m_tokens.find(token);
        if (jt == m_tokens.end()) return false;
        return jt->second.expires > nowUnix();
    };
    return check("Authorization") || check("authorization");
}

ApiResponse SecuiRouter::handleUnauthorized() {
    ApiResponse resp;
    resp.statusCode = 401;
    resp.body = json{{"result", "fail"}, {"code", 401}, {"message", "Unauthorized"}}.dump();
    return resp;
}

ApiResponse SecuiRouter::handleNotFound(const ApiRequest& req) {
    LOG_WARN("SECUI", "Unmatched route: " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode = 404;
    resp.body = json{{"result", "fail"}, {"code", 404}, {"message", "Not found: " + req.path}}.dump();
    return resp;
}

ApiResponse SecuiRouter::handleBadRequest(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode = 400;
    resp.body = json{{"result", "fail"}, {"code", 400}, {"message", msg}}.dump();
    return resp;
}

// Accepts a pre-serialised JSON string; wraps it in the Secui success envelope.
ApiResponse SecuiRouter::handleSuccess(const std::string& dataJson) {
    ApiResponse resp;
    resp.statusCode = 200;
    json data;
    try { data = json::parse(dataJson); } catch (...) { data = dataJson; }
    resp.body = json{{"result", "success"}, {"data", data}}.dump(2);
    return resp;
}

ApiResponse SecuiRouter::route(const ApiRequest& req) {
    LOG_DEBUG("SECUI", "route: " + req.method + " " + req.path);

    const std::string& m = req.method;
    const std::string& p = req.path;

    auto startsWith = [&](const std::string& prefix) {
        return p.rfind(prefix, 0) == 0;
    };

    if (m == "POST" && p == "/secui/api/auth/v1/token")
        return handleToken(req);
    if (m == "DELETE" && p == "/secui/api/auth/v1/token")
        return handleRevokeToken(req);

    if (!isAuthenticated(req))
        return handleUnauthorized();

    if (m == "GET"  && p == "/secui/api/ngf/v1/blacklist")
        return handleBlacklistGet(req);
    if (m == "POST" && p == "/secui/api/ngf/v1/blacklist")
        return handleBlacklistAdd(req);
    if (m == "DELETE" && p == "/secui/api/ngf/v1/blacklist")
        return handleBlacklistDelete(req);

    if (m == "GET" && startsWith("/secui/api/ngf/v1/address/group/")) {
        const std::string suffix = p.substr(std::string("/secui/api/ngf/v1/address/group/").size());
        if (suffix.find("/member") != std::string::npos)
            return handleAddressGroupGet(req);
        return handleAddressGroupGet(req);
    }
    if (m == "POST" && startsWith("/secui/api/ngf/v1/address/group/"))
        return handleAddressGroupAddMember(req);
    if (m == "DELETE" && startsWith("/secui/api/ngf/v1/address/group/"))
        return handleAddressGroupDeleteMember(req);

    if (m == "GET" && p == "/secui/api/ngf/v1/policy")
        return handlePolicyGet(req);
    if (m == "GET" && p == "/secui/api/ngf/v1/session")
        return handleSessionGet(req);
    if (m == "GET" && p == "/secui/api/ngf/v1/system/info")
        return handleSystemInfo(req);

    return handleNotFound(req);
}

ApiResponse SecuiRouter::handleToken(const ApiRequest& req) {
    ApiResponse resp;
    try {
        const auto body        = json::parse(req.body);
        const std::string cid  = body.value("client_id",     "");
        const std::string csec = body.value("client_secret", "");
        const std::string gt   = body.value("grant_type",    "");

        if (cid != SECUI_CLIENT_ID || csec != SECUI_CLIENT_SECRET) {
            LOG_WARN("SECUI", "Token request failed: client_id=" + cid);
            resp.statusCode = 401;
            resp.body = json{{"result","fail"},{"code",401},{"message","Invalid client credentials"}}.dump();
            return resp;
        }
        (void)gt;
        const std::string token = createToken(cid);
        LOG_INFO("SECUI", "Token issued: client_id=" + cid);
        resp.statusCode = 200;
        resp.body = json{
            {"result",       "success"},
            {"access_token", token},
            {"token_type",   "Bearer"},
            {"expires_in",   TOKEN_TTL_SEC}
        }.dump();
    } catch (const std::exception& e) {
        LOG_WARN("SECUI", "handleToken error: " + std::string(e.what()));
        resp = handleBadRequest("Invalid request body");
    }
    return resp;
}

ApiResponse SecuiRouter::handleRevokeToken(const ApiRequest& req) {
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
        removeToken(token);
        LOG_INFO("SECUI", "Token revoked: " + token);
    }
    return handleSuccess(json::object().dump());
}

ApiResponse SecuiRouter::handleBlacklistGet(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& e : m_blacklist) {
        arr.push_back({
            {"ip",            e.ip},
            {"direction",     e.direction},
            {"ttl_days",      e.ttlDays},
            {"registered_at", e.registeredAt},
            {"expires_at",    e.expiresAt}
        });
    }
    return handleSuccess(json{{"blacklist", arr}, {"total", static_cast<int>(m_blacklist.size())}}.dump());
}

ApiResponse SecuiRouter::handleBlacklistAdd(const ApiRequest& req) {
    try {
        const auto body = json::parse(req.body);
        const std::string ip  = body.value("ip",        "");
        const std::string dir = body.value("direction", "BOTH");
        const int ttl         = body.value("ttl_days",  365);

        if (ip.empty()) return handleBadRequest("'ip' field is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        for (const auto& e : m_blacklist) {
            if (e.ip == ip) {
                ApiResponse resp;
                resp.statusCode = 409;
                resp.body = json{{"result","fail"},{"code",409},{"message","IP already in blacklist: " + ip}}.dump();
                return resp;
            }
        }
        BlacklistEntry entry;
        entry.ip           = ip;
        entry.direction    = dir;
        entry.ttlDays      = ttl;
        entry.registeredAt = nowUnix();
        entry.expiresAt    = entry.registeredAt + static_cast<int64_t>(ttl) * 86400;
        m_blacklist.push_back(entry);
        LOG_INFO("SECUI", "Blacklist add: ip=" + ip + " dir=" + dir + " ttl=" + std::to_string(ttl));
        return handleSuccess(json{{"ip", ip},{"direction", dir},{"ttl_days", ttl}}.dump());
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse SecuiRouter::handleBlacklistDelete(const ApiRequest& req) {
    try {
        const auto body      = json::parse(req.body);
        const std::string ip = body.value("ip", "");
        if (ip.empty()) return handleBadRequest("'ip' field is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        const auto it = std::remove_if(m_blacklist.begin(), m_blacklist.end(),
            [&](const BlacklistEntry& e){ return e.ip == ip; });
        if (it == m_blacklist.end()) {
            ApiResponse resp;
            resp.statusCode = 404;
            resp.body = json{{"result","fail"},{"code",404},{"message","IP not found in blacklist: " + ip}}.dump();
            return resp;
        }
        m_blacklist.erase(it, m_blacklist.end());
        LOG_INFO("SECUI", "Blacklist delete: ip=" + ip);
        return handleSuccess(json{{"ip", ip},{"message", "Removed from blacklist"}}.dump());
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

static std::string extractGroupName(const std::string& path) {
    const std::string base = "/secui/api/ngf/v1/address/group/";
    std::string rem = path.substr(base.size());
    const auto pos = rem.find('/');
    if (pos != std::string::npos) rem = rem.substr(0, pos);
    return rem;
}

ApiResponse SecuiRouter::handleAddressGroupGet(const ApiRequest& req) {
    const std::string groupName = extractGroupName(req.path);
    std::lock_guard<std::mutex> lk(m_mutex);
    const auto it = m_addressGroups.find(groupName);
    if (it == m_addressGroups.end()) {
        ApiResponse resp;
        resp.statusCode = 404;
        resp.body = json{{"result","fail"},{"code",404},{"message","Group not found: " + groupName}}.dump();
        return resp;
    }
    const auto& g = it->second;
    json members = json::array();
    for (const auto& m : g.members) members.push_back(m);
    return handleSuccess(json{
        {"group_name", g.groupName},
        {"zone",       g.zone},
        {"members",    members},
        {"total",      static_cast<int>(g.members.size())}
    }.dump());
}

ApiResponse SecuiRouter::handleAddressGroupAddMember(const ApiRequest& req) {
    const std::string groupName = extractGroupName(req.path);
    try {
        const auto body      = json::parse(req.body);
        const std::string ip = body.value("ip", "");
        if (ip.empty()) return handleBadRequest("'ip' field is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        auto it = m_addressGroups.find(groupName);
        if (it == m_addressGroups.end()) {
            AddressGroupEntry newGroup;
            newGroup.groupName = groupName;
            newGroup.zone      = "external";
            m_addressGroups[groupName] = newGroup;
            it = m_addressGroups.find(groupName);
        }
        auto& members = it->second.members;
        if (std::find(members.begin(), members.end(), ip) != members.end()) {
            ApiResponse resp;
            resp.statusCode = 409;
            resp.body = json{{"result","fail"},{"code",409},{"message","IP already in group: " + ip}}.dump();
            return resp;
        }
        members.push_back(ip);
        LOG_INFO("SECUI", "AddressGroup add: group=" + groupName + " ip=" + ip);
        return handleSuccess(json{{"group_name", groupName},{"ip", ip},{"message", "Added"}}.dump());
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse SecuiRouter::handleAddressGroupDeleteMember(const ApiRequest& req) {
    const std::string groupName = extractGroupName(req.path);
    try {
        const auto body      = json::parse(req.body);
        const std::string ip = body.value("ip", "");
        if (ip.empty()) return handleBadRequest("'ip' field is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        auto it = m_addressGroups.find(groupName);
        if (it == m_addressGroups.end()) {
            ApiResponse resp;
            resp.statusCode = 404;
            resp.body = json{{"result","fail"},{"code",404},{"message","Group not found: " + groupName}}.dump();
            return resp;
        }
        auto& members = it->second.members;
        const auto mit = std::remove(members.begin(), members.end(), ip);
        if (mit == members.end()) {
            ApiResponse resp;
            resp.statusCode = 404;
            resp.body = json{{"result","fail"},{"code",404},{"message","IP not found in group: " + ip}}.dump();
            return resp;
        }
        members.erase(mit, members.end());
        LOG_INFO("SECUI", "AddressGroup delete: group=" + groupName + " ip=" + ip);
        return handleSuccess(json{{"group_name", groupName},{"ip", ip},{"message", "Removed"}}.dump());
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse SecuiRouter::handlePolicyGet(const ApiRequest& req) {
    (void)req;
    json policies = json::array();
    policies.push_back({
        {"id",          1},
        {"name",        "SOAR_BLOCK_INBOUND"},
        {"src_zone",    "external"},
        {"dst_zone",    "internal"},
        {"src_group",   "SOAR_BLOCK"},
        {"dst_group",   "any"},
        {"service",     "any"},
        {"action",      "deny"},
        {"logging",     true},
        {"enabled",     true}
    });
    policies.push_back({
        {"id",          2},
        {"name",        "INTERNAL_PERMIT"},
        {"src_zone",    "internal"},
        {"dst_zone",    "external"},
        {"src_group",   "any"},
        {"dst_group",   "any"},
        {"service",     "any"},
        {"action",      "permit"},
        {"logging",     true},
        {"enabled",     true}
    });
    return handleSuccess(json{{"policies", policies},{"total", 2}}.dump());
}

ApiResponse SecuiRouter::handleSessionGet(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json sessions = json::array();
    for (const auto& kv : m_tokens) {
        sessions.push_back({
            {"client_id", kv.second.clientId},
            {"expires",   kv.second.expires}
        });
    }
    return handleSuccess(json{{"sessions", sessions},{"total", static_cast<int>(sessions.size())}}.dump());
}

ApiResponse SecuiRouter::handleSystemInfo(const ApiRequest& req) {
    (void)req;
    return handleSuccess(json{
        {"model",    "BLUEMAX NGF Mock"},
        {"version",  "5.0.0-mock"},
        {"hostname", "secui-ngf-01"},
        {"uptime",   86400},
        {"cpu_usage",  12},
        {"mem_usage",  38}
    }.dump());
}
