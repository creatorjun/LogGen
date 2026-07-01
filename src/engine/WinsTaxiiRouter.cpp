// src/engine/WinsTaxiiRouter.cpp
#include "WinsTaxiiRouter.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <atomic>

using json = nlohmann::json;

static constexpr const char* TAXII_MOCK_USER = "admin";
static constexpr const char* TAXII_MOCK_PASS = "password";

WinsTaxiiRouter::WinsTaxiiRouter() {
    m_collections.push_back({
        COL_SBL_IP,
        "SBL IP Data Observed in Other Systems",
        "This data collection is for other system (ESM, SIEM, CTI) collecting Static Black List IP."
    });
    m_collections.push_back({
        COL_REP_IP,
        "Reputation IPs Data Observed in Other Systems",
        "This collection is published by other systems (ESM, SIEM, CTI) to collect reputation IPs."
    });
    m_collections.push_back({
        COL_REP_URL,
        "Reputation URLs Data Observed in Other Systems",
        "This collection is published by other systems (ESM, SIEM, CTI) to collect reputation URLs."
    });

    for (const auto& c : m_collections)
        m_store[c.id] = {};
}

bool WinsTaxiiRouter::isAuthenticated(const ApiRequest& req) {
    const auto it = req.headers.find("Authorization");
    if (it == req.headers.end()) return false;
    const std::string& auth = it->second;
    const std::string prefix = "Basic ";
    if (auth.rfind(prefix, 0) != 0) return false;
    const std::string encoded = auth.substr(prefix.size());
    const std::string decoded = [&]() -> std::string {
        static const std::string chars =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        std::string out;
        int val = 0, bits = -8;
        for (unsigned char c : encoded) {
            const auto pos = chars.find(c);
            if (pos == std::string::npos) continue;
            val = (val << 6) + static_cast<int>(pos);
            bits += 6;
            if (bits >= 0) {
                out += static_cast<char>((val >> bits) & 0xFF);
                bits -= 8;
            }
        }
        return out;
    }();
    const auto colon = decoded.find(':');
    if (colon == std::string::npos) return false;
    return decoded.substr(0, colon) == TAXII_MOCK_USER &&
           decoded.substr(colon + 1) == TAXII_MOCK_PASS;
}

ApiResponse WinsTaxiiRouter::handleNotFound(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode  = 404;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{
        {"description", msg},
        {"http_status", "404"},
        {"title",       "ProcessingError"}
    }.dump();
    return resp;
}

ApiResponse WinsTaxiiRouter::handleBadRequest(const std::string& msg) {
    ApiResponse resp;
    resp.statusCode  = 400;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{
        {"description", msg},
        {"http_status", "400"},
        {"title",       "ProcessingError"}
    }.dump();
    return resp;
}

ApiResponse WinsTaxiiRouter::makeProcessingError(int httpStatus, const std::string& desc) {
    ApiResponse resp;
    resp.statusCode  = httpStatus;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{
        {"description", desc},
        {"http_status", std::to_string(httpStatus)},
        {"title",       "ProcessingError"}
    }.dump();
    return resp;
}

ApiResponse WinsTaxiiRouter::makeBundle(const std::string& objectsJson) {
    static std::atomic<uint64_t> counter{1};
    const uint64_t n = counter.fetch_add(1);
    const std::string bid = "bundle--mock-wins-" + std::to_string(n);
    json objects;
    try { objects = json::parse(objectsJson); } catch (...) { objects = json::array(); }
    ApiResponse resp;
    resp.statusCode  = 200;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{
        {"type",         "bundle"},
        {"id",           bid},
        {"spec_version", "2.0"},
        {"objects",      objects}
    }.dump(2);
    return resp;
}

ApiResponse WinsTaxiiRouter::makeStatusResponse(const std::vector<std::string>& successes,
                                                 int totalCount) {
    static std::atomic<uint64_t> counter{1};
    const uint64_t n = counter.fetch_add(1);
    const std::string sid = "status-mock-" + std::to_string(n);

    using namespace std::chrono;
    const auto tp  = system_clock::now();
    const auto sec = duration_cast<seconds>(tp.time_since_epoch()).count();
    const std::string ts = [&]() -> std::string {
        char buf[32];
        const std::time_t t = static_cast<std::time_t>(sec);
        std::tm tm_utc{};
#ifdef _WIN32
        gmtime_s(&tm_utc, &t);
#else
        gmtime_r(&t, &tm_utc);
#endif
        std::strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%S.000000Z", &tm_utc);
        return std::string(buf);
    }();

    json sucArr = json::array();
    for (const auto& s : successes) sucArr.push_back(s);

    ApiResponse resp;
    resp.statusCode  = 200;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{
        {"id",                sid},
        {"status",            "complete"},
        {"request_timestamp", ts},
        {"total_count",       totalCount},
        {"success_count",     static_cast<int>(successes.size())},
        {"failure_count",     totalCount - static_cast<int>(successes.size())},
        {"pending_count",     0},
        {"successes",         sucArr}
    }.dump(2);
    return resp;
}

