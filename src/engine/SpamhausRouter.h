// src/engine/SpamhausRouter.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include "core/ApiTypes.h"
#include "engine/ISubRouter.h"

class SpamhausRouter : public ISubRouter {
public:
    SpamhausRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool        isAuthenticated(const ApiRequest& req) const;
    std::string createToken(const std::string& username);
    void        removeToken(const std::string& token);

    static std::string makeToken();
    static std::string nowIso8601();
    static int64_t     nowUnix();

    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);
    ApiResponse handleBadRequest(const std::string& msg);

    ApiResponse handleLogin(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);
    ApiResponse handleLimits(const ApiRequest& req);

    ApiResponse handleIpLookup(const ApiRequest& req);
    ApiResponse handleDomainLookup(const ApiRequest& req);

    struct TokenEntry {
        std::string username;
        int64_t     expires;
    };

    struct ListingRecord {
        std::string dataset;
        std::string ipaddress;
        std::string domain;
        std::string asn;
        std::string cc;
        int64_t     listed;
        int64_t     seen;
        int64_t     valid_until;
        std::string botname;
        std::string detection;
        std::string heuristic;
        int         dstport;
    };

    static std::vector<ListingRecord> buildIpRecords(const std::string& ip,
                                                      const std::string& dataset);
    static std::vector<ListingRecord> buildDomainRecords(const std::string& domain,
                                                          const std::string& dataset);

    mutable std::mutex                             m_mutex;
    std::unordered_map<std::string, TokenEntry>    m_tokens;
    int                                            m_queryCount = 0;
};
