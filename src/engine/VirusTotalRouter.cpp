// src/engine/VirusTotalRouter.cpp
#include "VirusTotalRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>

using json = nlohmann::json;

static constexpr const char* VT_MOCK_API_KEY = "mockapikey1234567890abcdef123456";

static const std::vector<std::string> KNOWN_MALICIOUS_IPS = {
    "1.1.1.100", "10.0.0.99", "192.168.100.200",
    "185.220.101.1", "45.142.212.100"
};

static const std::vector<std::string> KNOWN_MALICIOUS_HASHES = {
    "44d88612fea8a8f36de82e1278abb02f",
    "e3b0c44298fc1c149afbf4c8996fb924",
    "aabbccddeeff00112233445566778899aabbccddeeff00112233445566778899"
};

static const std::vector<std::string> KNOWN_MALICIOUS_DOMAINS = {
    "malware.example.com", "phishing.test.org", "c2server.bad"
};

VirusTotalRouter::VirusTotalRouter() {}

bool VirusTotalRouter::isValidApiKey(const std::string& key) {
    return !key.empty();
}

bool VirusTotalRouter::isAuthenticated(const ApiRequest& req) const {
    const auto it = req.headers.find("x-apikey");
    if (it != req.headers.end() && isValidApiKey(it->second))
        return true;
    const auto it2 = req.headers.find("X-Apikey");
    if (it2 != req.headers.end() && isValidApiKey(it2->second))
        return true;
    return false;
}

std::string VirusTotalRouter::makeAnalysisId() {
    static std::mt19937_64 rng(
        std::chrono::steady_clock::now().time_since_epoch().count());
    std::ostringstream oss;
    oss << std::hex << std::uppercase << rng() << rng();
    return oss.str();
}

std::string VirusTotalRouter::nowIso8601() {
    const auto now = std::chrono::system_clock::now();
    const auto tt  = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    struct tm tm_buf{};
#ifdef _WIN32
    gmtime_s(&tm_buf, &tt);
#else
    gmtime_r(&tt, &tm_buf);
#endif
    oss << std::put_time(&tm_buf, "%Y-%m-%dT%H:%M:%SZ");
    return oss.str();
}

std::string VirusTotalRouter::sha256Mock(const std::string& input) {
    std::size_t h = std::hash<std::string>{}(input);
    std::ostringstream oss;
    oss << std::hex << std::setfill('0')
        << std::setw(16) << h
        << std::setw(16) << (h ^ 0xDEADBEEFCAFEBABEULL)
        << std::setw(16) << (h * 6364136223846793005ULL)
        << std::setw(16) << (~h ^ 0x123456789ABCDEF0ULL);
    return oss.str();
}

static json makeEngineResults(int malicious, int total) {
    static const std::vector<std::string> engines = {
        "Kaspersky","BitDefender","Symantec","McAfee","ESET-NOD32",
        "Avast","AVG","MalwareBytes","TrendMicro","Sophos",
        "CrowdStrike","SentinelOne","Cylance","Carbon Black","Panda"
    };
    json results = json::object();
    int assigned = 0;
    for (int i = 0; i < static_cast<int>(engines.size()) && i < total; ++i) {
        const bool det = (assigned < malicious);
        results[engines[i]] = {
            {"category",    det ? "malicious" : "undetected"},
            {"engine_name", engines[i]},
            {"result",      det ? "Trojan.GenericKD" : nullptr},
            {"method",      "blacklist"},
            {"engine_update", "20260622"}
        };
        if (det) ++assigned;
    }
    return results;
}

ApiResponse VirusTotalRouter::handleUnauthorized() {
    ApiResponse resp;
    resp.statusCode = 401;
    resp.body = json{
        {"error", {
            {"code",    "WrongCredentialsError"},
            {"message", "Wrong API key or user does not exist."}
        }}
    }.dump();
    return resp;
}

ApiResponse VirusTotalRouter::handleNotFound(const ApiRequest& req) {
    LOG_WARN("VT", "Unmatched route: " + req.method + " " + req.path);
    ApiResponse resp;
    resp.statusCode = 404;
    resp.body = json{
        {"error", {
            {"code",    "NotFoundError"},
            {"message", "Not found: " + req.path}
        }}
    }.dump();
    return resp;
}

ApiResponse VirusTotalRouter::route(const ApiRequest& req) {
    LOG_DEBUG("VT", "route: " + req.method + " " + req.path);

    const std::string& m = req.method;
    const std::string& p = req.path;

    auto startsWith = [&](const std::string& prefix) {
        return p.rfind(prefix, 0) == 0;
    };

    if (!isAuthenticated(req))
        return handleUnauthorized();

    if (m == "GET"  && startsWith("/vtapi/v3/files/") && p.size() > 16)
        return handleFileReport(req);
    if (m == "POST" && p == "/vtapi/v3/files")
        return handleFileUpload(req);
    if (m == "POST" && startsWith("/vtapi/v3/files/") && p.find("/analyse") != std::string::npos)
        return handleFileRescan(req);

    if (m == "POST" && p == "/vtapi/v3/urls")
        return handleUrlScan(req);
    if (m == "GET"  && startsWith("/vtapi/v3/urls/") && p.size() > 15)
        return handleUrlReport(req);

    if (m == "GET"  && startsWith("/vtapi/v3/ip_addresses/") && p.size() > 23)
        return handleIpReport(req);

    if (m == "GET"  && startsWith("/vtapi/v3/domains/") && p.size() > 18)
        return handleDomainReport(req);

    if (m == "GET"  && startsWith("/vtapi/v3/analyses/") && p.size() > 19)
        return handleAnalysisGet(req);

    return handleNotFound(req);
}

