// LeapYearChecker.cpp

#include "LeapYearChecker.hpp"

LeapYearChecker::LeapYearChecker(int y) {
    year = y;
}

bool LeapYearChecker::isLeapYear() const {
    if (year < 1000 || year > 9999) {
        return false; // not a valid 4-digit year
    }

    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 == 0) {
        return true;
    } else {
        return false;
    }
}
