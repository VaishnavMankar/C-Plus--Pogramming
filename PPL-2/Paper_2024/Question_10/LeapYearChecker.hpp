// LeapYearChecker.hpp

#ifndef LEAPYEARCHECKER_HPP
#define LEAPYEARCHECKER_HPP

class LeapYearChecker {
public:
    LeapYearChecker(int y);
    bool isLeapYear() const;

private:
    int year;
};

#endif
