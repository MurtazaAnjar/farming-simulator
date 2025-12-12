#include "bunny.h"
#include <cstdlib>
#include <cmath>

Bunny::Bunny(int row, int col, std::string symbol) : row(row), col(col), symbol(symbol), state(State::Normal) {}

// Accessors
int Bunny::getRow() const { return row; }
int Bunny::getCol() const { return col; }
std::string Bunny::getSymbol() const { return symbol; }
Bunny::State Bunny::getState() const { return state; }

// Mutators
// void Bunny::setPosition(int newRow, int newCol) {
//     row = newRow;
//     col = newCol;
// }
//
void Bunny::setState(State s) {
    state = s;
}

bool Bunny::isPlayerAdjacent(int playerRow, int playerCol) const {
    int dr = std::abs(playerRow - row);
    int dc = std::abs(playerCol - col);
    return (dr + dc == 1);
}

// Normal Movement (1 step)
void Bunny::moveNormal() {
    int direction = rand() % 4;
    switch (direction) {
        case 0: row--; break; // up
        case 1: row++; break; // down
        case 2: col--; break; // left
        case 3: col++; break; // right
    }
}

// Scared Movement (4 steps away from player)
void Bunny::moveScared(int playerRow, int playerCol) {
    int dRow = row - playerRow;
    int dCol = col - playerCol;

    // Determine direction away from player
    int stepRow = (dRow > 0) ? 1 : (dRow < 0 ? -1 : 0);
    int stepCol = (dCol > 0) ? 1 : (dCol < 0 ? -1 : 0);

    // Move EXACTLY 4 tiles away in that direction
    row += (stepRow * 4);
    col += (stepCol * 4);
    state = State::Normal;
}


// Check if bunny left the map
bool Bunny::isOffMap(int maxRows, int maxCols) const {
    return (row < 0 || row >= maxRows || col < 0 || col >= maxCols);
}
