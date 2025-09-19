// main.cpp
#include <iostream>
using namespace std;

#include "LagrangeInterpolator.hpp"

int main() {
    // Example points: (1, 1), (2, 4), (3, 9)
    double x[] = {1, 2, 3};
    double y[] = {1, 4, 9};
    int size = 3;

    LagrangeInterpolator li(x, y, size);

    double input;
    cout << "Enter x value to interpolate: ";
    cin >> input;

    double result = li.interpolate(input);
    cout << "Interpolated value at x = " << input << " is: " << result << endl;

    return 0;
}
