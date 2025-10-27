#pragma once

#include <string>

#include "plot.h"

class Carrot : public Plot {
    private:
        int age = 0;

    public:
        std::string symbol() override;
        bool matureFlag() override;
        void end_day() override;
};