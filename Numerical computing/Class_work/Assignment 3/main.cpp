// main.cpp
#include <iostream>
#include "LagrangesInterpolation.hpp"

using namespace std;

int main() {
    int n;
    float x;

    cout << "Enter number of terms: ";
    cin >> n;

    LagrangesInterpolation li(n);

    li.inputValues();

    cout << "Enter the value of x for which you want y: ";
    cin >> x;

    float result = li.interpolate(x);
    cout << "Value at X = " << x << " is = " << result << endl;

    return 0;
}
