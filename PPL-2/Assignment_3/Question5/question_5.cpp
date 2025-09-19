#include "question_5.hpp"

using namespace std;

// Function to calculate GCD (Greatest Common Divisor) using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void question_5::convertToFraction(const string &number) {
    size_t dotPos = number.find('.');  // Find position of '.'

    if (dotPos == string::npos) {
        cout << number << " + 0 / 1" << endl;  // No fractional part
        return;
    }

    string intPart = number.substr(0, dotPos);  // Extract integer part
    string fracPart = number.substr(dotPos + 1); // Extract fractional part

    int numerator = stoi(fracPart);   // Convert fraction part to integer
    int denominator = 1;

    for (int i = 0; i < fracPart.length(); i++) {
        denominator *= 10; // Denominator becomes 10, 100, 1000, etc.
    }

    int commonDivisor = gcd(numerator, denominator); // Reduce fraction

    numerator /= commonDivisor;
    denominator /= commonDivisor;

    if (intPart == "0") { 
        cout << numerator << " / " << denominator << endl;
    } else {
        cout << intPart << " + " << numerator << " / " << denominator << endl;
    }
}
