// src/engine/ISubRouter.h
#pragma once

#include "core/ApiTypes.h"

class ISubRouter {
public:
    virtual ~ISubRouter() = default;
    [[nodiscard]] virtual ApiResponse route(const ApiRequest& req) = 0;
};
