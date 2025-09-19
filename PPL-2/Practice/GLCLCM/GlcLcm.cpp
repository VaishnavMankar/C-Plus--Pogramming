#include"GlcLcm.hpp"
#include<iostream>
#include<stdexcept>
using namespace std;

GcdLcm :: GcdLcm(int a, int b){
    if(a <= 0 || b <= 0){
        throw invalid_argument ("Olny integers");
    }
    num1 = a;
    num2 = b;
}

int GcdLcm :: computeGcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int GcdLcm :: getGcd(){
    return computeGcd(num1, num2);
}

int GcdLcm :: getLcm(){
    return (num1 * num2)/getGcd();
}
