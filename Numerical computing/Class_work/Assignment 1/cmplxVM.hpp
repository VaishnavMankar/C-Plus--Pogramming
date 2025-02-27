#include<iostream>

class cmplxVM
{
    public:
         //Data member
         double real,img;

         //member functions
         cmplxVM();
         void display();
         cmplxVM add(cmplxVM y);
         cmplxVM subtraction(cmplxVM y);
         cmplxVM multiplication(cmplxVM y);
         cmplxVM divide(cmplxVM y);
         double norm();
         cmplxVM conjugate(cmplxVM y);
};