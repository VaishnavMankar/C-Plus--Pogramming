#ifndef BOARD_H
#define BOARD_H

#include "Queen.h"

class Board {
private:
    Queen queens[8]; 
public:
    Board(); 
    bool placeQueens(int row);
    bool isSafe(int row, int col);
    void printBoard();
};

#endif
