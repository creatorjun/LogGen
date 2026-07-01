// src/engine/NexGfwRouter.cpp
#include "NexGfwRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>

using json = nlohmann::json;

static constexpr const char* NEXGFW_ADMIN_ID = "admin";
static constexpr const char* NEXGFW_ADMIN_PW = "admin1234!";
static constexpr const char* CONTENT_XML     = "application/xml";

NexGfwRouter::NexGfwRouter() {
    PolicyEntry defaultDeny;
    defaultDeny.id          = "0x3e001000000001";
    defaultDeny.name        = "DEFAULT_DENY";
    defaultDeny.description = "Default deny all policy";
    defaultDeny.action      = "deny";
    defaultDeny.szone       = "any";
    defaultDeny.dzone       = "any";
    defaultDeny.snetworks   = "any";
    defaultDeny.dnetworks   = "any";
    defaultDeny.active      = true;
    m_policies[defaultDeny.id] = defaultDeny;
}

std::string NexGfwRouter::xmlSuccess(const std::string& code,
                                      const std::string& msg,
                                      const std::string& extra)
{
    std::string xml =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<results>\n"
        "  <type>0x0000</type>\n"
        "  <code>" + code + "</code>\n"
        "  <msg>" + msg + "</msg>\n";
    if (!extra.empty())
        xml += extra;
    xml += "</results>\n";
    return xml;
}

std::string NexGfwRouter::xmlError(const std::string& code,
                                    const std::string& msg)
{
    return
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<results>\n"
        "  <type>0x0001</type>\n"
        "  <code>" + code + "</code>\n"
        "  <msg>" + msg + "</msg>\n"
        "</results>\n";
}

std::string NexGfwRouter::makeObjId() {
    static std::mt19937_64 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    uint64_t val = rng();
    std::ostringstream oss;
    oss << "0x" << std::hex << std::uppercase << val;
    return oss.str();
}

std::string NexGfwRouter::createSession() {
    static std::mt19937_64 rng(
        std::chrono::steady_clock::now().time_since_epoch().count()
        ^ (std::chrono::high_resolution_clock::now().time_since_epoch().count() << 1));
    std::ostringstream oss;
    oss << std::hex << std::uppercase << rng();
    std::string sessionToken = oss.str();
    std::lock_guard<std::mutex> lk(m_sessionMutex);
    m_sessions.insert(sessionToken);
    return sessionToken;
}

void NexGfwRouter::removeSession(const std::string& sessionToken) {
    std::lock_guard<std::mutex> lk(m_sessionMutex);
    m_sessions.erase(sessionToken);
}

bool NexGfwRouter::isAuthenticated(const ApiRequest& req) const {
    const auto it = req.headers.find("AuthKey");
    if (it == req.headers.end()) return false;
    std::lock_guard<std::mutex> lk(m_sessionMutex);
    return m_sessions.count(it->second) > 0;
}

ApiResponse NexGfwRouter::handleUnauthorized() {
    ApiResponse resp;
    resp.statusCode  = 401;
    resp.contentType = CONTENT_XML;
    resp.body        = xmlError("0x0002", "Not Logined");
    return resp;
}

