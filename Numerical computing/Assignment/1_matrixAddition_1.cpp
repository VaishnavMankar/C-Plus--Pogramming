#include<iostream>
using namespace std;
 
int main()
{
    int rows = 3, colm = 3;
    int sum[rows][colm],diff[rows][colm];

    int mat1[rows][colm] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    int mat2[rows][colm] = {
        {2,2,2},
        {2,2,2},
        {2,2,2}
    };

    //matrix addition
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    //matrix subtraction
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            diff[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    cout << "sum of matrix" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    cout << "subtraction of matrix" << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    //check if matrix in identity matrix or not
    bool isIdentity = false;
    bool rest = false;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < colm; j++){
            if(i == j && mat1[i][j] == 1){
                 isIdentity = true;
            }
            if(i != j && mat1[i][j] == 0){
                 rest = true;
            }
        }
    }
    if(isIdentity == rest){
        cout << "is identity" << endl;
    }
    else{
        cout << "Not" << endl;
    }

}