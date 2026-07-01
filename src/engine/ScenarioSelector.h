// src/engine/ScenarioSelector.h
#pragma once

#include <vector>
#include <random>
#include <string>
#include "core/DeviceProfile.h"

class ScenarioSelector {
public:
    ScenarioSelector()
        : m_rng(std::random_device{}())
    {}

    void updateScenarios(const std::vector<EventScenario>& scenarios) {
        m_scenarios = scenarios;
        std::vector<double> weights;
        weights.reserve(scenarios.size());
        for (const auto& s : scenarios)
            weights.push_back(static_cast<double>(s.weight));
        if (weights.empty())
            weights.push_back(1.0);
        m_distribution = std::discrete_distribution<size_t>(weights.begin(), weights.end());
    }

    [[nodiscard]] std::string_view selectAttackScenario() const {
        if (m_scenarios.empty()) return "Normal_Traffic";
        const size_t index = m_distribution(m_rng);
        if (index < m_scenarios.size())
            return m_scenarios[index].attackName;
        return "Normal_Traffic";
    }

private:
    std::vector<EventScenario>                 m_scenarios;
    mutable std::mt19937                       m_rng;
    mutable std::discrete_distribution<size_t> m_distribution;
};