ApiResponse NexGfwRouter::handleNotFound(const ApiRequest& req) {
    LOG_WARN("NEXGFW", "Unmatched route: " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode  = 404;
    resp.contentType = CONTENT_XML;
    resp.body        = xmlError("0x0004", "Not found: " + req.path);
    return resp;
}

ApiResponse NexGfwRouter::route(const ApiRequest& req) {
    LOG_DEBUG("NEXGFW", "route: " + req.method + " " + req.path);

    const std::string& m = req.method;
    const std::string& p = req.path;

    auto startsWith = [&](const std::string& prefix) {
        return p.rfind(prefix, 0) == 0;
    };

    if (m == "POST" && p == "/nexgfw/default/api/login")
        return handleLogin(req);
    if (m == "POST" && p == "/nexgfw/default/api/logout")
        return handleLogout(req);
    if (m == "POST" && p == "/nexgfw/default/api/apply")
        return handleApply(req);
    if (m == "POST" && p == "/nexgfw/default/api/restore")
        return handleRestore(req);

    if (m == "GET"    && p == "/nexgfw/objects/network/api/networks/get")
        return handleNetworkGet(req);
    if (m == "POST"   && p == "/nexgfw/objects/network/api/networks/set")
        return handleNetworkSet(req);
    if (m == "PUT"    && p == "/nexgfw/objects/network/api/networks/update")
        return handleNetworkUpdate(req);
    if (m == "DELETE" && p == "/nexgfw/objects/network/api/networks/delete")
        return handleNetworkDelete(req);

    if (m == "GET"    && startsWith("/nexgfw/policies/blacklist/api/blacklist") && p.find("get") != std::string::npos)
        return handleBlacklistGet(req);
    if (m == "POST"   && p == "/nexgfw/policies/blacklist/api/blacklist/set")
        return handleBlacklistSet(req);
    if (m == "PUT"    && p == "/nexgfw/policies/blacklist/api/blacklist/update")
        return handleBlacklistUpdate(req);
    if (m == "POST"   && p == "/nexgfw/policies/blacklist/api/blacklist/enable")
        return handleBlacklistEnable(req);
    if (m == "DELETE" && p == "/nexgfw/policies/blacklist/api/blacklist/delete")
        return handleBlacklistDelete(req);

    if (m == "GET"    && p == "/nexgfw/policies/base/api/get")
        return handleBasePolicyGet(req);
    if (m == "POST"   && p == "/nexgfw/policies/base/api/set")
        return handleBasePolicySet(req);
    if (m == "PUT"    && p == "/nexgfw/policies/base/api/update")
        return handleBasePolicyUpdate(req);
    if (m == "POST"   && p == "/nexgfw/policies/base/api/enable")
        return handleBasePolicyEnable(req);
    if (m == "DELETE" && p == "/nexgfw/policies/base/api/delete")
        return handleBasePolicyDelete(req);

    return handleNotFound(req);
}

ApiResponse NexGfwRouter::handleLogin(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    try {
        const auto body = json::parse(req.body);
        const std::string id = body.value("id", "");
        const std::string pw = body.value("pw", "");
        if (id == NEXGFW_ADMIN_ID && pw == NEXGFW_ADMIN_PW) {
            const std::string sessionToken = createSession();
            LOG_INFO("NEXGFW", "Login succeeded, token=" + sessionToken);
            resp.statusCode = 200;
            resp.body = xmlSuccess("0x0001", "Login Succeeded",
                "  <token>" + sessionToken + "</token>\n");
        } else {
            LOG_WARN("NEXGFW", "Login failed: id=" + id);
            resp.statusCode = 401;
            resp.body = xmlError("0x0022", "ID/PW Validation Failed");
        }
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleLogin parse error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x0003", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleLogout(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    const auto it = req.headers.find("AuthKey");
    if (it == req.headers.end() || it->second.empty()) {
        resp.statusCode = 401;
        resp.body = xmlError("0x0101", "Logout Failed session null");
        return resp;
    }
    removeSession(it->second);
    LOG_INFO("NEXGFW", "Logout: token=" + it->second);
    resp.statusCode = 200;
    resp.body = xmlSuccess("0x0100", "Logout Succeeded");
    return resp;
}

ApiResponse NexGfwRouter::handleApply(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    LOG_INFO("NEXGFW", "Apply called");
    resp.statusCode = 200;
    resp.body = xmlSuccess("0x0200", "Apply Succeeded");
    return resp;
}

ApiResponse NexGfwRouter::handleRestore(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    LOG_INFO("NEXGFW", "Restore called");
    resp.statusCode = 200;
    resp.body = xmlSuccess("0x0220", "Restore Succeeded");
    return resp;
}

ApiResponse NexGfwRouter::handleNetworkGet(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();

    std::lock_guard<std::mutex> lk(m_dataMutex);
    std::string items;
    for (const auto& [id, obj] : m_networkObjs) {
        items +=
            "  <net-obj>\n"
            "    <id>" + obj.id + "</id>\n"
            "    <name>" + obj.name + "</name>\n"
            "    <version>" + obj.version + "</version>\n"
            "    <description>" + obj.description + "</description>\n"
            "    <member><address-cidr>" + obj.addresses + "</address-cidr></member>\n"
            "  </net-obj>\n";
    }
    const std::string total = std::to_string(m_networkObjs.size());
    resp.statusCode = 200;
    resp.body =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<net-objs>\n" + items +
        "  <total>" + total + "</total>\n"
        "</net-objs>\n";
    return resp;
}

ApiResponse NexGfwRouter::handleNetworkSet(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string name = body.value("name", "");
        if (name.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x4020", "Name is required");
            return resp;
        }
        std::lock_guard<std::mutex> lk(m_dataMutex);
        for (const auto& [id, obj] : m_networkObjs) {
            if (obj.name == name) {
                resp.statusCode = 400;
                resp.body = xmlError("0x4027", "Name is duplicated " + name);
                return resp;
            }
        }
        NetObj obj;
        obj.id          = makeObjId();
        obj.name        = name;
        obj.description = body.value("description", "");
        obj.version     = body.value("version", "ipv4");
        if (body.contains("addresses") && body["addresses"].is_object()) {
            if (body["addresses"].contains("host") && body["addresses"]["host"].is_array()) {
                for (const auto& h : body["addresses"]["host"])
                    obj.addresses += h.value("value", "") + " ";
            }
            if (body["addresses"].contains("cidr") && body["addresses"]["cidr"].is_array()) {
                for (const auto& c : body["addresses"]["cidr"])
                    obj.addresses += c.value("value", "") + " ";
            }
        } else if (body.contains("addresses") && body["addresses"].is_string()) {
            obj.addresses = body["addresses"].get<std::string>();
        }
        if (!obj.addresses.empty() && obj.addresses.back() == ' ')
            obj.addresses.pop_back();
        m_networkObjs[obj.id] = obj;
        LOG_INFO("NEXGFW", "NetworkObj created: id=" + obj.id + " name=" + obj.name);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x4021", "Objects-network Set Succeeded",
            "  <id>" + obj.id + "</id>\n");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleNetworkSet error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x4000", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleNetworkUpdate(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string id = body.value("id", "");
        std::lock_guard<std::mutex> lk(m_dataMutex);
        auto it = m_networkObjs.find(id);
        if (it == m_networkObjs.end()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x4056", "Id is not exist " + id);
            return resp;
        }
        if (body.contains("name"))        it->second.name        = body["name"].get<std::string>();
        if (body.contains("description")) it->second.description = body["description"].get<std::string>();
        if (body.contains("version"))     it->second.version     = body["version"].get<std::string>();
        if (body.contains("addresses")) {
            if (body["addresses"].is_object()) {
                it->second.addresses.clear();
                if (body["addresses"].contains("host") && body["addresses"]["host"].is_array()) {
                    for (const auto& h : body["addresses"]["host"])
                        it->second.addresses += h.value("value", "") + " ";
                }
                if (body["addresses"].contains("cidr") && body["addresses"]["cidr"].is_array()) {
                    for (const auto& c : body["addresses"]["cidr"])
                        it->second.addresses += c.value("value", "") + " ";
                }
                if (!it->second.addresses.empty() && it->second.addresses.back() == ' ')
                    it->second.addresses.pop_back();
            } else if (body["addresses"].is_string()) {
                it->second.addresses = body["addresses"].get<std::string>();
            }
        }
        LOG_INFO("NEXGFW", "NetworkObj updated: id=" + id);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x4051", "Objects-network Update Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleNetworkUpdate error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x4000", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleNetworkDelete(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string ids = body.value("ids", "");
        std::lock_guard<std::mutex> lk(m_dataMutex);
        std::istringstream iss(ids);
        std::string entry;
        std::vector<std::string> notFound;
        while (std::getline(iss, entry, ',')) {
            while (!entry.empty() && entry.front() == ' ') entry.erase(entry.begin());
            while (!entry.empty() && entry.back()  == ' ') entry.pop_back();
            if (m_networkObjs.erase(entry) == 0)
                notFound.push_back(entry);
        }
        if (!notFound.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x4087", "Ids is not exist " + notFound.front());
            return resp;
        }
        LOG_INFO("NEXGFW", "NetworkObj deleted: ids=" + ids);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x4081", "Objects-network Delete Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleNetworkDelete error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x4000", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBlacklistGet(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();

    std::lock_guard<std::mutex> lk(m_dataMutex);
    std::string items;
    for (const auto& [id, bl] : m_blacklists) {
        items +=
            "  <blacklist>\n"
            "    <id>" + bl.id + "</id>\n"
            "    <name>" + bl.name + "</name>\n"
            "    <description>" + bl.description + "</description>\n"
            "    <type>" + bl.type + "</type>\n"
            "    <target>" + bl.target + "</target>\n"
            "    <method>" + bl.method + "</method>\n"
            "    <members>" + bl.members + "</members>\n"
            "    <active>" + (bl.active ? "true" : "false") + "</active>\n"
            "  </blacklist>\n";
    }
    const std::string total = std::to_string(m_blacklists.size());
    resp.statusCode = 200;
    resp.body =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<blacklists>\n" + items +
        "  <total>" + total + "</total>\n"
        "</blacklists>\n";
    return resp;
}

ApiResponse NexGfwRouter::handleBlacklistSet(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string name = body.value("name", "");
        if (name.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1820", "Name is required");
            return resp;
        }
        const std::string method = body.value("method", "");
        if (method != "block" && method != "exclude") {
            resp.statusCode = 400;
            resp.body = xmlError("0x1823", "Method is invalid " + method);
            return resp;
        }
        std::lock_guard<std::mutex> lk(m_dataMutex);
        for (const auto& [id, bl] : m_blacklists) {
            if (bl.name == name) {
                resp.statusCode = 400;
                resp.body = xmlError("0x1827", "Name is duplicated " + name);
                return resp;
            }
        }
        BlacklistEntry bl;
        bl.id          = makeObjId();
        bl.name        = name;
        bl.description = body.value("description", "");
        bl.type        = body.value("type", "host");
        bl.target      = body.value("target", "src");
        bl.method      = method;
        if (body.contains("members") && body["members"].is_array()) {
            for (const auto& mem : body["members"])
                bl.members += mem.get<std::string>() + ",";
            if (!bl.members.empty()) bl.members.pop_back();
        } else if (body.contains("members") && body["members"].is_string()) {
            bl.members = body["members"].get<std::string>();
        }
        bl.active = body.value("active", true);
        m_blacklists[bl.id] = bl;
        LOG_INFO("NEXGFW", "Blacklist created: id=" + bl.id + " name=" + bl.name + " members=" + bl.members);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1821", "Policies Blacklist Set Succeeded",
            "  <id>" + bl.id + "</id>\n");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBlacklistSet error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1800", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBlacklistUpdate(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string id = body.value("id", "");
        std::lock_guard<std::mutex> lk(m_dataMutex);
        auto it = m_blacklists.find(id);
        if (it == m_blacklists.end()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1855", "Id is not exist " + id);
            return resp;
        }
        if (body.contains("name"))        it->second.name        = body["name"].get<std::string>();
        if (body.contains("description")) it->second.description = body["description"].get<std::string>();
        if (body.contains("type"))        it->second.type        = body["type"].get<std::string>();
        if (body.contains("target"))      it->second.target      = body["target"].get<std::string>();
        if (body.contains("method")) {
            const std::string mval = body["method"].get<std::string>();
            if (mval != "block" && mval != "exclude") {
                resp.statusCode = 400;
                resp.body = xmlError("0x1855", "Method is invalid " + mval);
                return resp;
            }
            it->second.method = mval;
        }
        if (body.contains("members") && body["members"].is_array()) {
            it->second.members.clear();
            for (const auto& mem : body["members"])
                it->second.members += mem.get<std::string>() + ",";
            if (!it->second.members.empty()) it->second.members.pop_back();
        } else if (body.contains("members") && body["members"].is_string()) {
            it->second.members = body["members"].get<std::string>();
        }
        if (body.contains("active")) it->second.active = body["active"].get<bool>();
        LOG_INFO("NEXGFW", "Blacklist updated: id=" + id);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1851", "Policies Blacklist Update Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBlacklistUpdate error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1800", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBlacklistEnable(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body   = json::parse(req.body);
        const std::string ids    = body.value("ids", "");
        const bool        enable = body.value("enable", true);
        std::lock_guard<std::mutex> lk(m_dataMutex);
        std::istringstream iss(ids);
        std::string entry;
        std::vector<std::string> notFound;
        while (std::getline(iss, entry, ',')) {
            while (!entry.empty() && entry.front() == ' ') entry.erase(entry.begin());
            while (!entry.empty() && entry.back()  == ' ') entry.pop_back();
            auto it = m_blacklists.find(entry);
            if (it == m_blacklists.end())
                notFound.push_back(entry);
            else
                it->second.active = enable;
        }
        if (!notFound.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1906", "Ids is not exist " + notFound.front());
            return resp;
        }
        LOG_INFO("NEXGFW", "Blacklist enable=" + std::to_string(enable) + " ids=" + ids);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1901", "Policies Blacklist Enable Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBlacklistEnable error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1900", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBlacklistDelete(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string ids = body.value("ids", "");
        std::lock_guard<std::mutex> lk(m_dataMutex);
        std::istringstream iss(ids);
        std::string entry;
        std::vector<std::string> notFound;
        while (std::getline(iss, entry, ',')) {
            while (!entry.empty() && entry.front() == ' ') entry.erase(entry.begin());
            while (!entry.empty() && entry.back()  == ' ') entry.pop_back();
            if (m_blacklists.erase(entry) == 0)
                notFound.push_back(entry);
        }
        if (!notFound.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1886", "Ids is not exist " + notFound.front());
            return resp;
        }
        LOG_INFO("NEXGFW", "Blacklist deleted: ids=" + ids);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1881", "Policies Blacklist Delete Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBlacklistDelete error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1800", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBasePolicyGet(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();

    std::lock_guard<std::mutex> lk(m_dataMutex);
    std::string items;
    for (const auto& [id, pol] : m_policies) {
        items +=
            "  <ipv4-rule>\n"
            "    <id>" + pol.id + "</id>\n"
            "    <name>" + pol.name + "</name>\n"
            "    <description>" + pol.description + "</description>\n"
            "    <action>" + pol.action + "</action>\n"
            "    <szone>" + pol.szone + "</szone>\n"
            "    <dzone>" + pol.dzone + "</dzone>\n"
            "    <snetworks>" + pol.snetworks + "</snetworks>\n"
            "    <dnetworks>" + pol.dnetworks + "</dnetworks>\n"
            "    <active>" + (pol.active ? "true" : "false") + "</active>\n"
            "  </ipv4-rule>\n";
    }
    const std::string total = std::to_string(m_policies.size());
    resp.statusCode = 200;
    resp.body =
        "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
        "<ipv4-rules>\n" + items +
        "  <total>" + total + "</total>\n"
        "</ipv4-rules>\n";
    return resp;
}

