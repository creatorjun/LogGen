// src/engine/FortinetRouter.cpp
#include "FortinetRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <algorithm>
#include <sstream>

using json = nlohmann::json;

static constexpr const char* FORTI_MOCK_TOKEN     = "fortinet-mock-token-soar-test-0001";
static constexpr const char* FORTI_MOCK_USER_PLAIN  = "admin";
static constexpr const char* FORTI_MOCK_PASS_PLAIN  = "password";
static constexpr const char* FORTI_MOCK_USER_B64    = "4RgJgqwJXFiDMeNOqieM/Q==";
static constexpr const char* FORTI_MOCK_PASS_B64    = "L9ZPfQ4FFufZm1Eq49ptMA==";
static constexpr const char* FORTI_APSCOOKIE_NAME   = "APSCOOKIE_8";
static constexpr const char* FORTI_APSCOOKIE_VAL    = "mock_session_0001";
static constexpr const char* FORTI_CSRF_COOKIE      = "ccsrftoken";
static constexpr const char* FORTI_CSRF_VAL         = "mock-csrf-0001";

static int64_t nowUnix() {
    return static_cast<int64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
}

FortinetRouter::FortinetRouter()
    : m_token(FORTI_MOCK_TOKEN)
    , m_nextPolicyId(100)
{
    AddressEntry soarBlock;
    soarBlock.name    = "SOAR_BLOCK_GROUP";
    soarBlock.type    = "ipmask";
    soarBlock.subnet  = "0.0.0.0 0.0.0.0";
    soarBlock.comment = "SOAR managed block address";
    m_addresses.push_back(soarBlock);

    AddrgrpEntry grp;
    grp.name    = "SOAR_BLOCK_GRP";
    grp.comment = "SOAR managed address group";
    m_addrgrps.push_back(grp);

    PolicyEntry p;
    p.policyid  = 1;
    p.name      = "SOAR_BLOCK_INBOUND";
    p.srcintf   = "wan1";
    p.dstintf   = "internal";
    p.srcaddr   = "SOAR_BLOCK_GRP";
    p.dstaddr   = "all";
    p.action    = "deny";
    p.schedule  = "always";
    p.service   = "ALL";
    p.status    = 1;
    m_policies.push_back(p);
}

std::string FortinetRouter::extractToken(const ApiRequest& req) {
    auto checkHeader = [&](const std::string& key) -> std::string {
        const auto it = req.headers.find(key);
        if (it == req.headers.end()) return "";
        const std::string prefix = "Bearer ";
        if (it->second.rfind(prefix, 0) == 0)
            return it->second.substr(prefix.size());
        return it->second;
    };
    std::string tok = checkHeader("Authorization");
    if (tok.empty()) tok = checkHeader("authorization");
    if (!tok.empty()) return tok;

    const auto pit = req.params.find("access_token");
    if (pit != req.params.end() && !pit->second.empty())
        return pit->second;

    return "";
}

std::string FortinetRouter::extractSessionCookie(const ApiRequest& req) {
    const auto it = req.headers.find("Cookie");
    if (it == req.headers.end()) return "";
    const std::string& cookie = it->second;
    const std::string prefix = "APSCOOKIE_";
    auto pos = cookie.find(prefix);
    if (pos == std::string::npos) return "";
    const auto eq = cookie.find('=', pos);
    if (eq == std::string::npos) return "";
    const std::string sub = cookie.substr(eq + 1);
    const auto end = sub.find(';');
    return (end == std::string::npos) ? sub : sub.substr(0, end);
}

std::string FortinetRouter::extractCsrfToken(const ApiRequest& req) {
    for (const auto& key : {"X-CSRFTOKEN", "x-csrftoken"}) {
        const auto it = req.headers.find(key);
        if (it != req.headers.end()) return it->second;
    }
    const auto it = req.headers.find("Cookie");
    if (it != req.headers.end()) {
        const std::string key = "ccsrftoken=";
        auto pos = it->second.find(key);
        if (pos != std::string::npos) {
            const std::string sub = it->second.substr(pos + key.size());
            const auto end = sub.find(';');
            return (end == std::string::npos) ? sub : sub.substr(0, end);
        }
    }
    return "";
}

bool FortinetRouter::isAuthenticated(const ApiRequest& req) const {
    const std::string tok = extractToken(req);
    if (tok == m_token) return true;

    const std::string session = extractSessionCookie(req);
    if (!session.empty()) {
        std::lock_guard<std::mutex> lk(m_mutex);
        return m_sessions.count(session) > 0;
    }
    return false;
}

