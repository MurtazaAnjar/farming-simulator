#include <string>

#include "carrot.h"

std::string Carrot::symbol() {
    return age>0? "C" : "c";
}

bool Carrot::matureFlag(){
    return (age>0)? true : false;
}

void Carrot::end_day() {
  age += 1;
}