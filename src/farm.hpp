#pragma once

#include <string>
#include <vector>

#include "bunny.h"
#include "plot.h"
#include "player.h"

class Farm {
private:
    int rows;
    int columns;
    int day{1};
    Player *player;
    Bunny *bunny;

    std::vector<std::vector<Plot *>> plots;

public:
    Farm(int rows, int columns, Player *player);
    int number_of_rows();
    int number_of_columns();
    int getDay();
    std::string get_symbol(int row, int column);
    void spawnBunny(int chancePercent);
    void water(int row, int column);
    void plant(int row, int column, Plot *plot);
    void end_day();
    void harvest(int row, int column);
    ~Farm();
};