// src/engine/ApiResponseEngine.h
#pragma once

#include <string>
#include <unordered_map>
#include "core/ApiMockRule.h"

class ApiResponseEngine {
public:
    [[nodiscard]] std::string render(const std::string& bodyTemplate,
                                     const std::string& requestBody) const;

private:
    static void extractRequestTokens(
        const std::string& requestBody,
        std::unordered_map<std::string, std::string>& tokens);

    [[nodiscard]] static std::string renderTemplate(
        const std::string& tpl,
        const std::unordered_map<std::string, std::string>& tokens);
};
