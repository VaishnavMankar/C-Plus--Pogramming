#include "LagrangesInterpolation.hpp"
#include <iostream>
using namespace std;

LagrangesInterpolation::LagrangesInterpolation(int n) {
    this->n = n;
    X.resize(n);
    Y.resize(n);
}

void LagrangesInterpolation::inputValues() {
    cout << "Enter Value of X: \n";
    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    cout << "Enter Value of Y: \n";
    for (int i = 0; i < n; i++) {
        cin >> Y[i];
    }
}

 float LagrangesInterpolation::interpolate(float x) {
    float sum = 0, term;

    for (int i = 0; i < n; i++) {
        term = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (x - X[j]) / (X[i] - X[j]);
            }
        }
        sum += term * Y[i];
    }

    return sum;
}
