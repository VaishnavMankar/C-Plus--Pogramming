#include<iostream>
#include "BaseConverter.hpp"
using namespace std;

void BaseConverter :: setValues(int num, int baseValue){
    number = num;
    base = baseValue;
}

string BaseConverter :: converter(){
    if(base < 2 || base > 36){
        return "Invalid Base";
    }

    if(base == 10){
        return to_string(number);
    }

    string result = "";
    int num = number;
    const char digit[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    do{
        result = digit[num % base]+ result;
        num /= base;
    }while(num > 0);
    
    return result;
}