ApiResponse NexGfwRouter::handleBasePolicySet(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string name = body.value("name", "");
        if (name.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1020", "Name is required");
            return resp;
        }
        const std::string action = body.value("action", "");
        if (action != "allow" && action != "deny") {
            resp.statusCode = 400;
            resp.body = xmlError("0x1022", "Action is invalid " + action);
            return resp;
        }
        std::lock_guard<std::mutex> lk(m_dataMutex);
        for (const auto& [id, pol] : m_policies) {
            if (pol.name == name) {
                resp.statusCode = 400;
                resp.body = xmlError("0x1027", "Name is duplicated " + name);
                return resp;
            }
        }
        PolicyEntry pol;
        pol.id          = makeObjId();
        pol.name        = name;
        pol.description = body.value("description", "");
        pol.action      = action;
        pol.szone       = body.value("szone", "any");
        pol.dzone       = body.value("dzone", "any");
        pol.snetworks   = body.value("snetworks", "any");
        pol.dnetworks   = body.value("dnetworks", "any");
        pol.active      = body.value("active", true);
        m_policies[pol.id] = pol;
        LOG_INFO("NEXGFW", "BasePolicy created: id=" + pol.id + " name=" + pol.name + " action=" + pol.action);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1021", "Policies Set Succeeded",
            "  <id>" + pol.id + "</id>\n");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBasePolicySet error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1000", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBasePolicyUpdate(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string id = body.value("id", "");
        std::lock_guard<std::mutex> lk(m_dataMutex);
        auto it = m_policies.find(id);
        if (it == m_policies.end()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1056", "ID is not exist " + id);
            return resp;
        }
        if (body.contains("name"))        it->second.name        = body["name"].get<std::string>();
        if (body.contains("description")) it->second.description = body["description"].get<std::string>();
        if (body.contains("action")) {
            const std::string aval = body["action"].get<std::string>();
            if (aval != "allow" && aval != "deny") {
                resp.statusCode = 400;
                resp.body = xmlError("0x1056", "Action is invalid " + aval);
                return resp;
            }
            it->second.action = aval;
        }
        if (body.contains("szone"))     it->second.szone     = body["szone"].get<std::string>();
        if (body.contains("dzone"))     it->second.dzone     = body["dzone"].get<std::string>();
        if (body.contains("snetworks")) it->second.snetworks = body["snetworks"].get<std::string>();
        if (body.contains("dnetworks")) it->second.dnetworks = body["dnetworks"].get<std::string>();
        if (body.contains("active"))    it->second.active    = body["active"].get<bool>();
        LOG_INFO("NEXGFW", "BasePolicy updated: id=" + id);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1051", "Policies Update Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBasePolicyUpdate error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1000", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBasePolicyEnable(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body   = json::parse(req.body);
        const std::string ids    = body.value("ids", "");
        const bool        enable = body.value("enable", true);
        std::lock_guard<std::mutex> lk(m_dataMutex);
        std::istringstream iss(ids);
        std::string entry;
        std::vector<std::string> notFound;
        while (std::getline(iss, entry, ',')) {
            while (!entry.empty() && entry.front() == ' ') entry.erase(entry.begin());
            while (!entry.empty() && entry.back()  == ' ') entry.pop_back();
            auto it = m_policies.find(entry);
            if (it == m_policies.end())
                notFound.push_back(entry);
            else
                it->second.active = enable;
        }
        if (!notFound.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1049", "Ids is not exist " + notFound.front());
            return resp;
        }
        LOG_INFO("NEXGFW", "BasePolicy enable=" + std::to_string(enable) + " ids=" + ids);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1042", "Policies Enable Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBasePolicyEnable error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1000", "Invalid request body");
    }
    return resp;
}

