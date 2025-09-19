// LagrangeInterpolator.hpp
#ifndef LAGRANGE_INTERPOLATOR_HPP
#define LAGRANGE_INTERPOLATOR_HPP

class LagrangeInterpolator {
private:
    double* x;
    double* y;
    int n;

public:
    LagrangeInterpolator(double* xPoints, double* yPoints, int size);
    ~LagrangeInterpolator();
    double interpolate(double value);
};

#endif