bool FortinetRouter::validateCsrf(const ApiRequest& req) const {
    // SOAR(Apache HttpClient)가 Set-Cookie로 받은 ccsrftoken 값을 X-CSRFTOKEN 헤더에
    // 그대로 복사할 때 앞 1글자를 잘라내는 버그가 있어 "mock-csrf-0001" → "ock-csrf-000" 형태로 전송됨.
    // Mock 서버 목적상 CSRF 검증은 무조건 통과시킨다.
    (void)req;
    return true;
}

ApiResponse FortinetRouter::handleUnauthorized() {
    ApiResponse resp;
    resp.statusCode = 401;
    resp.body = json{
        {"http_status", 401},
        {"status",      "authentication_failed"},
        {"error",       -11}
    }.dump();
    return resp;
}

ApiResponse FortinetRouter::handleForbidden(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode = 403;
    resp.body = json{
        {"http_status", 403},
        {"status",      "forbidden"},
        {"message",     msg}
    }.dump();
    return resp;
}

ApiResponse FortinetRouter::handleNotFound(const ApiRequest& req) {
    LOG_WARN("FORTINET", "Unmatched route: " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode = 404;
    resp.body = json{
        {"http_status", 404},
        {"status",      "not_found"}
    }.dump();
    return resp;
}

ApiResponse FortinetRouter::handleBadRequest(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode = 400;
    resp.body = json{
        {"http_status", 400},
        {"status",      "invalid_request"},
        {"message",     msg}
    }.dump();
    return resp;
}

ApiResponse FortinetRouter::makeSuccess(const std::string& resultsJson, const std::string& method) {
    ApiResponse resp;
    resp.statusCode = 200;
    json results;
    try { results = json::parse(resultsJson); } catch (...) { results = resultsJson; }
    resp.body = json{
        {"http_method", method},
        {"results",     results},
        {"status",      "success"},
        {"http_status", 200},
        {"vdom",        "root"},
        {"revision",    "mock"}
    }.dump(2);
    return resp;
}

ApiResponse FortinetRouter::makeError(int httpStatus, const std::string& msg) {
    ApiResponse resp;
    resp.statusCode = httpStatus;
    resp.body = json{
        {"http_status", httpStatus},
        {"status",      "error"},
        {"message",     msg}
    }.dump();
    return resp;
}

// ---- private static JSON serialisation helpers ----

std::string FortinetRouter::addressToJson(const AddressEntry& e) {
    return json{
        {"name",         e.name},
        {"type",         e.type},
        {"subnet",       e.subnet},
        {"comment",      e.comment},
        {"q_origin_key", e.name}
    }.dump();
}

std::string FortinetRouter::addrgrpToJson(const AddrgrpEntry& e) {
    json members = json::array();
    for (const auto& m : e.members)
        members.push_back({{"name", m}});
    return json{
        {"name",         e.name},
        {"member",       members},
        {"comment",      e.comment},
        {"q_origin_key", e.name}
    }.dump();
}

std::string FortinetRouter::policyToJson(const PolicyEntry& e) {
    return json{
        {"policyid",  e.policyid},
        {"name",      e.name},
        {"srcintf",   json::array({{{"name", e.srcintf}}})},
        {"dstintf",   json::array({{{"name", e.dstintf}}})},
        {"srcaddr",   json::array({{{"name", e.srcaddr}}})},
        {"dstaddr",   json::array({{{"name", e.dstaddr}}})},
        {"action",    e.action},
        {"schedule",  e.schedule},
        {"service",   json::array({{{"name", e.service}}})},
        {"status",    e.status ? "enable" : "disable"}
    }.dump();
}

// ---- logincheck ----

ApiResponse FortinetRouter::handleLoginCheck(const ApiRequest& req) {
    std::string username, password;
    std::string resolvedVia;

    // Step 1: req.params (query string parsed from req.target)
    {
        std::string paramDump = "[login] req.params count=" + std::to_string(req.params.size());
        for (const auto& kv : req.params)
            paramDump += " [" + kv.first + "=" + kv.second + "]";
        LOG_DEBUG("FORTINET", paramDump);

        const auto uit = req.params.find("username");
        if (uit != req.params.end()) username = uit->second;

        const auto sit = req.params.find("secretkey");
        if (sit != req.params.end()) password = sit->second;
        if (password.empty()) {
            const auto pit = req.params.find("password");
            if (pit != req.params.end()) password = pit->second;
        }
        if (!username.empty()) resolvedVia = "params";
    }

    // Step 2: JSON body
    if (username.empty()) {
        LOG_DEBUG("FORTINET", "[login] params empty, trying JSON body. body_len="
            + std::to_string(req.body.size()));
        if (!req.body.empty()) {
            try {
                const auto body = json::parse(req.body);
                username = body.value("username", "");
                password = body.value("secretkey", body.value("password", ""));
                if (!username.empty()) resolvedVia = "json_body";
            } catch (const std::exception& ex) {
                LOG_DEBUG("FORTINET", std::string("[login] JSON parse failed: ") + ex.what());
            }
        }
    }

    // Step 3: raw body form-decode
    if (username.empty()) {
        LOG_DEBUG("FORTINET", "[login] JSON body miss, trying raw form-decode. body_len="
            + std::to_string(req.body.size()));
        if (!req.body.empty()) {
            std::istringstream ss(req.body);
            std::string token;
            while (std::getline(ss, token, '&')) {
                const auto eq = token.find('=');
                if (eq == std::string::npos) continue;
                const std::string k = token.substr(0, eq);
                const std::string v = token.substr(eq + 1);
                if (k == "username")                           { username = v; }
                else if (k == "secretkey" || k == "password") { password = v; }
            }
            if (!username.empty()) resolvedVia = "raw_form_body";
        }
    }

    LOG_DEBUG("FORTINET", "[login] resolved_via=" + (resolvedVia.empty() ? "none" : resolvedVia)
        + " user=[" + username + "] pass=[" + password + "]");

    const bool userOk = (username == FORTI_MOCK_USER_PLAIN || username == FORTI_MOCK_USER_B64);
    const bool passOk = (password == FORTI_MOCK_PASS_PLAIN || password == FORTI_MOCK_PASS_B64);

    if (!userOk || !passOk) {
        LOG_WARN("FORTINET", "Login failed: resolved_via=" + (resolvedVia.empty() ? "none" : resolvedVia)
            + " user=[" + username + "] userOk=" + (userOk?"Y":"N")
            + " passOk=" + (passOk?"Y":"N"));
        ApiResponse resp;
        resp.statusCode  = 200;
        resp.contentType = "text/plain";
        resp.body = "0";
        return resp;
    }

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_sessions[FORTI_APSCOOKIE_VAL] = FORTI_CSRF_VAL;
    }
    LOG_INFO("FORTINET", "Login success: resolved_via=" + resolvedVia + " user=[" + username + "]");

    ApiResponse resp;
    resp.statusCode  = 200;
    resp.contentType = "text/plain";
    resp.body = "1document.location=\"/ng/prompt?viewOnly&redir=%2Fng%2F\"";

    resp.headers.emplace_back(
        "Set-Cookie",
        std::string(FORTI_APSCOOKIE_NAME) + "=" + FORTI_APSCOOKIE_VAL
        + "; Path=/; HttpOnly"
    );
    resp.headers.emplace_back(
        "Set-Cookie",
        std::string(FORTI_CSRF_COOKIE) + "=" + FORTI_CSRF_VAL
        + "; Path=/"
    );
    return resp;
}

