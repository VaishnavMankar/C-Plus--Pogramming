#include <iostream>

class VMmatrix
{
public:
    int r, c;
    int **data;

    VMmatrix();
    VMmatrix(int r, int c)
    {
        int rows = r;
        int cols = c;
        r = r;
        c = c;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }
    VMmatrix(const VMmatrix &vm);
    void display();
    VMmatrix add(VMmatrix y);
};