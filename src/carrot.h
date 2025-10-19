#pragma once

#include <string>

#include "plot.h"

class Carrot : public Plot {
public:
    std::string symbol() override;
};