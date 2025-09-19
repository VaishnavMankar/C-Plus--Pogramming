#include "Polynomial.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

Polynomial::Polynomial(const string& filename) {
    ifstream file(filename);
    file >> n;
    X.resize(n);
    Y.resize(n);
    for (int i = 0; i < n; ++i) {
        file >> X[i] >> Y[i];
    }
    file >> interpolationX;
    file.close();
}

float Polynomial::lagrangeInterpolation() {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        float term = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (interpolationX - X[j]) / (X[i] - X[j]);
            }
        }
        sum += term * Y[i];
    }
    cout << "Lagrange Interpolation: y(" << interpolationX << ") = " << sum << endl;
    return sum;
}

void Polynomial::leastSquaresLine() {
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < n; i++) {
        sum_x += X[i];
        sum_y += Y[i];
        sum_xy += X[i] * Y[i];
        sum_x2 += X[i] * X[i];
    }

    float a, b;
    float A[2][3] = {
        {sum_x, float(n), sum_y},
        {sum_x2, sum_x, sum_xy}
    };

    float ratio = A[1][0] / A[0][0];
    for (int i = 0; i < 3; i++) {
        A[1][i] -= ratio * A[0][i];
    }

    b = A[1][2] / A[1][1];
    a = (A[0][2] - A[0][1] * b) / A[0][0];

    cout << "Least Squares Line: y = " << a << "x + " << b << endl;
}

void Polynomial::leastSquaresParabola() {
    float sx = 0, sy = 0, sxy = 0, sx2 = 0, sx3 = 0, sx4 = 0, sx2y = 0;
    for (int i = 0; i < n; i++) {
        float x = X[i], y = Y[i];
        sx += x;
        sy += y;
        sxy += x * y;
        sx2 += x * x;
        sx3 += x * x * x;
        sx4 += x * x * x * x;
        sx2y += x * x * y;
    }

    float A[3][4] = {
        {sx2, sx, float(n), sy},
        {sx3, sx2, sx, sxy},
        {sx4, sx3, sx2, sx2y}
    };

    // Convert to upper triangular
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            float ratio = A[j][i] / A[i][i];
            for (int k = 0; k < 4; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }

    float values[3] = {0};
    for (int i = 2; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < 3; j++) {
            sum += A[i][j] * values[j];
        }
        values[i] = (A[i][3] - sum) / A[i][i];
    }

    cout << "Least Squares Parabola: y = " << values[0] << "x^2 + " << values[1] << "x + " << values[2] << endl;
}
