// src/engine/SpamhausRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <cstdint>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class SpamhausRouter : public ISubRouter {
public:
    SpamhausRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    static std::string makeToken();
    static int64_t     nowUnix();
    static std::string nowIso8601();

    std::string createToken(const std::string& username);
    void        removeToken(const std::string& token);
    bool        isAuthenticated(const ApiRequest& req) const;

    ApiResponse handleBadRequest(const std::string& msg);
    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);

    ApiResponse handleLogin(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);
    ApiResponse handleLimits(const ApiRequest& req);
    ApiResponse handleIpLookup(const ApiRequest& req);
    ApiResponse handleDomainLookup(const ApiRequest& req);

    struct TokenEntry {
        std::string username;
        int64_t     expires = 0;
    };

    struct ListingRecord {
        std::string dataset;
        std::string ipaddress;
        std::string domain;
        std::string asn;
        std::string cc;
        int64_t     listed      = 0;
        int64_t     seen        = 0;
        int64_t     valid_until = 0;
        std::string botname;
        std::string detection;
        std::string heuristic;
        int         dstport = 0;
    };

    std::vector<ListingRecord> buildIpRecords(const std::string& ip, const std::string& dataset);
    std::vector<ListingRecord> buildDomainRecords(const std::string& domain, const std::string& dataset);

    mutable std::mutex                          m_mutex;
    std::unordered_map<std::string, TokenEntry> m_tokens;
    int64_t                                     m_queryCount = 0;
};
