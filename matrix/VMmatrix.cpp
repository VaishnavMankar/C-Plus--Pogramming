#include "VMmatrix.hpp"
#include<iostream>


VMmatrix VMmatrix::add(VMmatrix y)
{
    VMmatrix ans(r,c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ans.data[i][j] = data[i][i] + y.data[i][j]; 
        } 
    }
    return ans;
}