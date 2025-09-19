// Triangle.hpp
#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

class Triangle {
public:
    Triangle(double a, double b, double c);
    bool isValid();
    void findAngles();
private:
    double sideA, sideB, sideC;
    void showAngles(double A, double B, double C);
    double toDegrees(double rad);
};

#endif
