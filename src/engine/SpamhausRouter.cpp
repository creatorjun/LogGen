// src/engine/SpamhausRouter.cpp
#include "SpamhausRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>

using json = nlohmann::json;

static constexpr const char* SH_MOCK_USER  = "admin@soar.local";
static constexpr const char* SH_MOCK_PASS  = "spamhaus1234!";
static constexpr int64_t     TOKEN_TTL_SEC = 86400;

static const std::vector<std::string> LISTED_IPS = {
    "127.0.0.2",
    "45.150.206.114",
    "74.77.66.227",
    "185.220.101.1",
    "192.168.100.200",
    "10.0.0.99"
};

static const std::vector<std::string> LISTED_DOMAINS = {
    "malware.example.com",
    "phishing.test.org",
    "c2server.bad",
    "spam-relay.net",
    "botnet-c2.ru"
};

SpamhausRouter::SpamhausRouter() {}

std::string SpamhausRouter::makeToken() {
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

int64_t SpamhausRouter::nowUnix() {
    return static_cast<int64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());
}

std::string SpamhausRouter::nowIso8601() {
    const auto now = std::chrono::system_clock::now();
    const auto tt  = std::chrono::system_clock::to_time_t(now);
    struct tm tm_buf{};
#ifdef _WIN32
    gmtime_s(&tm_buf, &tt);
#else
    gmtime_r(&tt, &tm_buf);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%dT%H:%M:%SZ");
    return oss.str();
}

std::string SpamhausRouter::createToken(const std::string& username) {
    const std::string tok = makeToken();
    TokenEntry entry;
    entry.username = username;
    entry.expires  = nowUnix() + TOKEN_TTL_SEC;
    std::lock_guard<std::mutex> lk(m_mutex);
    m_tokens[tok] = entry;
    return tok;
}

void SpamhausRouter::removeToken(const std::string& token) {
    std::lock_guard<std::mutex> lk(m_mutex);
    m_tokens.erase(token);
}

bool SpamhausRouter::isAuthenticated(const ApiRequest& req) const {
    auto check = [&](const std::string& key) -> bool {
        const auto it = req.headers.find(key);
        if (it == req.headers.end()) return false;
        const std::string& val = it->second;
        const std::string prefix = "Bearer ";
        if (val.rfind(prefix, 0) != 0) return false;
        const std::string token = val.substr(prefix.size());
        std::lock_guard<std::mutex> lk(m_mutex);
        const auto jt = m_tokens.find(token);
        if (jt == m_tokens.end()) return false;
        return jt->second.expires > nowUnix();
    };
    return check("Authorization") || check("authorization");
}

ApiResponse SpamhausRouter::handleUnauthorized() {
    ApiResponse resp;
    resp.statusCode = 401;
    resp.body = json{{"code", 401}, {"message", "Authentication failed"}}.dump();
    return resp;
}

