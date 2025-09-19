// main.cpp

#include <iostream>
using namespace std;
#include "TriangleAngles.hpp"

int main() {
    double a, b, c;

    // Test Case 1
    a = 16.5; b = 17; c = 21;
    TriangleAngles t1(a, b, c);
    t1.computeAngles();
    t1.printAngles();

    // Test Case 2
    a = 5; b = 5; c = 10;
    TriangleAngles t2(a, b, c);
    t2.computeAngles();
    t2.printAngles();

    // Test Case 3
    a = 3; b = 4; c = 5;
    TriangleAngles t3(a, b, c);
    t3.computeAngles();
    t3.printAngles();

    return 0;
}
