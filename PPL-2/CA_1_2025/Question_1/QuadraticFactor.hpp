// QuadraticFactor.hpp
#ifndef QUADRATIC_FACTOR_HPP
#define QUADRATIC_FACTOR_HPP

class QuadraticFactor {
private:
    double a, b, c;
public:
    QuadraticFactor(double a, double b, double c);
    void factorize();
};

#endif