ApiResponse FortinetRouter::handleLogout(const ApiRequest& req) {
    const std::string session = extractSessionCookie(req);
    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_sessions.erase(session);
    }
    LOG_INFO("FORTINET", "Logout: session cleared");
    ApiResponse resp;
    resp.statusCode  = 200;
    resp.contentType = "text/plain";
    resp.headers.emplace_back(
        "Set-Cookie",
        std::string(FORTI_APSCOOKIE_NAME) + "=; Path=/; Max-Age=0"
    );
    resp.headers.emplace_back(
        "Set-Cookie",
        std::string(FORTI_CSRF_COOKIE) + "=; Path=/; Max-Age=0"
    );
    resp.body = "0";
    return resp;
}

// ---- /addrgrp/{name}/member 핸들러 ----
// GET  /addrgrp/{name}/member  → 멤버 목록 반환 (그룹 없으면 auto-create)
// POST /addrgrp/{name}/member  → 멤버 추가 (그룹 없으면 auto-create), firewall/address에도 주소 오브젝트 auto-create
// PUT  /addrgrp/{name}/member  → 멤버 전체 교체

ApiResponse FortinetRouter::handleAddrgrpMemberGet(const ApiRequest& req,
                                                    const std::string& grpName) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);

    const auto it = std::find_if(m_addrgrps.begin(), m_addrgrps.end(),
        [&](const AddrgrpEntry& e){ return e.name == grpName; });
    if (it == m_addrgrps.end()) {
        AddrgrpEntry newGrp;
        newGrp.name    = grpName;
        newGrp.comment = "auto-created by mock";
        m_addrgrps.push_back(newGrp);
        LOG_INFO("FORTINET", "Addrgrp auto-created: " + grpName);
        json emptyArr = json::array();
        return makeSuccess(emptyArr.dump(), "GET");
    }

    json arr = json::array();
    for (const auto& m : it->members)
        arr.push_back({{"name", m}});
    return makeSuccess(arr.dump(), "GET");
}

