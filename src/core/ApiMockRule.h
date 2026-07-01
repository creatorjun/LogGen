// src/core/ApiMockRule.h
#pragma once

#include <string>
#include <vector>

struct ApiMockResponse {
    int         statusCode   = 200;
    std::string contentType  = "application/json";
    std::string bodyTemplate;
};

struct ApiMockRule {
    std::string      endpoint;
    std::string      method          = "POST";
    int              simulateDelayMs = 0;
    float            errorRate       = 0.0f;
    std::vector<int> errorCodes      = {500};
    ApiMockResponse  response;
};
