// src/engine/Mf2Router.h
#pragma once

#include "core/ApiTypes.h"
#include "engine/ISubRouter.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <mutex>

class Mf2Router : public ISubRouter {
public:
    Mf2Router();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool        isAuthenticated(const ApiRequest& req) const;
    std::string createSession(const std::string& userId, const std::string& token);
    void        removeSession(const std::string& token);

    ApiResponse handleLogin(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);
    ApiResponse handleRefresh(const ApiRequest& req);

    ApiResponse handlePolicyGet(const ApiRequest& req);
    ApiResponse handlePolicyAdd(const ApiRequest& req);
    ApiResponse handlePolicyDelete(const ApiRequest& req);
    ApiResponse handlePolicyEnable(const ApiRequest& req);

    ApiResponse handleObjectGet(const ApiRequest& req);
    ApiResponse handleObjectAdd(const ApiRequest& req);
    ApiResponse handleObjectDelete(const ApiRequest& req);

    ApiResponse handleSystemInfo(const ApiRequest& req);
    ApiResponse handleApply(const ApiRequest& req);

    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);
    ApiResponse handleBadRequest(const std::string& msg);

    static std::string makeId();
    static int64_t     nowUnix();

    struct SessionEntry {
        std::string userId;
        int64_t     expires;
    };

    struct PolicyEntry {
        std::string id;
        std::string name;
        std::string srcIp;
        std::string dstIp;
        std::string service;
        std::string action;
        bool        enabled = true;
    };

    struct ObjectEntry {
        std::string id;
        std::string name;
        std::string type;
        std::string value;
    };

    mutable std::mutex                               m_mutex;
    std::unordered_map<std::string, SessionEntry>    m_sessions;
    std::unordered_map<std::string, PolicyEntry>     m_policies;
    std::unordered_map<std::string, ObjectEntry>     m_objects;
};
