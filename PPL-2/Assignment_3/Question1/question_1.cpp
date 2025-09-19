#include "question_1.hpp"
#include<iostream>
using namespace std;

void question_1::setValues(int num, int baseValue) {
    number = num;
    base = baseValue;
}

string question_1::convert() {
    if (base < 2 || base > 36) {
        return "Invalid Base";
    }
    
    if (base == 10) {
        return to_string(number);
    }
    
    string result = "";
    int num = number;
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    do {
        result = digits[num % base] + result;
        num /= base;
    } while (num > 0);
    
    return result;
}
