// TriangleAngles.hpp

#ifndef TRIANGLEANGLES_HPP
#define TRIANGLEANGLES_HPP

class TriangleAngles {
public:
    TriangleAngles(double a, double b, double c);
    bool isValid() const;
    void computeAngles();
    void printAngles() const;

private:
    double sideA, sideB, sideC;
    int angleA, angleB, angleC; // angles in degrees

    double toDegrees(double radians) const;
};

#endif
