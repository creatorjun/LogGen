// src/engine/TIPool.cpp
#include "TIPool.h"
#include <fstream>
#include <sstream>
#include <random>

bool TIPool::loadFromCSV(const std::string& csvPath) {
    std::unique_lock<std::shared_mutex> lock(m_mutex);
    std::ifstream file(csvPath);
    if (!file.is_open()) return false;

    m_entries.clear();
    std::string line;
    if (!std::getline(file, line)) return false;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        TIEntry entry;
        if (std::getline(ss, entry.ip,          ',') &&
            std::getline(ss, entry.countryCode,  ',') &&
            std::getline(ss, entry.countryName,  ',') &&
            std::getline(ss, entry.category,     ',') &&
            std::getline(ss, entry.severity,     ',') &&
            std::getline(ss, entry.description,  ',') &&
            std::getline(ss, entry.source,       ','))
        {
            m_entries.push_back(std::move(entry));
        }
    }
    return !m_entries.empty();
}

TIEntry TIPool::getRandomTI() const {
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    if (m_entries.empty()) return {};
    thread_local std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<size_t> dist(0, m_entries.size() - 1);
    return m_entries[dist(rng)];
}

bool TIPool::empty() const {
    std::shared_lock<std::shared_mutex> lock(m_mutex);
    return m_entries.empty();
}
