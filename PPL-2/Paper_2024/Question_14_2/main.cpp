// main.cpp
#include <iostream>
using namespace std;

#include "Triangle.hpp"

int main() {
    Triangle t1(16.5, 17, 21);
    t1.findAngles();

    Triangle t2(5, 5, 10);
    t2.findAngles();

    Triangle t3(3, 4, 5);
    t3.findAngles();

    return 0;
}
