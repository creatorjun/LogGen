// src/engine/SecuiRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <cstdint>
#include <atomic>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class SecuiRouter : public ISubRouter {
public:
    SecuiRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    static std::string makeToken();
    static int64_t     nowUnix();

    std::string createToken(const std::string& clientId);
    void        removeToken(const std::string& token);
    bool        isAuthenticated(const ApiRequest& req) const;

    ApiResponse handleBadRequest(const std::string& msg);
    ApiResponse handleSuccess(const std::string& dataJson);
    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);

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
        int64_t     expires = 0;
    };

    struct BlacklistEntry {
        std::string ip;
        std::string direction;
        int         ttlDays      = 365;
        int64_t     registeredAt = 0;
        int64_t     expiresAt    = 0;
    };

    struct AddressGroupEntry {
        std::string              groupName;
        std::string              zone;
        std::vector<std::string> members;
    };

    mutable std::mutex                                      m_mutex;
    std::unordered_map<std::string, TokenEntry>             m_tokens;
    std::vector<BlacklistEntry>                             m_blacklist;
    std::unordered_map<std::string, AddressGroupEntry>      m_addressGroups;
};
