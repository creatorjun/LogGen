// src/engine/SpamhausRouter.h
#pragma once

#include <string>
#include <unordered_map>
#include <mutex>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class SpamhausRouter : public ISubRouter {
public:
    SpamhausRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    ApiResponse handleIntelQuery(const ApiRequest& req);
    ApiResponse handleDataset(const ApiRequest& req);
    ApiResponse handleNotFound(const ApiRequest& req);

    mutable std::mutex m_mutex;
    std::unordered_map<std::string, std::string> m_cache;
};
