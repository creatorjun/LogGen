// src/engine/FortinetRouter.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <cstdint>
#include "core/ApiTypes.h"
#include "engine/ISubRouter.h"
// nlohmann/json.hpp is an implementation detail — included only in FortinetRouter.cpp

class FortinetRouter : public ISubRouter {
public:
    FortinetRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool        isAuthenticated(const ApiRequest& req) const;
    static std::string extractToken(const ApiRequest& req);
    static std::string extractSessionCookie(const ApiRequest& req);
    static std::string extractCsrfToken(const ApiRequest& req);
    bool        validateCsrf(const ApiRequest& req) const;

    ApiResponse handleUnauthorized();
    ApiResponse handleForbidden(const std::string& msg);
    ApiResponse handleNotFound(const ApiRequest& req);
    ApiResponse handleBadRequest(const std::string& msg);
    ApiResponse makeSuccess(const std::string& resultsJson, const std::string& method);
    ApiResponse makeError(int httpStatus, const std::string& msg);

    ApiResponse handleLoginCheck(const ApiRequest& req);
    ApiResponse handleLogout(const ApiRequest& req);

    ApiResponse handleSystemStatus(const ApiRequest& req);
    ApiResponse handleSystemGlobal(const ApiRequest& req);

    ApiResponse handleAddressList(const ApiRequest& req);
    ApiResponse handleAddressCreate(const ApiRequest& req);
    ApiResponse handleAddressGet(const ApiRequest& req, const std::string& name);
    ApiResponse handleAddressUpdate(const ApiRequest& req, const std::string& name);
    ApiResponse handleAddressDelete(const ApiRequest& req, const std::string& name);

    ApiResponse handleAddrgrpList(const ApiRequest& req);
    ApiResponse handleAddrgrpCreate(const ApiRequest& req);
    ApiResponse handleAddrgrpGet(const ApiRequest& req, const std::string& name);
    ApiResponse handleAddrgrpUpdate(const ApiRequest& req, const std::string& name);
    ApiResponse handleAddrgrpDelete(const ApiRequest& req, const std::string& name);
    ApiResponse handleAddrgrpMemberGet(const ApiRequest& req, const std::string& grpName);
    ApiResponse handleAddrgrpMemberPost(const ApiRequest& req, const std::string& grpName);

    ApiResponse handlePolicyList(const ApiRequest& req);
    ApiResponse handlePolicyCreate(const ApiRequest& req);
    ApiResponse handlePolicyGet(const ApiRequest& req, const std::string& policyid);
    ApiResponse handlePolicyUpdate(const ApiRequest& req, const std::string& policyid);
    ApiResponse handlePolicyDelete(const ApiRequest& req, const std::string& policyid);

    ApiResponse handleBannedAddUsers(const ApiRequest& req);
    ApiResponse handleBannedClearUsers(const ApiRequest& req);
    ApiResponse handleBannedClearAll(const ApiRequest& req);
    ApiResponse handleBannedList(const ApiRequest& req);

    struct AddressEntry {
        std::string name;
        std::string type;
        std::string subnet;
        std::string comment;
    };

    struct AddrgrpEntry {
        std::string name;
        std::vector<std::string> members;
        std::string comment;
    };

    struct PolicyEntry {
        int         policyid;
        std::string name;
        std::string srcintf;
        std::string dstintf;
        std::string srcaddr;
        std::string dstaddr;
        std::string action;
        std::string schedule;
        std::string service;
        int         status;
    };

    struct BannedEntry {
        std::string ip;
        int64_t     created;
        int         expiresSeconds;
    };

    static std::string addressToJson(const AddressEntry& e);
    static std::string addrgrpToJson(const AddrgrpEntry& e);
    static std::string policyToJson(const PolicyEntry& e);

    mutable std::mutex              m_mutex;
    std::string                     m_token;
    std::unordered_map<std::string, std::string> m_sessions;
    std::vector<AddressEntry>       m_addresses;
    std::vector<AddrgrpEntry>       m_addrgrps;
    std::vector<PolicyEntry>        m_policies;
    std::vector<BannedEntry>        m_banned;
    int                             m_nextPolicyId;
};