// ---- private static JSON serialisation helpers ----

std::string WinsTaxiiRouter::stixObjectToJson(const StixObject& s) {
    json labelArr = json::array();
    for (const auto& l : s.labels) labelArr.push_back(l);
    json objectsVal;
    try { objectsVal = json::parse(s.objectsJson); } catch (...) { objectsVal = json::object(); }
    return json{
        {"type",             s.type},
        {"id",               s.id},
        {"created",          s.created},
        {"modified",         s.modified},
        {"name",             s.name},
        {"labels",           labelArr},
        {"first_observed",   s.firstObserved},
        {"last_observed",    s.lastObserved},
        {"number_observed",  s.numberObserved},
        {"revoked",          s.revoked},
        {"objects",          objectsVal}
    }.dump();
}

WinsTaxiiRouter::StixObject WinsTaxiiRouter::stixObjectFromJson(const std::string& jsonStr) {
    StixObject s;
    try {
        const json j = json::parse(jsonStr);
        s.type           = j.value("type",            "observed-data");
        s.id             = j.value("id",              "");
        s.created        = j.value("created",         "");
        s.modified       = j.value("modified",        "");
        s.name           = j.value("name",            "");
        s.firstObserved  = j.value("first_observed",  "");
        s.lastObserved   = j.value("last_observed",   "");
        s.numberObserved = j.value("number_observed", 1);
        s.revoked        = j.value("revoked",         false);
        if (j.contains("labels") && j["labels"].is_array())
            for (const auto& l : j["labels"])
                s.labels.push_back(l.get<std::string>());
        if (j.contains("objects"))
            s.objectsJson = j["objects"].dump();
    } catch (...) {}
    return s;
}

std::string WinsTaxiiRouter::collectionToJson(const CollectionMeta& c) {
    return json{
        {"id",          c.id},
        {"title",       c.title},
        {"description", c.description},
        {"can_read",    true},
        {"can_write",   true},
        {"media_types", json::array({"application/vnd.oasis.stix+json; version=2.0"})}
    }.dump();
}

ApiResponse WinsTaxiiRouter::handleDiscovery(const ApiRequest& req) {
    (void)req;
    ApiResponse resp;
    resp.statusCode  = 200;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{
        {"title",       "WINS TAXII2.0 Server"},
        {"description", "WINS TAXII 2.0 Mock Server"},
        {"contact",     "wins-mock@example.com"},
        {"api_roots",   json::array({"https://rms.sniper.com:8500/api/taxii2/rms/"})}
    }.dump(2);
    return resp;
}

ApiResponse WinsTaxiiRouter::handleCollectionList(const ApiRequest& req) {
    (void)req;
    json arr = json::array();
    for (const auto& c : m_collections)
        arr.push_back(json::parse(collectionToJson(c)));
    ApiResponse resp;
    resp.statusCode  = 200;
    resp.contentType = TAXII_CONTENT_TYPE;
    resp.body = json{{"collections", arr}}.dump(2);
    return resp;
}

ApiResponse WinsTaxiiRouter::handleCollectionGet(const ApiRequest& req, const std::string& colId) {
    (void)req;
    for (const auto& c : m_collections) {
        if (c.id == colId) {
            ApiResponse resp;
            resp.statusCode  = 200;
            resp.contentType = TAXII_CONTENT_TYPE;
            resp.body = collectionToJson(c);
            return resp;
        }
    }
    return handleNotFound("Collection '" + colId + "' not found. Root exception: None");
}

ApiResponse WinsTaxiiRouter::handleObjectsGet(const ApiRequest& req, const std::string& colId) {
    (void)req;
    const auto storeIt = m_store.find(colId);
    if (storeIt == m_store.end())
        return handleNotFound("Collection '" + colId + "' not found. Root exception: None");

    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& s : storeIt->second)
        arr.push_back(json::parse(stixObjectToJson(s)));
    return makeBundle(arr.dump());
}

