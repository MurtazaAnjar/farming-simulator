#pragma once
#include <string>

#include "plot.h"

class Lettuce : public Plot {
private:
    int age = 0;
    bool watered = false;

public:
    std::string symbol() override {
        if (age>=0 && age<2) {
            return "*";
        }else if (age>1 && age<4) {
            return "l";
        }else {
            return "L";
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