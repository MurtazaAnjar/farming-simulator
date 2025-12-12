#pragma once
#include <string>

class Bunny {
public:
    enum class State {
        Normal,
        Scared
    };

    Bunny(int row, int col, std::string symbol = "&");

    int getRow() const;
    int getCol() const;
    std::string getSymbol() const;
    State getState() const;

    //void setPosition(int newRow, int newCol);
    void setState(State s);
    bool isPlayerAdjacent(int playerRow, int playerCol) const;
    void moveNormal();
    void moveScared(int playerRow, int playerCol);
    bool isOffMap(int maxRows, int maxCols) const;

private:
    int row;
    int col;
    std::string symbol;
    State state;
};

