// src/engine/WorkerAllocationStrategy.h
#pragma once
#include <vector>
#include "core/DeviceProfile.h"

class WorkerAllocationStrategy {
public:
    [[nodiscard]] static std::vector<int>
        allocate(const std::vector<const DeviceProfile*>& profiles,
                 int poolSize);
};
