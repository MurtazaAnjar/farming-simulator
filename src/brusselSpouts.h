#pragma once
#include <string>

#include "plot.h"

class BrusselSpouts : public Plot {
private:
    int age = 0;
    bool watered = false;

public:
    std::string symbol() override {
        if (age>=0 && age<5) {
            return "*";
        }else if (age>4 && age<15) {
            return "r";
        }else {
            return "R";
        }
    }
    bool matureFlag() override {
        return (age>0)? true : false;
    }
    void end_day() override {
        if(watered) {
            age += 2;
        } else {
            age += 1;
        }
        watered = false;
    }
    void water() override {
        watered = true;
    }
    int get_age() const {
        return age;
    }
};