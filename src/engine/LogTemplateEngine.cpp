// src/engine/LogTemplateEngine.cpp
#include "LogTemplateEngine.h"
#include "engine/FieldGenerator.h"
#include "logging/Logger.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <filesystem>
#include <format>
#include <ranges>
#include <cctype>
#include <random>

using json = nlohmann::json;
namespace fs = std::filesystem;

CompiledLine LogTemplateEngine::compileLine(const std::string& tpl) {
    CompiledLine cl;
    size_t pos = 0;
    std::string litBuf;
    litBuf.reserve(64);

    auto flushLit = [&]() {
        if (!litBuf.empty()) {
            cl.segments.push_back(Literal{ std::move(litBuf) });
            litBuf.clear();
            litBuf.reserve(64);
        }
    };

    while (pos < tpl.size()) {
        const size_t dollarPos = tpl.find('$', pos);
        if (dollarPos == std::string::npos) {
            litBuf.append(tpl, pos, tpl.size() - pos);
            break;
        }
        litBuf.append(tpl, pos, dollarPos - pos);

        if (dollarPos + 1 >= tpl.size()) {
            litBuf += '$';
            pos = dollarPos + 1;
            continue;
        }

        if (tpl[dollarPos + 1] == '{') {
            const size_t end = tpl.find('}', dollarPos + 2);
            if (end == std::string::npos) {
                litBuf.append(tpl, dollarPos, tpl.size() - dollarPos);
                break;
            }
            flushLit();
            cl.segments.push_back(
                Placeholder{ tpl.substr(dollarPos + 2, end - dollarPos - 2) });
            pos = end + 1;
        } else if (std::isupper(static_cast<unsigned char>(tpl[dollarPos + 1]))
                || tpl[dollarPos + 1] == '_') {
            size_t keyStart = dollarPos + 1;
            size_t keyEnd   = keyStart;
            while (keyEnd < tpl.size() &&
                   (std::isupper(static_cast<unsigned char>(tpl[keyEnd]))
                    || tpl[keyEnd] == '_'
                    || std::isdigit(static_cast<unsigned char>(tpl[keyEnd])))) {
                ++keyEnd;
            }
            flushLit();
            cl.segments.push_back(
                Placeholder{ tpl.substr(keyStart, keyEnd - keyStart) });
            pos = keyEnd;
        } else {
            litBuf += '$';
            pos = dollarPos + 1;
        }
    }
    flushLit();

    cl.reserveHint = std::ranges::fold_left(
        cl.segments, size_t{32},
        [](size_t acc, const Segment& seg) {
            return acc + std::visit([](const auto& s) -> size_t {
                if constexpr (std::is_same_v<std::decay_t<decltype(s)>, Literal>)
                    return s.text.size();
                else
                    return size_t{16};
            }, seg);
        });

    return cl;
}

std::string LogTemplateEngine::renderCompiled(
    const CompiledLine& cl,
    const std::flat_map<std::string, std::string>& tokens)
{
    std::string result;
    result.reserve(cl.reserveHint);
    static const std::string kEmpty;

    std::ranges::for_each(cl.segments, [&](const Segment& seg) {
        std::visit([&](const auto& s) {
            if constexpr (std::is_same_v<std::decay_t<decltype(s)>, Literal>) {
                result += s.text;
            } else {
                const auto it = tokens.find(s.key);
                result += (it != tokens.end()) ? it->second : kEmpty;
            }
        }, seg);
    });

    return result;
}

bool LogTemplateEngine::loadTemplate(const std::string& formatRaw) {
    m_lines.clear();
    m_compiled.clear();

    if (formatRaw.empty()) {
        LOG_WARN("TEMPLATE", "loadTemplate: formatRaw is empty");
        return false;
    }

    m_lines.push_back(formatRaw);
    m_rawFormat = formatRaw;
    m_compiled.push_back(compileLine(formatRaw));

    LOG_INFO("TEMPLATE", std::format("Template compiled from raw string, segments={}",
        m_compiled[0].segments.size()));
    return true;
}

std::string LogTemplateEngine::render(
    const std::flat_map<std::string, std::string>& tokens) const
{
    if (m_compiled.empty()) return {};
    const CompiledLine* cl = &m_compiled[0];
    if (m_compiled.size() > 1) {
        std::uniform_int_distribution<size_t> d(0, m_compiled.size() - 1);
        cl = &m_compiled[d(m_rng)];
    }
    return renderCompiled(*cl, tokens);
}

