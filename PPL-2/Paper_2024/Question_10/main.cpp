// main.cpp

#include <iostream>
using namespace std;
#include "LeapYearChecker.hpp"

int main() {
    int year;
    cout << "Enter a 4-digit year: ";
    cin >> year;

    LeapYearChecker checker(year);

    if (checker.isLeapYear()) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }

    return 0;
}
