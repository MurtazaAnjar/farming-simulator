#include <string>

#include "carrot.h"

std::string Carrot::symbol() {
    return age>0? "C" : "c";
}

bool Carrot::matureFlag(){
    return (age>0)? true : false;
}

void Carrot::end_day() {
  if(watered) {
    age += 2;
  } else {
    age += 1;
  }
  watered = false;
}

void Carrot::water() {
  watered = true;
}

int Carrot::get_age() {
  return age;
}