#include "cmplxVM.hpp"

//constructor
cmplxVM ::cmplxVM()
{
    real = 0;
    img = 0;
    std :: cout << "\n In cmplxVm default constant .....\n";
}

void cmplxVM::display()
{
    std :: cout << real << " + " << img << "i" << std :: endl;
}

cmplxVM cmplxVM::add(cmplxVM y)
{
    cmplxVM c;
    c.real = this -> real + y.real;
    c.img = this-> img + y.img;

    return c;
}