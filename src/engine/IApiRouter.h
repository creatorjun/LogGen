// src/engine/IApiRouter.h
#pragma once

#include "core/ApiTypes.h"

class IApiRouter {
public:
    virtual ~IApiRouter() = default;
    [[nodiscard]] virtual ApiResponse route(const ApiRequest& req) = 0;
};
