// src/engine/ScenarioSelector.h
#pragma once

#include <vector>
#include <random>
#include <string>
#include <string_view>
#include "core/DeviceProfile.h"

struct ScenarioResult {
    std::string_view attackName;
    std::string_view customLog;
    bool             isCustom = false;
};

class ScenarioSelector {
public:
    ScenarioSelector()
        : m_rng(std::random_device{}())
    {}

    void updateScenarios(const std::vector<EventScenario>& scenarios) {
        m_scenarios = scenarios;
        m_customIndex = 0;

        m_customScenarios.clear();
        m_weightScenarios.clear();

        for (const auto& s : m_scenarios) {
            if (!s.customLog.empty())
                m_customScenarios.push_back(&s);
            else
                m_weightScenarios.push_back(&s);
        }

        std::vector<double> weights;
        weights.reserve(m_weightScenarios.size());
        for (const auto* s : m_weightScenarios)
            weights.push_back(static_cast<double>(s->weight));
        if (weights.empty())
            weights.push_back(1.0);
        m_distribution = std::discrete_distribution<size_t>(weights.begin(), weights.end());
    }

    [[nodiscard]] ScenarioResult select() const {
        if (!m_customScenarios.empty()) {
            const auto* s = m_customScenarios[m_customIndex % m_customScenarios.size()];
            ++m_customIndex;
            return ScenarioResult{ s->attackName, s->customLog, true };
        }
        if (m_weightScenarios.empty())
            return ScenarioResult{ "Normal_Traffic", {}, false };
        const size_t idx = m_distribution(m_rng);
        const auto* s = m_weightScenarios[idx < m_weightScenarios.size() ? idx : 0];
        return ScenarioResult{ s->attackName, {}, false };
    }

    [[nodiscard]] std::string_view selectAttackScenario() const {
        return select().attackName;
    }

private:
    std::vector<EventScenario>         m_scenarios;
    std::vector<const EventScenario*>  m_customScenarios;
    std::vector<const EventScenario*>  m_weightScenarios;
    mutable size_t                     m_customIndex{};
    mutable std::mt19937               m_rng;
    mutable std::discrete_distribution<size_t> m_distribution;
};
