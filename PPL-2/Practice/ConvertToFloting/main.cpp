#include<iostream>
#include<string>
#include"FloatConverter.hpp"
using namespace std;

int main(){
    string number;
    cout << "Enter a positive real number: \n";
    cin >> number;

    ConvertFloat num;
    num.setValues(number);
    cout << num.formatNumber() << endl;
    return 0; 
}