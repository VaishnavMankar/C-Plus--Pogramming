#include "Board.h"
#include <iostream>
using namespace std;

int main() {
    Board board;
    if (board.placeQueens(0)) {
        cout << "Solution Found:\n";
        board.printBoard();
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}
