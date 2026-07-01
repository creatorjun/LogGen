// src/engine/TIPool.h
#pragma once

#include <string>
#include <vector>
#include <shared_mutex>

struct TIEntry {
    std::string ip;
    std::string countryCode;
    std::string countryName;
    std::string category;
    std::string severity;
    std::string description;
    std::string source;
};

class TIPool {
public:
    TIPool()  = default;
    ~TIPool() = default;

    [[nodiscard]] bool    loadFromCSV(const std::string& csvPath);
    [[nodiscard]] TIEntry getRandomTI() const;
    [[nodiscard]] bool    empty() const;

private:
    std::vector<TIEntry>      m_entries;
    mutable std::shared_mutex m_mutex;
};