std::vector<LogTemplate> LogTemplateEngine::loadFromDirectory(const std::string& dirPath) {
    std::vector<LogTemplate> templates;
    if (!fs::exists(dirPath) || !fs::is_directory(dirPath)) {
        LOG_WARN("TEMPLATE", std::format("Template directory not found: {}", dirPath));
        return templates;
    }

    size_t loaded = 0, failed = 0;

    auto entries = fs::directory_iterator(dirPath)
        | std::views::filter([](const fs::directory_entry& e) {
              return e.is_regular_file();
          })
        | std::views::filter([](const fs::directory_entry& e) {
              const auto ext = e.path().extension().string();
              return ext == ".json" || ext == ".txt";
          });

    for (const auto& entry : entries) {
        const auto& path = entry.path();
        const auto  ext  = path.extension().string();

        try {
            LogTemplate tmpl;
            tmpl.name = path.stem().string();

            if (ext == ".json") {
                std::ifstream f(path);
                if (!f.is_open()) { ++failed; continue; }
                const json root = json::parse(f);

                if (!root.contains("format") || !root["format"].contains("raw")) {
                    ++failed; continue;
                }
                const auto& rawNode = root["format"]["raw"];
                if (rawNode.is_array()) {
                    for (const auto& item : rawNode
                            | std::views::filter([](const json& j) {
                                  return j.is_string() && !j.get<std::string>().empty();
                              })) {
                        tmpl.lines.push_back(item.get<std::string>());
                    }
                } else if (rawNode.is_string()) {
                    std::string l = rawNode.get<std::string>();
                    if (!l.empty()) tmpl.lines.push_back(std::move(l));
                }
            } else {
                std::ifstream file(path);
                if (!file.is_open()) { ++failed; continue; }

                auto lines = std::ranges::istream_view<std::string>(file)
                    | std::views::filter([](const std::string& l) { return !l.empty(); });
                std::ranges::copy(lines, std::back_inserter(tmpl.lines));
            }

            if (tmpl.lines.empty()) { ++failed; continue; }
            templates.push_back(std::move(tmpl));
            ++loaded;

        } catch (const json::exception& e) {
            LOG_WARN("TEMPLATE", std::format("JSON parse error: {}: {}",
                path.string(), e.what()));
            ++failed;
        }
    }

    LOG_INFO("TEMPLATE", std::format("loadFromDirectory: dir={} loaded={} failed={}",
        dirPath, loaded, failed));
    return templates;
}

template<typename LookupFn>
static std::string renderRaw(const std::string& tpl, LookupFn lookup) {
    std::string result;
    result.reserve(tpl.size() + 128);
    size_t pos = 0;
    while (pos < tpl.size()) {
        const size_t dollarPos = tpl.find('$', pos);
        if (dollarPos == std::string::npos) {
            result.append(tpl, pos, tpl.size() - pos);
            break;
        }
        result.append(tpl, pos, dollarPos - pos);
        if (dollarPos + 1 >= tpl.size()) { result += '$'; pos = dollarPos + 1; continue; }
        if (tpl[dollarPos + 1] == '{') {
            const size_t end = tpl.find('}', dollarPos + 2);
            if (end == std::string::npos) {
                result.append(tpl, dollarPos, tpl.size() - dollarPos);
                break;
            }
            result += lookup(tpl.substr(dollarPos + 2, end - dollarPos - 2));
            pos = end + 1;
        } else if (std::isupper(static_cast<unsigned char>(tpl[dollarPos + 1]))
                || tpl[dollarPos + 1] == '_') {
            size_t ks = dollarPos + 1, ke = ks;
            while (ke < tpl.size() &&
                   (std::isupper(static_cast<unsigned char>(tpl[ke]))
                    || tpl[ke] == '_'
                    || std::isdigit(static_cast<unsigned char>(tpl[ke])))) ++ke;
            result += lookup(tpl.substr(ks, ke - ks));
            pos = ke;
        } else {
            result += '$';
            pos = dollarPos + 1;
        }
    }
    return result;
}

std::string LogTemplateEngine::render(const LogTemplate& tmpl, const FieldGenerator& gen) {
    if (tmpl.lines.empty()) return {};
    const std::string& line = tmpl.lines[gen.pickIndex(tmpl.lines.size())];
    return renderRaw(line, [&gen](const std::string& key) { return gen.generate(key); });
}
