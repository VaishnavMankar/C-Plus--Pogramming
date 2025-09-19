// LagrangeInterpolator.cpp
#include "LagrangeInterpolator.hpp"
#include <iostream>
using namespace std;

LagrangeInterpolator::LagrangeInterpolator(double* xPoints, double* yPoints, int size) {
    n = size;
    x = new double[n];
    y = new double[n];
    for (int i = 0; i < n; i++) {
        x[i] = xPoints[i];
        y[i] = yPoints[i];
    }
}

LagrangeInterpolator::~LagrangeInterpolator() {
    delete[] x;
    delete[] y;
}

double LagrangeInterpolator::interpolate(double value) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}
