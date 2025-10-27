#include "soil.h"

std::string Soil::symbol() {
    return ".";
}

bool Soil::matureFlag(){
    return false;
}

void Soil::end_day() {
  // no-op
}