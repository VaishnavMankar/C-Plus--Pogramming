#include<iostream>
#include "cmplxVM.hpp"

int main()
{
    // Create objects
    cmplxVM obj1, obj2, result;
    
    // Initialize objects
    obj1.real = 3.0;
    obj1.img = 2.0;
    obj2.real = 1.5;
    obj2.img = 4.5;
    
    // Display the initial values
    std::cout << "Object 1: ";
    obj1.display();
    std::cout << "Object 2: ";
    obj2.display();
    
    // Add the two objects
    result = obj1.add(obj2);
    
    // Display the result
    std::cout << "Result: ";
    result.display();
    
    //Subtraction the two objects
    result = obj1.subtraction(obj2);

    // Display the result
    std::cout << "Result: ";
    result.display();

    //multiplication the two objects
    result = obj1.multiplication(obj2);

    // Display the result
    std::cout << "Result: ";
    result.display();

    //division the two objects
    result = obj1.divide(obj2);

    // Display the result
    std::cout << "Result: ";
    result.display();

    // //norm of two number
    // result = norm.obj1;

    return 0;
}
