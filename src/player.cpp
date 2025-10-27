#include "player.h"

int Player::row() {
    return current_row;
}

int Player::column() {
    return current_column;
}

void Player::move_right(int cols) {
    if(current_column<cols-1)
        current_column += 1;
}

void Player::move_down(int rows) {
    if(current_row<rows-1)
        current_row += 1;
}

void Player::move_left(){
    if(current_column>0)
        current_column -=1;
}

void Player::move_up() {
    if(current_row>0)
        current_row -= 1;
}