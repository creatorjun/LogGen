// src/engine/SecuiRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <cstdint>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class SecuiRouter : public ISubRouter {
public:
    SecuiRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool        isAuthenticated(const ApiRequest& req) const;
    std::string createSession();
    void        removeSession(const std::string& token);

    ApiResponse handleLogin(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);
    ApiResponse handlePolicyList(const ApiRequest& req);
    ApiResponse handlePolicyCreate(const ApiRequest& req);
    ApiResponse handlePolicyGet(const ApiRequest& req, const std::string& id);
    ApiResponse handlePolicyUpdate(const ApiRequest& req, const std::string& id);
    ApiResponse handlePolicyDelete(const ApiRequest& req, const std::string& id);
    ApiResponse handleBlacklistList(const ApiRequest& req);
    ApiResponse handleBlacklistCreate(const ApiRequest& req);
    ApiResponse handleBlacklistGet(const ApiRequest& req, const std::string& id);
    ApiResponse handleBlacklistUpdate(const ApiRequest& req, const std::string& id);
    ApiResponse handleBlacklistDelete(const ApiRequest& req, const std::string& id);
    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);

    struct PolicyEntry {
        std::string id;
        std::string name;
        std::string action;
        std::string srcIp;
        std::string dstIp;
        bool        enabled = true;
    };

    struct BlacklistEntry {
        std::string id;
        std::string ip;
        std::string reason;
        bool        active = true;
    };

    mutable std::mutex                                 m_sessionMutex;
    std::unordered_set<std::string>                    m_sessions;
    mutable std::mutex                                 m_dataMutex;
    std::unordered_map<std::string, PolicyEntry>       m_policies;
    std::unordered_map<std::string, BlacklistEntry>    m_blacklists;
    std::atomic<uint64_t>                              m_idCounter{1};
};
