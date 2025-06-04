#ifndef QUEEN_H
#define QUEEN_H

class Queen {
private:
    int row, col;
public:
    Queen();
    Queen(int r, int c);
    bool canAttack(int r, int c);
    int getRow();
    int getCol();
};

#endif
