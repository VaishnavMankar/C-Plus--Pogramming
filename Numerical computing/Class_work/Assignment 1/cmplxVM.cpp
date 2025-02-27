#include "cmplxVM.hpp"
#include<iostream>
#include <cmath>
#include<string>

//constructor
cmplxVM ::cmplxVM()
{
    real = 0;
    img = 0;
    std :: cout << "\n In cmplxVm default constant .....\n";
}

void cmplxVM::display()
{
    std :: cout << this->real ;
    // std :: cout << (this->img>0)?"+":""; 
    if(this->img>0)
    {
        std::cout << " + "; 
    }else   std::cout << "";
    std :: cout << this->img << "i" << std::endl;
}

//addition
cmplxVM cmplxVM::add(cmplxVM y)
{
    cmplxVM c;
    c.real = this -> real + y.real;
    c.img = this-> img + y.img;

    return c;
}

//subtraction
cmplxVM cmplxVM::subtraction(cmplxVM y)
{
    cmplxVM c;
    c.real = this -> real - y.real;
    c.img = this-> img - y.img;

    return c;
}

//multiplication
cmplxVM cmplxVM::multiplication(cmplxVM y)
{
    cmplxVM c;
    c.real = (this -> real * y.real) - (img * y.img);
    c.img = (this-> real * y.img) + (img * y.real);

    return c;
}

//division
cmplxVM cmplxVM::divide(cmplxVM y)
{
    cmplxVM c;
    double denominator = pow(y.real, 2) + pow(y.img, 2);
        c.real = ((this->real * y.real) + (img * y.img)) / denominator;
        c.img = ((this->img * y.real) - (real * y.img)) / denominator;
    return c;
}

//norm
 double cmplxVM::norm() {
        return sqrt((real*real) + (img*img));
    }

cmplxVM cmplxVM::conjugate(cmplxVM y){
    cmplxVM c;
    c.real = real;
    c.img = -img;
    return c;
}