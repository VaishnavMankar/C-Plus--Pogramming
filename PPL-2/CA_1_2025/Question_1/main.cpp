// main.cpp
#include <iostream>
using namespace std;

#include "QuadraticFactor.hpp"

int main() {
    // Example 1: real distinct roots
    QuadraticFactor q1(1, -5, 6);  // (x - 3)(x - 2)
    q1.factorize();

    // Example 2: perfect square
    QuadraticFactor q2(1, 2, 1);   // (x + 1)^2
    q2.factorize();

    // Example 3: complex roots
    QuadraticFactor q3(1, 4, 5);   // complex roots
    q3.factorize();

    return 0;
}