ApiResponse SpamhausRouter::handleNotFound(const ApiRequest& req) {
    LOG_WARN("SPAMHAUS", "Unmatched route: " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode = 404;
    resp.body = json{{"code", 404}, {"message", "Not found: " + req.path}}.dump();
    return resp;
}

ApiResponse SpamhausRouter::handleBadRequest(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode = 400;
    resp.body = json{{"code", 400}, {"message", msg}}.dump();
    return resp;
}

ApiResponse SpamhausRouter::route(const ApiRequest& req) {
    LOG_DEBUG("SPAMHAUS", "route: " + req.method + " " + req.path);

    const std::string& m = req.method;
    const std::string& p = req.path;

    auto startsWith = [&](const std::string& prefix) {
        return p.rfind(prefix, 0) == 0;
    };

    if (m == "POST" && p == "/spamhaus/api/v1/login")
        return handleLogin(req);
    if (m == "POST" && p == "/spamhaus/api/v1/logout")
        return handleLogout(req);

    if (!isAuthenticated(req))
        return handleUnauthorized();

    if (m == "GET" && p == "/spamhaus/api/intel/v1/limits")
        return handleLimits(req);

    if (m == "GET" && startsWith("/spamhaus/api/intel/v1/byobject/cidr/"))
        return handleIpLookup(req);

    if (m == "GET" && startsWith("/spamhaus/api/intel/v1/byobject/domain/"))
        return handleDomainLookup(req);

    return handleNotFound(req);
}

ApiResponse SpamhausRouter::handleLogin(const ApiRequest& req) {
    ApiResponse resp;
    try {
        const auto body     = json::parse(req.body);
        const std::string username = body.value("username", "");
        const std::string password = body.value("password", "");
        const std::string realm    = body.value("realm",    "");

        if (username != SH_MOCK_USER || password != SH_MOCK_PASS) {
            LOG_WARN("SPAMHAUS", "Login failed: username=" + username);
            resp.statusCode = 401;
            resp.body = json{{"code", 401}, {"message", "Authentication failed"}}.dump();
            return resp;
        }
        (void)realm;
        const std::string token   = createToken(username);
        const int64_t     expires = nowUnix() + TOKEN_TTL_SEC;
        LOG_INFO("SPAMHAUS", "Login succeeded: username=" + username);
        resp.statusCode = 200;
        resp.body = json{
            {"code",    200},
            {"token",   token},
            {"expires", expires}
        }.dump();
    } catch (const std::exception& e) {
        LOG_WARN("SPAMHAUS", "handleLogin error: " + std::string(e.what()));
        resp.statusCode = 400;
        resp.body = json{{"code", 400}, {"message", "Invalid request body"}}.dump();
    }
    return resp;
}

ApiResponse SpamhausRouter::handleLogout(const ApiRequest& req) {
    ApiResponse resp;
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
        LOG_INFO("SPAMHAUS", "Logout: token=" + token);
    }
    resp.statusCode = 200;
    resp.body = json{{"code", 200}, {"message", "Logout succeeded"}}.dump();
    return resp;
}

ApiResponse SpamhausRouter::handleLimits(const ApiRequest& req) {
    (void)req;
    std::lock_guard<std::mutex> lk(m_mutex);
    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"status", 200},
        {"account", {
            {"sub", "mock-sub-0001"},
            {"usr", SH_MOCK_USER}
        }},
        {"limits", {
            {"ads",     "XBL,SBL,CSS,BCL,DBL,ZRD,ALL"},
            {"trs",     "base"},
            {"qms",     1000},
            {"qmh",     1500},
            {"rl_qph",  3600},
            {"rl_qpm",  60},
            {"rl_qps",  1}
        }},
        {"current", {
            {"qpm",    m_queryCount},
            {"qpd",    m_queryCount},
            {"rl_qph", 0},
            {"rl_qpm", 0},
            {"rl_qps", 0}
        }}
    }.dump(2);
    return resp;
}

std::vector<SpamhausRouter::ListingRecord>
SpamhausRouter::buildIpRecords(const std::string& ip, const std::string& dataset) {
    const bool listed = std::find(
        LISTED_IPS.begin(), LISTED_IPS.end(), ip) != LISTED_IPS.end();

    if (!listed) return {};

    const int64_t now = static_cast<int64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());

    static const std::vector<std::pair<std::string,std::string>> DETECTIONS = {
        {"SMTP impersonation",    "IMPERSONATE"},
        {"Bot activity",          "BOTNET"},
        {"Spamming activity",     "SPAM"},
        {"Brute force attempt",   "BRUTEFORCE"},
        {"Port scanning",         "PORTSCAN"}
    };
    const std::size_t idx = std::hash<std::string>{}(ip) % DETECTIONS.size();

    ListingRecord rec;
    rec.dataset   = (dataset == "ALL") ? "XBL" : dataset;
    rec.ipaddress = ip;
    rec.asn       = "64512";
    rec.cc        = "RU";
    rec.listed    = now - 86400;
    rec.seen      = now - 86500;
    rec.valid_until = now + 604800;
    rec.botname   = "unknown";
    rec.detection = DETECTIONS[idx].first;
    rec.heuristic = DETECTIONS[idx].second;
    rec.dstport   = 25;
    return {rec};
}

