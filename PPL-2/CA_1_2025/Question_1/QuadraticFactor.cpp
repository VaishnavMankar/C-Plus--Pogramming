// QuadraticFactor.cpp
#include "QuadraticFactor.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

QuadraticFactor::QuadraticFactor(double aCoeff, double bCoeff, double cCoeff) {
    a = aCoeff;
    b = bCoeff;
    c = cCoeff;
}

void QuadraticFactor::factorize() {
    if (a == 0) {
        cout << "This is not a quadratic equation." << endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;
    double twoA = 2 * a;

    cout << "Factorized form: ";

    if (discriminant > 0) {
        double r1 = (-b + sqrt(discriminant)) / twoA;
        double r2 = (-b - sqrt(discriminant)) / twoA;
        cout << fixed << setprecision(2);
        cout << "(x - " << r1 << ")(x - " << r2 << ")" << endl;
    }
    else if (discriminant == 0) {
        double r = -b / twoA;
        cout << fixed << setprecision(2);
        cout << "(x - " << r << ")^2" << endl;
    }
    else {
        double realPart = -b / twoA;
        double imagPart = sqrt(-discriminant) / twoA;
        cout << fixed << setprecision(2);
        cout << "(x - (" << realPart << " + " << imagPart << "i))";
        cout << "(x - (" << realPart << " - " << imagPart << "i))" << endl;
    }
}
