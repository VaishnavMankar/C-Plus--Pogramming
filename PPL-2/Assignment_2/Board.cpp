#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    // Default constructor
}

bool Board::isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (queens[i].canAttack(row, col)) {
            return false;
        }
    }
    return true;
}

bool Board::placeQueens(int row) {
    if (row >= 8) return true; 

    for (int col = 0; col < 8; col++) {
        if (isSafe(row, col)) {
            queens[row] = Queen(row, col); 
            if (placeQueens(row + 1)) return true; 
        }
    }
    return false; 
}

void Board::printBoard() {
    char board[8][8] = {};
    
    for (int i = 0; i < 8; i++) {
        board[queens[i].getRow()][queens[i].getCol()] = 'Q';
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << (board[i][j] == 'Q' ? 'Q' : '-') << " ";
        }
        cout << endl;
    }
}