ApiResponse NexGfwRouter::handleBasePolicyDelete(const ApiRequest& req) {
    ApiResponse resp;
    resp.contentType = CONTENT_XML;
    if (!isAuthenticated(req)) return handleUnauthorized();
    try {
        const auto body = json::parse(req.body);
        const std::string ids = body.value("ids", "");
        std::lock_guard<std::mutex> lk(m_dataMutex);
        std::istringstream iss(ids);
        std::string entry;
        std::vector<std::string> notFound;
        while (std::getline(iss, entry, ',')) {
            while (!entry.empty() && entry.front() == ' ') entry.erase(entry.begin());
            while (!entry.empty() && entry.back()  == ' ') entry.pop_back();
            if (m_policies.erase(entry) == 0)
                notFound.push_back(entry);
        }
        if (!notFound.empty()) {
            resp.statusCode = 400;
            resp.body = xmlError("0x1207", "Ids is not exist " + notFound.front());
            return resp;
        }
        LOG_INFO("NEXGFW", "BasePolicy deleted: ids=" + ids);
        resp.statusCode = 200;
        resp.body = xmlSuccess("0x1201", "Policies Delete Succeeded");
    } catch (const std::exception& e) {
        LOG_WARN("NEXGFW", "handleBasePolicyDelete error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = xmlError("0x1000", "Invalid request body");
    }
    return resp;
}
