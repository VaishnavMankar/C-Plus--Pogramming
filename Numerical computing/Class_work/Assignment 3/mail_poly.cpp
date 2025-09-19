#include "Polynomial.hpp"
#include <iostream>
using namespace std;

int main() {
    Polynomial poly("data.txt");

    poly.lagrangeInterpolation();
    poly.leastSquaresLine();
    poly.leastSquaresParabola();

    return 0;
}

