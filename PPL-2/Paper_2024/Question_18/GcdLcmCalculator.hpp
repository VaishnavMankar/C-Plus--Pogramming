// GcdLcmCalculator.hpp

#ifndef GCDLCMCALCULATOR_HPP
#define GCDLCMCALCULATOR_HPP

class GcdLcmCalculator {
public:
    GcdLcmCalculator(int a, int b);

    int getGCD() const;
    int getLCM() const;

private:
    int num1, num2;

    int computeGCD(int a, int b) const;
};

#endif
