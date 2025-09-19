// TriangleAngles.cpp

#include "TriangleAngles.hpp"
#include <cmath>
#include <iostream>
using namespace std;

TriangleAngles::TriangleAngles(double a, double b, double c) {
    sideA = a;
    sideB = b;
    sideC = c;
    angleA = angleB = angleC = 0;
}

bool TriangleAngles::isValid() const {
    return (sideA + sideB > sideC) &&
           (sideA + sideC > sideB) &&
           (sideB + sideC > sideA);
}

double TriangleAngles::toDegrees(double radians) const {
    return radians * 180.0 / M_PI;
}

void TriangleAngles::computeAngles() {
    if (!isValid()) return;

    double cosA = (pow(sideB, 2) + pow(sideC, 2) - pow(sideA, 2)) / (2 * sideB * sideC);
    double cosB = (pow(sideA, 2) + pow(sideC, 2) - pow(sideB, 2)) / (2 * sideA * sideC);
    double cosC = (pow(sideA, 2) + pow(sideB, 2) - pow(sideC, 2)) / (2 * sideA * sideB);

    // Clamp values to avoid domain errors in acos due to floating-point precision
    if (cosA < -1) cosA = -1; if (cosA > 1) cosA = 1;
    if (cosB < -1) cosB = -1; if (cosB > 1) cosB = 1;
    if (cosC < -1) cosC = -1; if (cosC > 1) cosC = 1;

    angleA = static_cast<int>(round(toDegrees(acos(cosA))));
    angleB = static_cast<int>(round(toDegrees(acos(cosB))));
    angleC = static_cast<int>(round(toDegrees(acos(cosC))));
}

void TriangleAngles::printAngles() const {
    if (!isValid()) {
        cout << "Invalid input: Cannot form a triangle." << endl;
        return;
    }

    cout << "Angles of triangle: "
         << angleA << "°, "
         << angleB << "°, "
         << angleC << "°" << endl;
}
