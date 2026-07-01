// src/engine/TICategoryMapper.h
#pragma once

#include <string>

struct TICategoryContext {
    std::string dstPort;
    std::string proto;
    std::string action;
};

class TICategoryMapper {
public:
    [[nodiscard]] static TICategoryContext map(const std::string& category,
                                               const std::string& tiSeverity);
};
