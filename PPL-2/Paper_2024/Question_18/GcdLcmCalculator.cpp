// GcdLcmCalculator.cpp

#include "GcdLcmCalculator.hpp"
#include <stdexcept> // for std::invalid_argument

GcdLcmCalculator::GcdLcmCalculator(int a, int b) {
    if (a <= 0 || b <= 0) {
        throw std::invalid_argument("Only positive integers are allowed.");
    }
    num1 = a;
    num2 = b;
}

int GcdLcmCalculator::computeGCD(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int GcdLcmCalculator::getGCD() const {
    return computeGCD(num1, num2);
}

int GcdLcmCalculator::getLCM() const {
    return (num1 * num2) / getGCD();
}
