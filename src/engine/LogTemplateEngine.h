// src/engine/LogTemplateEngine.h
#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <flat_map>
#include <variant>
#include <random>

struct Literal     { std::string text; };
struct Placeholder { std::string key;  };
using Segment = std::variant<Literal, Placeholder>;

struct CompiledLine {
    std::vector<Segment> segments;
    size_t               reserveHint = 0;
};

struct LogTemplate {
    std::string              name;
    std::vector<std::string> lines;
};

class FieldGenerator;

class LogTemplateEngine {
public:
    LogTemplateEngine()
        : m_rng(std::random_device{}())
    {}

    [[nodiscard]] bool        loadTemplate(const std::string& formatRaw);
    [[nodiscard]] std::string render(const std::flat_map<std::string, std::string>& tokens) const;

    [[nodiscard]] static std::vector<LogTemplate> loadFromDirectory(const std::string& dirPath);
    [[nodiscard]] static std::string              render(const LogTemplate& tmpl, const FieldGenerator& gen);

private:
    std::vector<CompiledLine> m_compiled;
    std::string               m_rawFormat;
    std::vector<std::string>  m_lines;
    mutable std::mt19937      m_rng;

    [[nodiscard]] static CompiledLine compileLine(const std::string& tpl);
    [[nodiscard]] static std::string  renderCompiled(
        const CompiledLine& cl,
        const std::flat_map<std::string, std::string>& tokens);
};
