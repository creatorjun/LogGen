// src/core/Callbacks.h
#pragma once

#include <functional>
#include "core/LogEntry.h"
#include "core/ApiRequestEntry.h"

using LogCallback     = std::function<void(LogEntry)>;
using RequestCallback = std::function<void(const ApiRequestEntry&)>;
