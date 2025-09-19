#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    //*************Constants*************//
    // int a = 20;
    // cout << "The value of a was" << a << endl;
    // a = 45;
    // cout << "The value of a was" << a << endl;

    // Afterr using constants
    const int a = 29;
    // you cannot change the value of a 
    cout << "The value of a was" << a << endl; 

    //Manipulators in C++ 
    //Using setw function 
    //helps to print the result in right space pattern
    //can be only use after including iomanip library  
    int b=3, c=78, d=1234;
    cout << "This vaues of b without setw is: " << b << endl;
    cout <<  "This vaues of c without setw is: " << c << endl;
    cout << "This vaues of d without setw is: " << d << endl;

    cout << "This value of b is: " << setw(4)<< b << endl;
    cout << "This value of c is: " << setw(4)<< c << endl;
    cout << "This value of d is: " << setw(4)<< d << endl;
    return 0;
}