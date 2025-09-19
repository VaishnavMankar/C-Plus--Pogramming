#include "question_2.hpp"
#include<iostream>
using namespace std;

void question_2::setValues(string number) {
    size_t dotPos = number.find('.');
    
    if (dotPos != string::npos) {
        integerPart = number.substr(0, dotPos); //everything before .
        fractionalPart = number.substr(dotPos + 1); //everything after .
    } else {
        integerPart = number;
        fractionalPart = "0"; // Default to "0" if no fractional part is provided
    }
}

string question_2::formatNumber() {
    // Remove leading zeros from fractional part
    while (!fractionalPart.empty() && fractionalPart[0] == '0') {
        fractionalPart.erase(0, 1);
    }

    // Remove leading zeros from integer part
    while (!integerPart.empty() && integerPart[0] == '0') {
        integerPart.erase(0, 1);
    }

    if (integerPart.empty()) {
        integerPart = "0"; // Handle cases where integer part becomes empty
    }

    // Determine the number of '#' characters to align decimal at position 6
    int numHashes = 6 - integerPart.length();
    string hashString = (numHashes > 0) ? string(numHashes, '#') : "";

    return fractionalPart + hashString + "." + integerPart;
}
