#include "Queen.h"
#include <cmath>  
using namespace std;
Queen::Queen() : row(-1), col(-1) {} // Default constructor

Queen::Queen(int r, int c) : row(r), col(c) {} // Parameterized constructor

bool Queen::canAttack(int r, int c) {
    return (row == r || col == c || abs(row - r) == abs(col - c)); // Same row, column, diagonal
}

int Queen::getRow() { return row; }
int Queen::getCol() { return col; }
