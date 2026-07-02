// src/engine/WorkerAllocationStrategy.cpp
#include "WorkerAllocationStrategy.h"
#include <algorithm>
#include <cmath>
#include <numeric>

std::vector<int>
WorkerAllocationStrategy::allocate(
        const std::vector<const DeviceProfile*>& profiles,
        int poolSize) {
    const int count = static_cast<int>(profiles.size());
    std::vector<int> workerCounts(count, 1);

    const int remaining = poolSize - count;
    if (remaining <= 0 || count == 0)
        return workerCounts;

    std::vector<double> eps(count);
    for (int i = 0; i < count; ++i) {
        const double v = static_cast<double>(
            profiles[i]->scheduler.normalRateToEps());
        eps[i] = (v > 1.0) ? v : 1.0;
    }

    const double totalEps = std::accumulate(eps.begin(), eps.end(), 0.0);

    std::vector<double> share(count);
    for (int i = 0; i < count; ++i)
        share[i] = (eps[i] / totalEps) * static_cast<double>(remaining);

    for (int i = 0; i < count; ++i)
        workerCounts[i] += static_cast<int>(share[i]);

    int allocated = 0;
    for (int i = 0; i < count; ++i) allocated += workerCounts[i];
    int leftover = poolSize - allocated;
    if (leftover > 0) {
        std::vector<std::pair<double, int>> rem;
        rem.reserve(count);
        for (int i = 0; i < count; ++i)
            rem.emplace_back(share[i] - std::floor(share[i]), i);
        std::sort(rem.begin(), rem.end(),
            [](const std::pair<double,int>& a, const std::pair<double,int>& b){
                return a.first > b.first;
            });
        for (int k = 0; k < leftover && k < count; ++k)
            ++workerCounts[rem[k].second];
    }

    return workerCounts;
}
