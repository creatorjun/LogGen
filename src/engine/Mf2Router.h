// src/engine/Mf2Router.h
#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <cstdint>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class Mf2Router : public ISubRouter {
public:
    Mf2Router();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool        isAuthenticated(const ApiRequest& req) const;
    std::string createSession();

    ApiResponse handleLogin(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);
    ApiResponse handleIpReputationList(const ApiRequest& req);
    ApiResponse handleIpReputationCreate(const ApiRequest& req);
    ApiResponse handleIpReputationUpdate(const ApiRequest& req, const std::string& id);
    ApiResponse handleIpReputationDelete(const ApiRequest& req, const std::string& id);
    ApiResponse handleUrlReputationList(const ApiRequest& req);
    ApiResponse handleUrlReputationCreate(const ApiRequest& req);
    ApiResponse handleUrlReputationUpdate(const ApiRequest& req, const std::string& id);
    ApiResponse handleUrlReputationDelete(const ApiRequest& req, const std::string& id);
    ApiResponse handleUnauthorized();
    ApiResponse handleNotFound(const ApiRequest& req);

    struct IpEntry {
        std::string id;
        std::string ip;
        std::string category;
        std::string description;
        bool        active = true;
    };

    struct UrlEntry {
        std::string id;
        std::string url;
        std::string category;
        std::string description;
        bool        active = true;
    };

    mutable std::mutex                             m_sessionMutex;
    std::unordered_set<std::string>                m_sessions;
    mutable std::mutex                             m_dataMutex;
    std::unordered_map<std::string, IpEntry>       m_ipEntries;
    std::unordered_map<std::string, UrlEntry>      m_urlEntries;
    std::atomic<uint64_t>                          m_idCounter{1};
};
