// src/engine/WinsTaxiiRouter.h
#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <atomic>
#include "core/ApiTypes.h"
#include "core/interfaces/ISubRouter.h"

static constexpr const char* TAXII_CONTENT_TYPE = "application/vnd.oasis.taxii+json; version=2.0";
static constexpr const char* API_ROOT_PATH      = "/api/taxii2/rms";
static constexpr const char* COL_SBL_IP  = "SBL_IP_DATA";
static constexpr const char* COL_REP_IP  = "REP_IP_DATA";
static constexpr const char* COL_REP_URL = "REP_URL_DATA";

class WinsTaxiiRouter : public ISubRouter {
public:
    WinsTaxiiRouter();

    ApiResponse route(const ApiRequest& req) override;

private:
    bool isAuthenticated(const ApiRequest& req);

    ApiResponse handleNotFound(const std::string& msg);
    ApiResponse handleBadRequest(const std::string& msg);
    ApiResponse makeProcessingError(int httpStatus, const std::string& desc);
    ApiResponse makeBundle(const std::string& objectsJson);
    ApiResponse makeStatusResponse(const std::vector<std::string>& successes, int totalCount);

    ApiResponse handleDiscovery(const ApiRequest& req);
    ApiResponse handleCollectionList(const ApiRequest& req);
    ApiResponse handleCollectionGet(const ApiRequest& req, const std::string& colId);
    ApiResponse handleObjectsGet(const ApiRequest& req, const std::string& colId);
    ApiResponse handleObjectsPost(const ApiRequest& req, const std::string& colId);
    ApiResponse handleObjectGet(const ApiRequest& req, const std::string& colId, const std::string& objectId);

    struct StixObject {
        std::string              type;
        std::string              id;
        std::string              created;
        std::string              modified;
        std::string              name;
        std::vector<std::string> labels;
        std::string              firstObserved;
        std::string              lastObserved;
        int                      numberObserved = 1;
        bool                     revoked        = false;
        std::string              objectsJson;
    };

    struct CollectionMeta {
        std::string id;
        std::string title;
        std::string description;
    };

    static std::string  stixObjectToJson(const StixObject& s);
    static StixObject   stixObjectFromJson(const std::string& jsonStr);
    static std::string  collectionToJson(const CollectionMeta& c);

    mutable std::mutex                                          m_mutex;
    std::vector<CollectionMeta>                                 m_collections;
    std::unordered_map<std::string, std::vector<StixObject>>    m_store;
};