ApiResponse VirusTotalRouter::handleFileReport(const ApiRequest& req) {
    const std::string hash = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("VT", "FileReport hash=" + hash);

    const bool isMalicious = std::find(
        KNOWN_MALICIOUS_HASHES.begin(),
        KNOWN_MALICIOUS_HASHES.end(), hash) != KNOWN_MALICIOUS_HASHES.end();

    const int malicious  = isMalicious ? 42 : 0;
    const int suspicious = isMalicious ?  5 : 0;
    const int harmless   = isMalicious ?  3 : 60;
    const int undetected = 72 - malicious - suspicious - harmless;

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "file"},
            {"id",   hash},
            {"attributes", {
                {"sha256",     hash},
                {"md5",        hash.size() == 32 ? hash : sha256Mock(hash).substr(0,32)},
                {"size",       isMalicious ? 204800 : 512},
                {"type_description", isMalicious ? "Win32 EXE" : "Text"},
                {"meaningful_name", isMalicious ? "malware.exe" : "document.txt"},
                {"last_analysis_date", nowIso8601()},
                {"last_analysis_stats", {
                    {"malicious",   malicious},
                    {"suspicious",  suspicious},
                    {"harmless",    harmless},
                    {"undetected",  undetected},
                    {"timeout",     0}
                }},
                {"last_analysis_results", makeEngineResults(malicious, 15)},
                {"reputation", isMalicious ? -80 : 0},
                {"times_submitted", isMalicious ? 9 : 1}
            }}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleFileUpload(const ApiRequest& req) {
    const std::string analysisId = makeAnalysisId();
    const std::string fakeHash   = sha256Mock(req.body + analysisId);

    AnalysisEntry entry;
    entry.id          = analysisId;
    entry.type        = "file";
    entry.target      = fakeHash;
    entry.status      = "queued";
    entry.sha256      = fakeHash;
    entry.submittedAt = nowIso8601();

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_analyses[analysisId]  = entry;
        m_hashToId[fakeHash]    = analysisId;
    }

    LOG_INFO("VT", "File uploaded, analysis_id=" + analysisId);

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "analysis"},
            {"id",   analysisId}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleFileRescan(const ApiRequest& req) {
    const std::string hash       = req.path.substr(16, req.path.find("/analyse") - 16);
    const std::string analysisId = makeAnalysisId();

    AnalysisEntry entry;
    entry.id          = analysisId;
    entry.type        = "file";
    entry.target      = hash;
    entry.status      = "queued";
    entry.sha256      = hash;
    entry.submittedAt = nowIso8601();

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_analyses[analysisId] = entry;
    }

    LOG_INFO("VT", "File rescan requested, hash=" + hash + " analysis_id=" + analysisId);

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "analysis"},
            {"id",   analysisId}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleUrlScan(const ApiRequest& req) {
    std::string url;
    try {
        const auto body = json::parse(req.body);
        url = body.value("url", "");
    } catch (...) {
        url = req.body;
    }
    if (url.empty()) {
        ApiResponse resp;
        resp.statusCode = 400;
        resp.body = json{{"error", {{"code","InvalidArgumentError"},{"message","URL is required"}}}
        }.dump();
        return resp;
    }

    const std::string analysisId = makeAnalysisId();
    const std::string urlId      = sha256Mock(url);

    AnalysisEntry entry;
    entry.id          = analysisId;
    entry.type        = "url";
    entry.target      = url;
    entry.status      = "queued";
    entry.sha256      = urlId;
    entry.submittedAt = nowIso8601();

    {
        std::lock_guard<std::mutex> lk(m_mutex);
        m_analyses[analysisId] = entry;
        m_urlToId[url]         = urlId;
    }

    LOG_INFO("VT", "URL scan submitted: " + url + " analysis_id=" + analysisId);

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "analysis"},
            {"id",   analysisId}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleUrlReport(const ApiRequest& req) {
    const std::string urlId = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("VT", "UrlReport urlId=" + urlId);

    const bool isMalicious = (urlId.find("malicious") != std::string::npos
        || urlId.size() % 7 == 0);

    const int malicious  = isMalicious ? 18 : 0;
    const int suspicious = isMalicious ?  3 : 0;
    const int harmless   = isMalicious ?  5 : 65;
    const int undetected = 72 - malicious - suspicious - harmless;

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "url"},
            {"id",   urlId},
            {"attributes", {
                {"url",               "https://example.com"},
                {"final_url",         "https://example.com"},
                {"last_analysis_date", nowIso8601()},
                {"last_http_response_code", 200},
                {"last_analysis_stats", {
                    {"malicious",   malicious},
                    {"suspicious",  suspicious},
                    {"harmless",    harmless},
                    {"undetected",  undetected},
                    {"timeout",     0}
                }},
                {"last_analysis_results", makeEngineResults(malicious, 15)},
                {"reputation", isMalicious ? -60 : 0},
                {"times_submitted", 1}
            }}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleIpReport(const ApiRequest& req) {
    const std::string ip = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("VT", "IpReport ip=" + ip);

    const bool isMalicious = std::find(
        KNOWN_MALICIOUS_IPS.begin(),
        KNOWN_MALICIOUS_IPS.end(), ip) != KNOWN_MALICIOUS_IPS.end();

    const int malicious  = isMalicious ? 25 : 0;
    const int suspicious = isMalicious ?  4 : 0;
    const int harmless   = isMalicious ?  2 : 70;
    const int undetected = 72 - malicious - suspicious - harmless;

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "ip_address"},
            {"id",   ip},
            {"attributes", {
                {"ip_address",   ip},
                {"country",      isMalicious ? "RU" : "US"},
                {"asn",          isMalicious ? 208323 : 15169},
                {"as_owner",     isMalicious ? "Hosting Provider" : "Google LLC"},
                {"network",      ip + "/24"},
                {"continent",    isMalicious ? "EU" : "NA"},
                {"last_analysis_date", nowIso8601()},
                {"last_analysis_stats", {
                    {"malicious",   malicious},
                    {"suspicious",  suspicious},
                    {"harmless",    harmless},
                    {"undetected",  undetected},
                    {"timeout",     0}
                }},
                {"last_analysis_results", makeEngineResults(malicious, 15)},
                {"reputation", isMalicious ? -75 : 0},
                {"tags",       isMalicious ? json::array({"malware","c2"}) : json::array()}
            }}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleDomainReport(const ApiRequest& req) {
    const std::string domain = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("VT", "DomainReport domain=" + domain);

    const bool isMalicious = std::find(
        KNOWN_MALICIOUS_DOMAINS.begin(),
        KNOWN_MALICIOUS_DOMAINS.end(), domain) != KNOWN_MALICIOUS_DOMAINS.end();

    const int malicious  = isMalicious ? 30 : 0;
    const int suspicious = isMalicious ?  5 : 0;
    const int harmless   = isMalicious ?  2 : 68;
    const int undetected = 72 - malicious - suspicious - harmless;

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "domain"},
            {"id",   domain},
            {"attributes", {
                {"id",            domain},
                {"creation_date", 1577836800},
                {"last_update_date", 1700000000},
                {"registrar",    "Mock Registrar Inc."},
                {"last_analysis_date", nowIso8601()},
                {"last_analysis_stats", {
                    {"malicious",   malicious},
                    {"suspicious",  suspicious},
                    {"harmless",    harmless},
                    {"undetected",  undetected},
                    {"timeout",     0}
                }},
                {"last_analysis_results", makeEngineResults(malicious, 15)},
                {"reputation", isMalicious ? -85 : 0},
                {"tags",       isMalicious ? json::array({"phishing","malware"}) : json::array()},
                {"categories", isMalicious
                    ? json{{"Sophos","malware site"}}
                    : json{{"Sophos","information technology"}}}
            }}
        }}
    }.dump(2);
    return resp;
}

