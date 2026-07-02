// src/core/LogFormatUtils.cpp
#include "core/DeviceProfile.h"

namespace LogFormatUtils {

std::string_view toString(LogFormat f) noexcept {
    switch (f) {
        case LogFormat::CSV:   return "CSV";
        case LogFormat::KVP:   return "KVP";
        case LogFormat::CEF:   return "CEF";
        case LogFormat::LEF:   return "LEF";
        case LogFormat::PLAIN: return "PLAIN";
    }
    return "PLAIN";
}

LogFormat fromString(std::string_view s) noexcept {
    if (s == "CSV")  return LogFormat::CSV;
    if (s == "KVP")  return LogFormat::KVP;
    if (s == "CEF")  return LogFormat::CEF;
    if (s == "LEF")  return LogFormat::LEF;
    return LogFormat::PLAIN;
}

} // namespace LogFormatUtils
