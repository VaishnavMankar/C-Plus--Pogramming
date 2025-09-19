// Triangle.cpp
#include "Triangle.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
}

bool Triangle::isValid() {
    return (sideA + sideB > sideC) && 
           (sideA + sideC > sideB) && 
           (sideB + sideC > sideA);
}

double Triangle::toDegrees(double rad) {
    return rad * 180.0 / 3.141592653589793;
}

void Triangle::showAngles(double A, double B, double C) {
    cout << "Angles: " 
         << int(A + 0.5) << "°, " 
         << int(B + 0.5) << "°, " 
         << int(C + 0.5) << "°" << endl;
}

void Triangle::findAngles() {
    if (!isValid()) {
        cout << "Invalid input: Cannot form triangle." << endl;
        return;
    }

    double a = sideA, b = sideB, c = sideC;

    double angleA = acos((b*b + c*c - a*a) / (2*b*c));
    double angleB = acos((a*a + c*c - b*b) / (2*a*c));
    double angleC = acos((a*a + b*b - c*c) / (2*a*b));

    showAngles(toDegrees(angleA), toDegrees(angleB), toDegrees(angleC));
}
