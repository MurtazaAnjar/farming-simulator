#pragma once

#include <string>

class Plot {
public:
    virtual ~Plot() = default;

    virtual std::string symbol() = 0;
    virtual bool matureFlag() = 0;
    virtual void end_day() = 0;
    virtual void water() = 0;
};