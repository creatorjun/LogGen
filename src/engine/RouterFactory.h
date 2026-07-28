// src/engine/RouterFactory.h
#pragma once

#include <memory>
#include "engine/ApiRouter.h"

class RouterFactory {
public:
    [[nodiscard]] static std::unique_ptr<ApiRouter> create();
};
