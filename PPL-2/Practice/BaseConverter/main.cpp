#include<iostream>
#include "BaseConverter.hpp"
using namespace std;

int main(){
    int number, base;
    cout<<"Enter the number: \n";
    cin>>number;
    cout<<"Enter the base: \n";
    cin>>base;
    
    if(number < 0){
        cout << "Invalid input!";
    }

    BaseConverter N1;
    N1.setValues(number,base);
    string result =  N1.converter();
    cout << result << endl;
    return 0;
}