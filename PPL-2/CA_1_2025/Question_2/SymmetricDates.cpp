// SymmetricDates.cpp
#include "SymmetricDates.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;

bool SymmetricDates::isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    return day >= 1 && day <= daysInMonth[month - 1];
}

bool SymmetricDates::isPalindrome(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i)
        if (str[i] != str[len - 1 - i])
            return false;
    return true;
}

void SymmetricDates::findSymmetricDates() {
    for (int year = 2001; year <= 2100; ++year) {
        for (int month = 1; month <= 12; ++month) {
            for (int day = 1; day <= 31; ++day) {
                if (!isValidDate(day, month, year)) continue;

                ostringstream oss;
                oss << setfill('0') << setw(2) << day
                    << setw(2) << month
                    << setw(4) << year;
                string digits = oss.str();

                if (isPalindrome(digits.c_str())) {
                    cout << setfill('0') << setw(2) << day << "-"
                         << setw(2) << month << "-"
                         << setw(4) << year << endl;
                }
            }
        }
    }
}
