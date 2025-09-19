#include<iostream>
#include "FloatConverter.hpp"
using namespace std;

void ConvertFloat :: setValues(string number){
    size_t dotPos = number.find('.');

    if(dotPos != string::npos){
        integerPart = number.substr(0,dotPos);
        fractionalPart = number.substr(dotPos + 1);
    }else{
        integerPart = number;
        fractionalPart = "0";
    }
}

string ConvertFloat :: formatNumber(){
    while(!fractionalPart.empty() && fractionalPart[0] == '0'){
        fractionalPart.erase(0,1);
    }
    while(!integerPart.empty() && integerPart[0] == '0'){
        integerPart.erase(0,1);
    }
    if(integerPart.empty()){
        integerPart = "0";
    }
    int numHashes = 6 - integerPart.length();
    string hashString = (numHashes > 0) ? string(numHashes, '#'): "";

    return fractionalPart + hashString + "." + integerPart;
}