ApiResponse VirusTotalRouter::handleAnalysisGet(const ApiRequest& req) {
    const std::string analysisId = req.path.substr(req.path.rfind('/') + 1);
    LOG_DEBUG("VT", "AnalysisGet id=" + analysisId);

    std::lock_guard<std::mutex> lk(m_mutex);
    auto it = m_analyses.find(analysisId);

    if (it == m_analyses.end()) {
        ApiResponse resp;
        resp.statusCode = 404;
        resp.body = json{
            {"error", {{"code","NotFoundError"},{"message","Analysis not found"}}}
        }.dump();
        return resp;
    }

    AnalysisEntry& entry = it->second;
    if (entry.status == "queued")
        entry.status = "completed";

    const int malicious  = entry.malicious;
    const int suspicious = entry.suspicious;
    const int harmless   = entry.harmless;
    const int undetected = entry.total - malicious - suspicious - harmless;

    ApiResponse resp;
    resp.statusCode = 200;
    resp.body = json{
        {"data", {
            {"type", "analysis"},
            {"id",   analysisId},
            {"attributes", {
                {"status",       entry.status},
                {"date",         entry.submittedAt},
                {"stats", {
                    {"malicious",  malicious},
                    {"suspicious", suspicious},
                    {"harmless",   harmless},
                    {"undetected", undetected},
                    {"timeout",    0}
                }},
                {"results", makeEngineResults(malicious, 15)}
            }},
            {"meta", {
                {"file_info", {
                    {"sha256", entry.sha256}
                }}
            }}
        }}
    }.dump(2);
    return resp;
}
