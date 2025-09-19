#include"basic_23.hpp"
#include<iostream>
using namespace std;

void basic_23 :: setPrice(void){
    cout << "Enter Id of your item no " << counter + 1 << endl;
    cin >> itemID[counter];
    cout << "Enter Price of your item" << endl;
    cin >> itemPrint[counter];
    counter ++;
}

void basic_23 :: displayPrice(void){
    for(int i = 1;i < counter; i++){
        cout << "The price of item ID " << itemID[i] << " is " << itemPrint[i] << endl;
    }
}