#include"basic_25_2.hpp"
#include<iostream>
using namespace std;

int main(){
    basic_25_2 c1,c2,c3;
    c1.setData(1,2);
    c1.printNumber();
    c2.setData(4,5);
    c2.printNumber();
    c3.setDataBySum(c1,c2);
    c3.printNumber();
}