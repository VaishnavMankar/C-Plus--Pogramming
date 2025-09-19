#include<bits/stdc++.h>
using namespace std;
//Write a program that takes an input of age
//and print if you are adult or not 
int main(){
    int age;
    cin >> age;
    if (age <= 18){
        cout << "You ar not an adult";
    } 
    else if(age >= 19 && age <= 50) {
        cout << "You are an adult";
    }
    else{
        cout << "you are old";
    }
    return 0;
}