ApiResponse FortinetRouter::handleAddrgrpMemberPost(const ApiRequest& req,
                                                     const std::string& grpName) {
    try {
        const auto body = json::parse(req.body);

        std::lock_guard<std::mutex> lk(m_mutex);

        // addrgrp auto-create
        auto it = std::find_if(m_addrgrps.begin(), m_addrgrps.end(),
            [&](const AddrgrpEntry& e){ return e.name == grpName; });
        if (it == m_addrgrps.end()) {
            AddrgrpEntry newGrp;
            newGrp.name    = grpName;
            newGrp.comment = "auto-created by mock";
            m_addrgrps.push_back(newGrp);
            it = m_addrgrps.end() - 1;
            LOG_INFO("FORTINET", "Addrgrp auto-created: " + grpName);
        }

        // member 추가 + firewall/address 에도 주소 오브젝트 auto-create
        auto addMember = [&](const std::string& memberName) {
            // addrgrp member 추가
            if (std::find(it->members.begin(), it->members.end(), memberName) == it->members.end()) {
                it->members.push_back(memberName);
                LOG_INFO("FORTINET", "Addrgrp member added: grp=" + grpName + " member=" + memberName);
            }
            // firewall/address 에 해당 이름의 주소 오브젝트가 없으면 auto-create
            const auto addrIt = std::find_if(m_addresses.begin(), m_addresses.end(),
                [&](const AddressEntry& a){ return a.name == memberName; });
            if (addrIt == m_addresses.end()) {
                // memberName 형식: Block_MMDD_x.x.x.x/32  → subnet 추츠
                std::string subnet = "0.0.0.0 255.255.255.255";
                const auto slashPos = memberName.rfind('/');
                const auto underPos = memberName.rfind('_');
                if (underPos != std::string::npos && slashPos != std::string::npos && underPos < slashPos) {
                    const std::string ip = memberName.substr(underPos + 1, slashPos - underPos - 1);
                    const std::string mask = (memberName.substr(slashPos + 1) == "32") ? "255.255.255.255" : "0.0.0.0";
                    subnet = ip + " " + mask;
                }
                AddressEntry newAddr;
                newAddr.name    = memberName;
                newAddr.type    = "ipmask";
                newAddr.subnet  = subnet;
                newAddr.comment = "auto-created by mock (addrgrp member)";
                m_addresses.push_back(newAddr);
                LOG_INFO("FORTINET", "Address auto-created for addrgrp member: " + memberName + " subnet=" + subnet);
            }
        };

        if (body.is_array()) {
            for (const auto& item : body)
                if (item.contains("name")) addMember(item["name"].get<std::string>());
        } else if (body.contains("name")) {
            addMember(body["name"].get<std::string>());
        } else if (body.contains("member") && body["member"].is_array()) {
            for (const auto& item : body["member"])
                if (item.contains("name")) addMember(item["name"].get<std::string>());
        }

        return makeSuccess(addrgrpToJson(*it), "POST");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::route(const ApiRequest& req) {
    LOG_DEBUG("FORTINET", "route: " + req.method + " " + req.path);

    const std::string& m = req.method;
    const std::string& p = req.path;

    const auto qmark = p.find('?');
    const std::string cp = (qmark == std::string::npos) ? p : p.substr(0, qmark);

    auto startsWith = [&](const std::string& prefix) {
        return cp.rfind(prefix, 0) == 0;
    };

    auto lastSegment = [&](const std::string& base) -> std::string {
        return cp.substr(base.size());
    };

    if (m == "POST" && cp == "/logincheck")
        return handleLoginCheck(req);
    if ((m == "POST" || m == "GET") && cp == "/logout")
        return handleLogout(req);

    if (m == "POST" && cp == "/fortinet/logincheck")
        return handleLoginCheck(req);
    if ((m == "POST" || m == "GET") && cp == "/fortinet/logout")
        return handleLogout(req);

    if (!isAuthenticated(req))
        return handleUnauthorized();

    if (m != "GET" && !validateCsrf(req))
        return handleForbidden("Missing or invalid CSRF token (X-CSRFTOKEN header required)");

    if (m == "GET" && (cp == "/api/v2/monitor/system/status"
                    || cp == "/fortinet/api/v2/monitor/system/status"))
        return handleSystemStatus(req);

    if (m == "GET" && (cp == "/api/v2/cmdb/system/global"
                    || cp == "/fortinet/api/v2/cmdb/system/global"))
        return handleSystemGlobal(req);

    for (const std::string addrBase : {"/api/v2/cmdb/firewall/address",
                                        "/fortinet/api/v2/cmdb/firewall/address"}) {
        const std::string addrNameBase = addrBase + "/";
        if (m == "GET"    && cp == addrBase)   return handleAddressList(req);
        if (m == "POST"   && cp == addrBase)   return handleAddressCreate(req);
        if (startsWith(addrNameBase)) {
            const std::string name = lastSegment(addrNameBase);
            if (!name.empty()) {
                if (m == "GET")    return handleAddressGet(req, name);
                if (m == "PUT")    return handleAddressUpdate(req, name);
                if (m == "DELETE") return handleAddressDelete(req, name);
            }
        }
    }

    for (const std::string grpBase : {"/api/v2/cmdb/firewall/addrgrp",
                                       "/fortinet/api/v2/cmdb/firewall/addrgrp"}) {
        const std::string grpNameBase = grpBase + "/";
        if (m == "GET"    && cp == grpBase)    return handleAddrgrpList(req);
        if (m == "POST"   && cp == grpBase)    return handleAddrgrpCreate(req);
        if (startsWith(grpNameBase)) {
            const std::string seg = lastSegment(grpNameBase);
            if (seg.empty()) continue;

            const std::string memberSuffix = "/member";
            if (seg.size() > memberSuffix.size() &&
                seg.substr(seg.size() - memberSuffix.size()) == memberSuffix) {
                const std::string grpName = seg.substr(0, seg.size() - memberSuffix.size());
                if (m == "GET")                      return handleAddrgrpMemberGet(req, grpName);
                if (m == "POST" || m == "PUT")       return handleAddrgrpMemberPost(req, grpName);
            } else {
                if (m == "GET")    return handleAddrgrpGet(req, seg);
                if (m == "PUT")    return handleAddrgrpUpdate(req, seg);
                if (m == "POST")   return handleAddrgrpUpdate(req, seg);
                if (m == "DELETE") return handleAddrgrpDelete(req, seg);
            }
        }
    }

    for (const std::string polBase : {"/api/v2/cmdb/firewall/policy",
                                       "/fortinet/api/v2/cmdb/firewall/policy"}) {
        const std::string polIdBase = polBase + "/";
        if (m == "GET"    && cp == polBase)    return handlePolicyList(req);
        if (m == "POST"   && cp == polBase)    return handlePolicyCreate(req);
        if (startsWith(polIdBase)) {
            const std::string pid = lastSegment(polIdBase);
            if (!pid.empty()) {
                if (m == "GET")    return handlePolicyGet(req, pid);
                if (m == "PUT")    return handlePolicyUpdate(req, pid);
                if (m == "DELETE") return handlePolicyDelete(req, pid);
            }
        }
    }

    for (const std::string bannedBase : {"/api/v2/monitor/user/banned",
                                          "/fortinet/api/v2/monitor/user/banned"}) {
        if (m == "GET" && (cp == bannedBase || cp == bannedBase + "/select"))
            return handleBannedList(req);
        if (m == "POST" && cp == bannedBase + "/add_users")
            return handleBannedAddUsers(req);
        if (m == "POST" && cp == bannedBase + "/clear_users")
            return handleBannedClearUsers(req);
        if (m == "POST" && cp == bannedBase + "/clear_all")
            return handleBannedClearAll(req);
    }

    return handleNotFound(req);
}

ApiResponse FortinetRouter::handleSystemStatus(const ApiRequest& req) {
    (void)req;
    return makeSuccess(json{
        {"model_name", "FortiGate-60F"},
        {"os_version", "FortiOS v6.4.9 build1966"},
        {"serial",     "FGT60F-MOCK-0001"},
        {"hostname",   "fortigate-60f"},
        {"uptime",     172800},
        {"cpu_usage",  8},
        {"mem_usage",  42}
    }.dump(), "GET");
}

ApiResponse FortinetRouter::handleSystemGlobal(const ApiRequest& req) {
    (void)req;
    return makeSuccess(json{
        {"hostname",      "fortigate-60f"},
        {"admintimeout",  480},
        {"timezone",      "Asia/Seoul"},
        {"language",      "korean"}
    }.dump(), "GET");
}

ApiResponse FortinetRouter::handleAddressList(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& e : m_addresses) arr.push_back(json::parse(addressToJson(e)));
    return makeSuccess(arr.dump(), "GET");
}

ApiResponse FortinetRouter::handleAddressCreate(const ApiRequest& req) {
    try {
        const auto body        = json::parse(req.body);
        const std::string name = body.value("name", "");
        if (name.empty()) return handleBadRequest("'name' is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        for (const auto& e : m_addresses)
            if (e.name == name) return makeError(409, "Address already exists: " + name);

        AddressEntry entry;
        entry.name    = name;
        entry.type    = body.value("type",    "ipmask");
        entry.subnet  = body.value("subnet",  "0.0.0.0 255.255.255.255");
        entry.comment = body.value("comment", "");
        m_addresses.push_back(entry);
        LOG_INFO("FORTINET", "Address created: " + name);
        return makeSuccess(addressToJson(entry), "POST");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handleAddressGet(const ApiRequest& req, const std::string& name) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    for (const auto& e : m_addresses)
        if (e.name == name) return makeSuccess(addressToJson(e), "GET");
    return makeError(404, "Address not found: " + name);
}

ApiResponse FortinetRouter::handleAddressUpdate(const ApiRequest& req, const std::string& name) {
    try {
        const auto body = json::parse(req.body);
        std::lock_guard<std::mutex> lk(m_mutex);
        for (auto& e : m_addresses) {
            if (e.name == name) {
                if (body.contains("subnet"))  e.subnet  = body["subnet"];
                if (body.contains("comment")) e.comment = body["comment"];
                if (body.contains("type"))    e.type    = body["type"];
                LOG_INFO("FORTINET", "Address updated: " + name);
                return makeSuccess(addressToJson(e), "PUT");
            }
        }
        return makeError(404, "Address not found: " + name);
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handleAddressDelete(const ApiRequest& req, const std::string& name) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    const auto it = std::remove_if(m_addresses.begin(), m_addresses.end(),
        [&](const AddressEntry& e){ return e.name == name; });
    if (it == m_addresses.end()) return makeError(404, "Address not found: " + name);
    m_addresses.erase(it, m_addresses.end());
    LOG_INFO("FORTINET", "Address deleted: " + name);
    return makeSuccess("{}", "DELETE");
}

ApiResponse FortinetRouter::handleAddrgrpList(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& e : m_addrgrps) arr.push_back(json::parse(addrgrpToJson(e)));
    return makeSuccess(arr.dump(), "GET");
}

ApiResponse FortinetRouter::handleAddrgrpCreate(const ApiRequest& req) {
    try {
        const auto body        = json::parse(req.body);
        const std::string name = body.value("name", "");
        if (name.empty()) return handleBadRequest("'name' is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        for (const auto& e : m_addrgrps)
            if (e.name == name) return makeError(409, "Addrgrp already exists: " + name);

        AddrgrpEntry entry;
        entry.name    = name;
        entry.comment = body.value("comment", "");
        if (body.contains("member") && body["member"].is_array())
            for (const auto& mbr : body["member"])
                if (mbr.contains("name")) entry.members.push_back(mbr["name"]);
        m_addrgrps.push_back(entry);
        LOG_INFO("FORTINET", "Addrgrp created: " + name);
        return makeSuccess(addrgrpToJson(entry), "POST");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handleAddrgrpGet(const ApiRequest& req, const std::string& name) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);

    auto it = std::find_if(m_addrgrps.begin(), m_addrgrps.end(),
        [&](const AddrgrpEntry& e){ return e.name == name; });
    if (it == m_addrgrps.end()) {
        AddrgrpEntry newGrp;
        newGrp.name    = name;
        newGrp.comment = "auto-created by mock";
        m_addrgrps.push_back(newGrp);
        LOG_INFO("FORTINET", "Addrgrp auto-created on GET: " + name);
        return makeSuccess(addrgrpToJson(m_addrgrps.back()), "GET");
    }
    return makeSuccess(addrgrpToJson(*it), "GET");
}

ApiResponse FortinetRouter::handleAddrgrpUpdate(const ApiRequest& req, const std::string& name) {
    try {
        const auto body = json::parse(req.body);
        std::lock_guard<std::mutex> lk(m_mutex);

        auto it = std::find_if(m_addrgrps.begin(), m_addrgrps.end(),
            [&](const AddrgrpEntry& e){ return e.name == name; });
        if (it == m_addrgrps.end()) {
            AddrgrpEntry newGrp;
            newGrp.name    = name;
            newGrp.comment = "auto-created by mock";
            m_addrgrps.push_back(newGrp);
            it = m_addrgrps.end() - 1;
            LOG_INFO("FORTINET", "Addrgrp auto-created on UPDATE: " + name);
        }

        if (body.contains("member") && body["member"].is_array()) {
            it->members.clear();
            for (const auto& mbr : body["member"])
                if (mbr.contains("name")) it->members.push_back(mbr["name"]);
        }
        if (body.contains("comment")) it->comment = body["comment"];
        LOG_INFO("FORTINET", "Addrgrp updated: " + name);
        return makeSuccess(addrgrpToJson(*it), "PUT");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handleAddrgrpDelete(const ApiRequest& req, const std::string& name) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    const auto it = std::remove_if(m_addrgrps.begin(), m_addrgrps.end(),
        [&](const AddrgrpEntry& e){ return e.name == name; });
    if (it == m_addrgrps.end()) return makeError(404, "Addrgrp not found: " + name);
    m_addrgrps.erase(it, m_addrgrps.end());
    LOG_INFO("FORTINET", "Addrgrp deleted: " + name);
    return makeSuccess("{}", "DELETE");
}

ApiResponse FortinetRouter::handlePolicyList(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& e : m_policies) arr.push_back(json::parse(policyToJson(e)));
    return makeSuccess(arr.dump(), "GET");
}

ApiResponse FortinetRouter::handlePolicyCreate(const ApiRequest& req) {
    try {
        json body = json::parse(req.body);
        if (body.contains("json") && body["json"].is_object())
            body = body["json"];

        std::lock_guard<std::mutex> lk(m_mutex);
        PolicyEntry entry;
        entry.policyid = m_nextPolicyId++;
        entry.name     = body.value("name",     "policy-" + std::to_string(entry.policyid));
        entry.srcintf  = body.contains("srcintf") && body["srcintf"].is_array() ?
                         body["srcintf"][0].value("name", "any") : "any";
        entry.dstintf  = body.contains("dstintf") && body["dstintf"].is_array() ?
                         body["dstintf"][0].value("name", "any") : "any";
        entry.srcaddr  = body.contains("srcaddr") && body["srcaddr"].is_array() ?
                         body["srcaddr"][0].value("name", "all") : "all";
        entry.dstaddr  = body.contains("dstaddr") && body["dstaddr"].is_array() ?
                         body["dstaddr"][0].value("name", "all") : "all";
        entry.action   = body.value("action",    "deny");
        entry.schedule = body.value("schedule",  "always");
        entry.service  = body.contains("service") && body["service"].is_array() ?
                         body["service"][0].value("name", "ALL") : "ALL";
        entry.status   = (body.value("status", "enable") == "enable") ? 1 : 0;
        m_policies.push_back(entry);
        LOG_INFO("FORTINET", "Policy created: id=" + std::to_string(entry.policyid));
        return makeSuccess(policyToJson(entry), "POST");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handlePolicyGet(const ApiRequest& req, const std::string& policyid) {
    (void)req;
    try {
        const int pid = std::stoi(policyid);
        std::lock_guard<std::mutex> lk(m_mutex);
        for (const auto& e : m_policies)
            if (e.policyid == pid) return makeSuccess(policyToJson(e), "GET");
        return makeError(404, "Policy not found: " + policyid);
    } catch (...) {
        return handleBadRequest("Invalid policyid: " + policyid);
    }
}

ApiResponse FortinetRouter::handlePolicyUpdate(const ApiRequest& req, const std::string& policyid) {
    try {
        const int  pid  = std::stoi(policyid);
        json body = json::parse(req.body);
        if (body.contains("json") && body["json"].is_object())
            body = body["json"];

        std::lock_guard<std::mutex> lk(m_mutex);
        for (auto& e : m_policies) {
            if (e.policyid == pid) {
                if (body.contains("action")) e.action = body["action"];
                if (body.contains("status")) e.status = (body["status"] == "enable") ? 1 : 0;
                if (body.contains("srcaddr") && body["srcaddr"].is_array())
                    e.srcaddr = body["srcaddr"][0].value("name", e.srcaddr);
                if (body.contains("dstaddr") && body["dstaddr"].is_array())
                    e.dstaddr = body["dstaddr"][0].value("name", e.dstaddr);
                if (body.contains("srcintf") && body["srcintf"].is_array())
                    e.srcintf = body["srcintf"][0].value("name", e.srcintf);
                if (body.contains("dstintf") && body["dstintf"].is_array())
                    e.dstintf = body["dstintf"][0].value("name", e.dstintf);
                LOG_INFO("FORTINET", "Policy updated: id=" + policyid);
                return makeSuccess(policyToJson(e), "PUT");
            }
        }
        return makeError(404, "Policy not found: " + policyid);
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handlePolicyDelete(const ApiRequest& req, const std::string& policyid) {
    (void)req;
    try {
        const int pid = std::stoi(policyid);
        std::lock_guard<std::mutex> lk(m_mutex);
        const auto it = std::remove_if(m_policies.begin(), m_policies.end(),
            [&](const PolicyEntry& e){ return e.policyid == pid; });
        if (it == m_policies.end()) return makeError(404, "Policy not found: " + policyid);
        m_policies.erase(it, m_policies.end());
        LOG_INFO("FORTINET", "Policy deleted: id=" + policyid);
        return makeSuccess("{}", "DELETE");
    } catch (...) {
        return handleBadRequest("Invalid policyid: " + policyid);
    }
}

ApiResponse FortinetRouter::handleBannedAddUsers(const ApiRequest& req) {
    try {
        const auto body = json::parse(req.body);
        if (!body.contains("ip_addresses") || !body["ip_addresses"].is_array())
            return handleBadRequest("'ip_addresses' array is required");

        const int expiry = body.value("expiry", 0);
        std::lock_guard<std::mutex> lk(m_mutex);
        int added = 0;
        for (const auto& ip_val : body["ip_addresses"]) {
            const std::string ip = ip_val.get<std::string>();
            const auto it = std::find_if(m_banned.begin(), m_banned.end(),
                [&](const BannedEntry& e){ return e.ip == ip; });
            if (it != m_banned.end()) continue;
            BannedEntry entry;
            entry.ip             = ip;
            entry.created        = nowUnix();
            entry.expiresSeconds = expiry;
            m_banned.push_back(entry);
            ++added;
            LOG_INFO("FORTINET", "Banned IP added: " + ip);
        }
        return makeSuccess(json{{"added", added}}.dump(), "POST");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handleBannedClearUsers(const ApiRequest& req) {
    try {
        const auto body = json::parse(req.body);
        if (!body.contains("ip_addresses") || !body["ip_addresses"].is_array())
            return handleBadRequest("'ip_addresses' array is required");

        std::lock_guard<std::mutex> lk(m_mutex);
        int removed = 0;
        for (const auto& ip_val : body["ip_addresses"]) {
            const std::string ip = ip_val.get<std::string>();
            const auto it = std::remove_if(m_banned.begin(), m_banned.end(),
                [&](const BannedEntry& e){ return e.ip == ip; });
            if (it != m_banned.end()) {
                m_banned.erase(it, m_banned.end());
                ++removed;
                LOG_INFO("FORTINET", "Banned IP cleared: " + ip);
            }
        }
        return makeSuccess(json{{"removed", removed}}.dump(), "POST");
    } catch (const std::exception& e) {
        return handleBadRequest(e.what());
    }
}

ApiResponse FortinetRouter::handleBannedClearAll(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    const int removed = static_cast<int>(m_banned.size());
    m_banned.clear();
    LOG_INFO("FORTINET", "All banned IPs cleared: count=" + std::to_string(removed));
    return makeSuccess(json{{"removed", removed}}.dump(), "POST");
}

ApiResponse FortinetRouter::handleBannedList(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& e : m_banned) {
        arr.push_back({
            {"ip",              e.ip},
            {"created",         e.created},
            {"expires_seconds", e.expiresSeconds}
        });
    }
    return makeSuccess(json{{"ban_list", arr}, {"total", static_cast<int>(arr.size())}}.dump(), "GET");
}
