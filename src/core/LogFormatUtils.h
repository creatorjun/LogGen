// src/core/LogFormatUtils.h
#pragma once

#include "core/LogFormat.h"
#include <string_view>

namespace LogFormatUtils {
    [[nodiscard]] std::string_view toString(LogFormat f) noexcept;
    [[nodiscard]] LogFormat        fromString(std::string_view s) noexcept;
} // namespace LogFormatUtils
