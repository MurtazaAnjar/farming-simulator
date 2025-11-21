#include <iostream>

#include "src/player.h"
#include "src/farm.hpp"
#include "src/farm_printer.h"
#include "src/carrot.h"
#include "src/lettuce.h"
#include "src/spinach.h"
#include "src/beet.h"
#include "src/brusselSpouts.h"
#include "src/ansi_clear.hpp"

int main() {
  Player player;
  Farm farm(7, 8, &player);
  FarmPrinter printer(&farm);
  bool game_in_progress = true;
  std::string player_input;
  int dayCounter = 1;
  std::string errorMes = "";


  while(game_in_progress) {
    ansi_clear();
    std::cout<<std::endl;
    std::cout<<"Legend: wasd(move), e(end day), q(quit), h(harvest), enter(confirm control)\n\t"
               "Plants: 1(carrot), 2(lettuce), 3(spinach), 4(beet), 5(brussel spouts)"<<std::endl;
    std::cout<<"Day: "<<farm.getDay()<<std::endl;
    if(!errorMes.empty()){
      std::cout<<errorMes<<std::endl;
      errorMes.clear();
    }
    std::cout<<std::endl;
    std::cout << printer.pp() << std::endl;
    std::cin >> player_input;

    if(player_input == "q") {
      game_in_progress = false;
    } else if(player_input == "d") {
      player.move_right(8);
    } else if(player_input == "s") {
      player.move_down(7);
    } else if(player_input == "a") {
      player.move_left();
    } else if(player_input == "w") {
      player.move_up();
    } else if(player_input == "1") {
      Carrot *carrot = new Carrot();
      farm.plant(player.row(), player.column(), carrot);
    } else if(player_input == "2") {
      Lettuce *lettuce = new Lettuce();
      farm.plant(player.row(), player.column(), lettuce);
    } else if(player_input == "3") {
      Spinach *spinach = new Spinach();
      farm.plant(player.row(), player.column(), spinach);
    } else if(player_input == "4") {
      Beet *beet = new Beet();
      farm.plant(player.row(), player.column(), beet);
    } else if(player_input == "5") {
      BrusselSpouts *brussel_spouts = new BrusselSpouts();
      farm.plant(player.row(), player.column(), brussel_spouts);
    } else if(player_input == "h") {
      farm.harvest(player.row(), player.column());
    } else if(player_input == "t") {
      farm.water(player.row(), player.column());
    }else if(player_input == "e"){
      farm.end_day();
    }else{
      errorMes="Invalid Input, try again...";
    }
  }
}