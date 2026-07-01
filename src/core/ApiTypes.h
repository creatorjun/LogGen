// src/core/ApiTypes.h
#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

struct ApiRequest {
    std::string                                  method;
    std::string                                  path;
    std::string                                  body;
    std::unordered_map<std::string, std::string> headers;
    std::unordered_map<std::string, std::string> params;
};

struct ApiResponse {
    int                                              statusCode  = 200;
    std::string                                      contentType = "application/json";
    std::string                                      body;
    std::vector<std::pair<std::string, std::string>> headers;
};
