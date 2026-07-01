// src/engine/ApiResponseEngine.cpp
#include "ApiResponseEngine.h"
#include <nlohmann/json.hpp>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

// Thread-safe timestamp helpers (localtime_s / localtime_r)
static std::string nowTimestamp() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm_buf{};
#ifdef _WIN32
    localtime_s(&tm_buf, &t);
#else
    localtime_r(&t, &tm_buf);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

static std::string nowDate() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm_buf{};
#ifdef _WIN32
    localtime_s(&tm_buf, &t);
#else
    localtime_r(&t, &tm_buf);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm_buf, "%Y-%m-%d");
    return oss.str();
}

void ApiResponseEngine::extractRequestTokens(
    const std::string& requestBody,
    std::unordered_map<std::string, std::string>& tokens)
{
    if (requestBody.empty()) return;
    try {
        const auto j = nlohmann::json::parse(requestBody);
        for (auto it = j.begin(); it != j.end(); ++it) {
            const std::string key = "req.body." + it.key();
            if (it->is_string())
                tokens[key] = it->get<std::string>();
            else
                tokens[key] = it->dump();
        }
    } catch (const nlohmann::json::parse_error&) {
        // 비-JSON 바디는 조용히 무시 — req.body.* 토큰 미등록 상태로 진행
    }
}

std::string ApiResponseEngine::renderTemplate(
    const std::string& tpl,
    const std::unordered_map<std::string, std::string>& tokens)
{
    std::string result;
    result.reserve(tpl.size() + 128);
    size_t pos = 0;
    while (pos < tpl.size()) {
        const size_t open = tpl.find("{{", pos);
        if (open == std::string::npos) {
            result += tpl.substr(pos);
            break;
        }
        result += tpl.substr(pos, open - pos);
        const size_t close = tpl.find("}}", open + 2);
        if (close == std::string::npos) {
            result += tpl.substr(open);
            break;
        }
        const std::string key = tpl.substr(open + 2, close - open - 2);
        const auto it = tokens.find(key);
        if (it != tokens.end())
            result += it->second;
        pos = close + 2;
    }
    return result;
}

std::string ApiResponseEngine::render(
    const std::string& bodyTemplate,
    const std::string& requestBody) const
{
    std::unordered_map<std::string, std::string> tokens;
    tokens["TIMESTAMP"] = nowTimestamp();
    tokens["DATE"]      = nowDate();
    extractRequestTokens(requestBody, tokens);
    return renderTemplate(bodyTemplate, tokens);
}
