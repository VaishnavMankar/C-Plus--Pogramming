// SymmetricDates.hpp
#ifndef SYMMETRIC_DATES_HPP
#define SYMMETRIC_DATES_HPP

class SymmetricDates {
public:
    void findSymmetricDates();
private:
    bool isValidDate(int day, int month, int year);
    bool isPalindrome(const char* dateStr);
};

#endif
