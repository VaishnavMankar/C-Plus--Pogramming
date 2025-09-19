#include "ConvertToFractional.hpp"
#include<iostream>
#include<string>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void ConvertFractional :: convert(const string& number){
        size_t dotPos = number.find('.');

    if(dotPos == string::npos){
        cout<< number << " + 0/1"<<endl;
        return;
    }

    string intpart = number.substr(0, dotPos);
    string fraction = number.substr(dotPos + 1);

    int numerator = stoi(fraction);
    int denominator = 1;

    for(int i = 0; i < fraction.length();i++){
        denominator *= 10;
    }

    int commonDivisor = gcd(numerator, denominator);

    numerator /= commonDivisor;
    denominator /= commonDivisor;

    if(intpart == "0"){
        cout << numerator << " / "<< denominator << endl;
    }else{
        cout<<intpart << " + " << numerator << " / " << denominator << endl;
    }
}
