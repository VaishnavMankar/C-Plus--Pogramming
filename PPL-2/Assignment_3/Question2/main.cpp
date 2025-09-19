#include "question_2.hpp"
#include<iostream>
#include<string>
using namespace std;

int main() {
    string number;
    cout << "Enter a positive real number: ";
    cin >> number;

    question_2 formatter;
    formatter.setValues(number);
    string result = formatter.formatNumber();

    cout << "Formatted Number: " << result <<endl;
    return 0;
}
