#include "ConvertToFractional.hpp"
#include<iostream>
#include<sstream>
using namespace std;

int main(){
    float num;
    cout<<"Enter a number: \n";
    cin>>num;
    if(cin.fail()){
        cerr << "Error: ";
        return 1;
    }

    ostringstream oss;
    oss << num;
    string numberstr = oss.str();


    ConvertFractional N1;

    N1.convert(numberstr);
    return 0;
}