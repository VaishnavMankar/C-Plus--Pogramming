#include<iostream>
#include"LeapYear.hpp"
using namespace std;

int main(){
    int year;
    cout << "Enter a year between 1000 to 9999: \n";
    cin >> year;
    
    LeapYear Y(year);
    if(Y.isLeapYear()){
        cout << year << " is leap year\n";
    }
    else{
        cout << year << " is not a leap year\n";
    }
    return 0;
}