ApiResponse WinsTaxiiRouter::handleObjectsPost(const ApiRequest& req, const std::string& colId) {
    const auto storeIt = m_store.find(colId);
    if (storeIt == m_store.end())
        return handleNotFound("Collection '" + colId + "' not found. Root exception: None");

    json body;
    try {
        body = json::parse(req.body);
    } catch (const std::exception& e) {
        return handleBadRequest(std::string("JSON parse error: ") + e.what());
    }

    if (!body.contains("objects") || !body["objects"].is_array())
        return handleBadRequest("'objects' array is required in bundle");

    std::vector<std::string> successes;
    int totalCount = 0;

    std::lock_guard<std::mutex> lk(m_mutex);
    auto& store = storeIt->second;

    for (const auto& obj : body["objects"]) {
        ++totalCount;
        try {
            const std::string type = obj.value("type", "");
            if (type != "observed-data") {
                LOG_WARN("TAXII", "Skipping non observed-data type: " + type);
                continue;
            }
            const std::string id = obj.value("id", "");
            if (id.empty()) {
                LOG_WARN("TAXII", "Skipping object without id");
                continue;
            }

            StixObject incoming = stixObjectFromJson(obj.dump());

            auto it = std::find_if(store.begin(), store.end(),
                [&](const StixObject& s){ return s.id == id; });

            if (it == store.end()) {
                store.push_back(incoming);
                LOG_INFO("TAXII", "Object created: " + id);
            } else {
                if (incoming.modified > it->modified) {
                    *it = incoming;
                    LOG_INFO("TAXII", "Object updated: " + id
                        + (incoming.revoked ? " [revoked]" : ""));
                } else {
                    LOG_WARN("TAXII", "Object " + id + " modified timestamp is not newer, skipping");
                    continue;
                }
            }
            successes.push_back(id);
        } catch (const std::exception& e) {
            LOG_WARN("TAXII", std::string("Object processing error: ") + e.what());
        }
    }

    return makeStatusResponse(successes, totalCount);
}

ApiResponse WinsTaxiiRouter::handleObjectGet(const ApiRequest& req, const std::string& colId,
                                              const std::string& objectId) {
    (void)req;
    const auto storeIt = m_store.find(colId);
    if (storeIt == m_store.end())
        return handleNotFound("Collection '" + colId + "' not found. Root exception: None");

    std::lock_guard<std::mutex> lk(m_mutex);
    json arr = json::array();
    for (const auto& s : storeIt->second) {
        if (s.id == objectId) {
            arr.push_back(json::parse(stixObjectToJson(s)));
            break;
        }
    }
    return makeBundle(arr.dump());
}

ApiResponse WinsTaxiiRouter::route(const ApiRequest& req) {
    LOG_DEBUG("TAXII", "route: " + req.method + " " + req.path);

    const auto cleanPath = [&]() -> std::string {
        const auto pos = req.path.find('?');
        return (pos == std::string::npos) ? req.path : req.path.substr(0, pos);
    };
    const std::string cp = cleanPath();
    const std::string& m = req.method;

    if (m == "GET" && (cp == "/api/taxii2/taxii" || cp == "/wins/taxii"))
        return handleDiscovery(req);

    const std::string apiRoot   = std::string(API_ROOT_PATH);
    const std::string colsBase  = apiRoot + "/collections";
    const std::string colsBaseS = apiRoot + "/collections/";

    if (!isAuthenticated(req)) {
        ApiResponse resp;
        resp.statusCode  = 401;
        resp.contentType = TAXII_CONTENT_TYPE;
        resp.body = json{
            {"description", "Unauthorized"},
            {"http_status", "401"},
            {"title",       "AuthenticationError"}
        }.dump();
        return resp;
    }

    if (m == "GET" && cp == colsBase)
        return handleCollectionList(req);

    if (cp.rfind(colsBaseS, 0) == 0) {
        const std::string rest = cp.substr(colsBaseS.size());

        const auto slashPos = rest.find('/');
        if (slashPos == std::string::npos) {
            const std::string colId = rest;
            if (!colId.empty() && m == "GET")
                return handleCollectionGet(req, colId);
        } else {
            const std::string colId   = rest.substr(0, slashPos);
            const std::string objPart = rest.substr(slashPos + 1);

            if (objPart == "objects" || objPart == "objects/") {
                if (m == "GET")  return handleObjectsGet(req, colId);
                if (m == "POST") return handleObjectsPost(req, colId);
            }

            const std::string objsPrefix = "objects/";
            if (objPart.rfind(objsPrefix, 0) == 0) {
                const std::string objectId = objPart.substr(objsPrefix.size());
                if (!objectId.empty() && m == "GET")
                    return handleObjectGet(req, colId, objectId);
            }
        }
    }

    LOG_WARN("TAXII", "Unmatched route: " + m + " " + cp);
    return handleNotFound("Route not found: " + m + " " + cp);
}
