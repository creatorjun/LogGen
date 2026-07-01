// src/ui/viewmodel/TimeSeriesData.h
#pragma once

#include <vector>
#include <cstddef>

struct TimeSeriesData {
    static constexpr size_t kMaxPoints = 7200;

    std::vector<float> xs;
    std::vector<float> ys;
    size_t             head      = 0;
    size_t             count     = 0;
    float              windowSec = 120.0f;

    TimeSeriesData() {
        xs.resize(kMaxPoints, 0.0f);
        ys.resize(kMaxPoints, 0.0f);
    }

    void AddPoint(float x, float y) {
        xs[head] = x;
        ys[head] = y;
        head = (head + 1) % kMaxPoints;
        if (count < kMaxPoints) ++count;
        const float oldest = x - windowSec;
        while (count > 0) {
            const size_t tail = (head + kMaxPoints - count) % kMaxPoints;
            if (xs[tail] < oldest) --count;
            else break;
        }
    }

    void getLinear(std::vector<float>& outXs, std::vector<float>& outYs) const {
        outXs.resize(count);
        outYs.resize(count);
        const size_t tail = (head + kMaxPoints - count) % kMaxPoints;
        for (size_t i = 0; i < count; ++i) {
            const size_t idx = (tail + i) % kMaxPoints;
            outXs[i] = xs[idx];
            outYs[i] = ys[idx];
        }
    }

    void Erase() { head = 0; count = 0; }
    [[nodiscard]] int Size() const { return static_cast<int>(count); }
};
