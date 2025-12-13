#include <string>
#include <vector>
#include <cstdlib>

#include "farm.hpp"
#include "soil.h"
#include "bunny.h"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player), bunny(nullptr) {
  for(int i = 0; i < rows; i++) {
    std::vector<Plot *> row;
    for(int j = 0; j < columns; j++) {
      Soil *soil = new Soil();
      row.push_back(soil);
    }
    plots.push_back(row);
  }
}

int Farm::number_of_rows() {
  return rows;
}

int Farm::number_of_columns() {
  return columns;
}

int Farm::getDay() {
  return day;
}

std::string Farm::get_symbol(int row, int column) {
  if(player->row() == row && player->column() == column) {
    return "@";
  }
  if (bunny != nullptr) {
    if (bunny->getRow() == row && bunny->getCol() == column) {
      return bunny->getSymbol();
    }
  }
  return plots.at(row).at(column)->symbol();
}

void Farm::spawnBunny(int chancePercent) {
  if ((rand() % 100) < chancePercent && bunny == nullptr) {
    int spawnCol = columns-1; // default top-right
    if (player->row() == 0 && player->column() == columns-1) {
      spawnCol -= 1; // move 1 left if player is there
    }
    bunny = new Bunny(0, spawnCol);
  }
}

void Farm::plant(int row, int column, Plot *plot) {
  Plot *current_plot = plots.at(row).at(column);
  if(plots.at(row).at(column)->symbol() == "."){
    plots.at(row).at(column) = plot;
    delete current_plot;
  }
  
}

void Farm::end_day(){
  day++;
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      plots.at(i).at(j)->end_day();
    }
  }

  if (bunny != nullptr) {
    //Eat vegetable if on a non-soil plot
    Plot* currentPlot = plots.at(bunny->getRow()).at(bunny->getCol());
    if (currentPlot->symbol() != ".") {
      delete currentPlot;
      plots.at(bunny->getRow()).at(bunny->getCol()) = new Soil();
    }

    //Check if bunny should be scared
    if (bunny->isPlayerAdjacent(player->row(), player->column())) {
      bunny->setState(Bunny::State::Scared);
    }

    //Move bunny
    if (bunny->getState() == Bunny::State::Scared) {
      bunny->moveScared(player->row(), player->column());
    } else {
      bunny->moveNormal();
    }

    //Remove bunny if it went off map
    if (bunny->isOffMap(rows, columns)) {
      delete bunny;
      bunny = nullptr;
    }
  } else {
    spawnBunny(100);
  }
}

void Farm::harvest(int row, int column){
  Plot *current_plot = plots.at(row).at(column);
  if (current_plot->matureFlag()) {
    Soil* soil = new Soil();
    plots.at(row).at(column) = soil;
    delete current_plot;
  }
}

void Farm::water(int row, int column) {
  Plot *current_plot = plots.at(row).at(column);
  current_plot->water();
}

Farm::~Farm() {
  for (auto &row : plots) {
    for (auto &plot : row) {
      delete plot;
    }
  }
}