std::vector<SpamhausRouter::ListingRecord>
SpamhausRouter::buildDomainRecords(const std::string& domain, const std::string& dataset) {
    const bool listed = std::find(
        LISTED_DOMAINS.begin(), LISTED_DOMAINS.end(), domain) != LISTED_DOMAINS.end();

    if (!listed) return {};

    const int64_t now = static_cast<int64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()).count());

    static const std::vector<std::pair<int,std::string>> DOMAIN_CODES = {
        {2002, "Domain used for spam"},
        {2004, "Phishing domain"},
        {2005, "Malware domain"},
        {2006, "Botnet C&C domain"},
        {2103, "Spam domain used as a redirector"}
    };
    const std::size_t idx = std::hash<std::string>{}(domain) % DOMAIN_CODES.size();

    ListingRecord rec;
    rec.dataset    = (dataset == "ALL") ? "DBL" : dataset;
    rec.domain     = domain;
    rec.listed     = now - 3600;
    rec.seen       = now - 3700;
    rec.valid_until = now + 604800;
    rec.detection  = DOMAIN_CODES[idx].second;
    rec.heuristic  = std::to_string(DOMAIN_CODES[idx].first);
    rec.dstport    = 0;
    return {rec};
}

ApiResponse SpamhausRouter::handleIpLookup(const ApiRequest& req) {
    const std::string base = "/spamhaus/api/intel/v1/byobject/cidr/";
    std::string remainder  = req.path.substr(base.size());

    auto popSegment = [&](std::string& s) -> std::string {
        const auto pos = s.find('/');
        if (pos == std::string::npos) {
            std::string seg = s;
            s.clear();
            return seg;
        }
        std::string seg = s.substr(0, pos);
        s = s.substr(pos + 1);
        return seg;
    };

    const std::string dataset = popSegment(remainder);
    const std::string mode    = popSegment(remainder);
    const std::string type    = popSegment(remainder);
    const std::string ip      = remainder;

    if (dataset.empty() || mode.empty() || type.empty() || ip.empty())
        return handleBadRequest("Missing path segments: /cidr/<DATASET>/<MODE>/<TYPE>/<IP>");

    LOG_DEBUG("SPAMHAUS", "IpLookup dataset=" + dataset + " ip=" + ip);

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        ++m_queryCount;
    }

    const auto records = buildIpRecords(ip, dataset);

    ApiResponse resp;
    if (records.empty()) {
        resp.statusCode = 200;
        resp.body = json{{"code", 404}}.dump();
        return resp;
    }

    json results = json::array();
    for (const auto& r : records) {
        results.push_back({
            {"dataset",     r.dataset},
            {"ipaddress",   r.ipaddress},
            {"asn",         r.asn},
            {"cc",          r.cc},
            {"listed",      r.listed},
            {"seen",        r.seen},
            {"valid_until", r.valid_until},
            {"botname",     r.botname},
            {"detection",   r.detection},
            {"dstport",     r.dstport},
            {"heuristic",   r.heuristic},
            {"srcip",       r.ipaddress}
        });
    }

    resp.statusCode = 200;
    resp.body = json{
        {"code",    200},
        {"results", results}
    }.dump(2);
    return resp;
}

ApiResponse SpamhausRouter::handleDomainLookup(const ApiRequest& req) {
    const std::string base = "/spamhaus/api/intel/v1/byobject/domain/";
    std::string remainder  = req.path.substr(base.size());

    auto popSegment = [&](std::string& s) -> std::string {
        const auto pos = s.find('/');
        if (pos == std::string::npos) {
            std::string seg = s;
            s.clear();
            return seg;
        }
        std::string seg = s.substr(0, pos);
        s = s.substr(pos + 1);
        return seg;
    };

    const std::string dataset = popSegment(remainder);
    const std::string mode    = popSegment(remainder);
    const std::string type    = popSegment(remainder);
    const std::string domain  = remainder;

    if (dataset.empty() || mode.empty() || type.empty() || domain.empty())
        return handleBadRequest("Missing path segments: /domain/<DATASET>/<MODE>/<TYPE>/<DOMAIN>");

    LOG_DEBUG("SPAMHAUS", "DomainLookup dataset=" + dataset + " domain=" + domain);

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        ++m_queryCount;
    }

    const auto records = buildDomainRecords(domain, dataset);

    ApiResponse resp;
    if (records.empty()) {
        resp.statusCode = 200;
        resp.body = json{{"code", 404}}.dump();
        return resp;
    }

    json results = json::array();
    for (const auto& r : records) {
        results.push_back({
            {"dataset",     r.dataset},
            {"domain",      r.domain},
            {"listed",      r.listed},
            {"seen",        r.seen},
            {"valid_until", r.valid_until},
            {"detection",   r.detection},
            {"return_code", r.heuristic}
        });
    }

    resp.statusCode = 200;
    resp.body = json{
        {"code",    200},
        {"results", results}
    }.dump(2);
    return resp;
}
