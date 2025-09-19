#include "basic_25_2.hpp"
#include<iostream>
using namespace std;

void basic_25_2 :: setData(int v1, int v2){
    a = v1;
    b = v2;
}

void basic_25_2 :: setDataBySum(basic_25_2 o1, basic_25_2 o2){
    a = o1.a + o2.a;
    b = o1.b + o2.b;
}

void basic_25_2 :: printNumber(){
    cout <<"Your complex number is "<<a<<" +i" << b <<endl;
}