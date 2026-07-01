// src/engine/SecuiRouter.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include "core/ApiTypes.h"
#include "engine/ISubRouter.h"
// nlohmann/json.hpp is an implementation detail — included only in SecuiRouter.cpp

class SecuiRouter : public ISubRouter {
public:
    SecuiRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool        isAuthenticated(const ApiRequest& req) const;
    std::string createToken(const std::string& clientId);
    void        removeToken(const std::string& token);

    static std::string makeToken();
    static int64_t     nowUnix();

    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);
    ApiResponse handleBadRequest(const std::string& msg);
    ApiResponse handleSuccess(const std::string& jsonBody);

    ApiResponse handleToken(const ApiRequest& req);
    ApiResponse handleRevokeToken(const ApiRequest& req);

    ApiResponse handleBlacklistGet(const ApiRequest& req);
    ApiResponse handleBlacklistAdd(const ApiRequest& req);
    ApiResponse handleBlacklistDelete(const ApiRequest& req);

    ApiResponse handleAddressGroupGet(const ApiRequest& req);
    ApiResponse handleAddressGroupAddMember(const ApiRequest& req);
    ApiResponse handleAddressGroupDeleteMember(const ApiRequest& req);

    ApiResponse handlePolicyGet(const ApiRequest& req);
    ApiResponse handleSessionGet(const ApiRequest& req);
    ApiResponse handleSystemInfo(const ApiRequest& req);

    struct TokenEntry {
        std::string clientId;
        int64_t     expires;
    };

    struct BlacklistEntry {
        std::string ip;
        std::string direction;
        int         ttlDays;
        int64_t     registeredAt;
        int64_t     expiresAt;
    };

    struct AddressGroupEntry {
        std::string groupName;
        std::string zone;
        std::vector<std::string> members;
    };

    mutable std::mutex                             m_mutex;
    std::unordered_map<std::string, TokenEntry>    m_tokens;
    std::vector<BlacklistEntry>                    m_blacklist;
    std::unordered_map<std::string,
                       AddressGroupEntry>          m_addressGroups;
};
