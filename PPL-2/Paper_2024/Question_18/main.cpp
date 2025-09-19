// main.cpp

#include <iostream>
#include <exception> // for std::exception
#include "GcdLcmCalculator.hpp"

int main() {
    int a, b;

    std::cout << "Enter two positive integers: ";
    std::cin >> a >> b;

    try {
        GcdLcmCalculator calculator(a, b);

        std::cout << "GCD of " << a << " and " << b << " = " << calculator.getGCD() << std::endl;
        std::cout << "LCM of " << a << " and " << b << " = " << calculator.getLCM() << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unexpected error occurred." << std::endl;
    }
    // try{
    //     GlcLcm num(a,b);
    //     cout << num.getGcd()<<endl;
    //     cout << num.getLcm()<<endl;
    //     }
    //     catch(const char* msg){
    //         cout << "Exception caught: " << msg << endl; 
    //     }

    return 0;
}
