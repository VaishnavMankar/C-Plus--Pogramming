#include<iostream>
using namespace std;

int main(){
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if(age >= 18){
        cout << "you can vote\n";
    }
    else{
        cout << "You cant vote\n"; 
    }
    return 0;
}