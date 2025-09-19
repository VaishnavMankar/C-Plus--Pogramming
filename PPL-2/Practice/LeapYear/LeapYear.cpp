#include<iostream>
#include"LeapYear.hpp"
using namespace std;

LeapYear :: LeapYear(int y){
    year = y;
}

bool LeapYear :: isLeapYear(){
    if(year < 1000 || year > 9999){
        return false;
    }

    if(year % 4 != 0){
        return false;
    }
    else if(year % 100 != 0){
        return true;
    }
    else if(year % 400 == 0){
        return true;
    }
    else{
        return false;
    }
}