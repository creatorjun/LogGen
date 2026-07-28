// src/engine/WinsTaxiiRouter.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

class WinsTaxiiRouter : public ISubRouter {
public:
    WinsTaxiiRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    ApiResponse handleDiscovery(const ApiRequest& req);
    ApiResponse handleApiRoot(const ApiRequest& req);
    ApiResponse handleCollections(const ApiRequest& req);
    ApiResponse handleCollectionObjects(const ApiRequest& req, const std::string& colId);
    ApiResponse handleAddObjects(const ApiRequest& req, const std::string& colId);
    ApiResponse handleStatus(const ApiRequest& req, const std::string& statusId);
    ApiResponse handleWinsQuery(const ApiRequest& req);
    ApiResponse handleNotFound(const ApiRequest& req);

    struct TaxiiObject {
        std::string id;
        std::string type;
        std::string json;
    };

    mutable std::mutex                                          m_mutex;
    std::unordered_map<std::string, std::vector<TaxiiObject>>  m_collections;
    std::unordered_map<std::string, std::string>               m_statusMap;
};
