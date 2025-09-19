#include"basic_24.hpp"
#include<iostream>
using namespace std;

int basic_24 :: count;

void basic_24 :: setData(void){
    cout << "Enter the id " << endl;
    cin >> id;
    count++;
}

void basic_24 :: getData(void){
    cout <<"The id of This employee is " << id <<" and this is the employee number " << count << endl;
}

void basic_24 :: getCounter(void){
    cout << "The value of count is " << count << endl;
}
