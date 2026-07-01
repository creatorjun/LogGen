// src/engine/NexGfwRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <atomic>
#include <cstdint>
#include "core/ApiTypes.h"
#include "engine/ISubRouter.h"

class NexGfwRouter : public ISubRouter {
public:
    NexGfwRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    static std::string xmlSuccess(const std::string& code, const std::string& msg, const std::string& extra = "");
    static std::string xmlError(const std::string& code, const std::string& msg);
    static std::string makeObjId();

    bool        isAuthenticated(const ApiRequest& req) const;
    std::string createSession();
    void        removeSession(const std::string& token);

    ApiResponse handleLogin(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);
    ApiResponse handleApply(const ApiRequest& req);
    ApiResponse handleRestore(const ApiRequest& req);

    ApiResponse handleNetworkGet(const ApiRequest& req);
    ApiResponse handleNetworkSet(const ApiRequest& req);
    ApiResponse handleNetworkUpdate(const ApiRequest& req);
    ApiResponse handleNetworkDelete(const ApiRequest& req);

    ApiResponse handleBlacklistGet(const ApiRequest& req);
    ApiResponse handleBlacklistSet(const ApiRequest& req);
    ApiResponse handleBlacklistUpdate(const ApiRequest& req);
    ApiResponse handleBlacklistEnable(const ApiRequest& req);
    ApiResponse handleBlacklistDelete(const ApiRequest& req);

    ApiResponse handleBasePolicyGet(const ApiRequest& req);
    ApiResponse handleBasePolicySet(const ApiRequest& req);
    ApiResponse handleBasePolicyUpdate(const ApiRequest& req);
    ApiResponse handleBasePolicyEnable(const ApiRequest& req);
    ApiResponse handleBasePolicyDelete(const ApiRequest& req);

    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);

    struct NetObj {
        std::string id;
        std::string name;
        std::string description;
        std::string version;
        std::string addresses;
    };

    struct BlacklistEntry {
        std::string id;
        std::string name;
        std::string description;
        std::string type;
        std::string target;
        std::string method;
        std::string members;
        bool        active = true;
    };

    struct PolicyEntry {
        std::string id;
        std::string name;
        std::string description;
        std::string action;
        std::string szone;
        std::string dzone;
        std::string snetworks;
        std::string dnetworks;
        bool        active = true;
    };

    mutable std::mutex                              m_sessionMutex;
    std::unordered_set<std::string>                 m_sessions;

    mutable std::mutex                              m_dataMutex;
    std::unordered_map<std::string, NetObj>         m_networkObjs;
    std::unordered_map<std::string, BlacklistEntry> m_blacklists;
    std::unordered_map<std::string, PolicyEntry>    m_policies;

    std::atomic<uint64_t> m_idCounter { 0x0A001000000000ULL };
};
