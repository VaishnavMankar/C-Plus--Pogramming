#include<iostream>
using namespace std;
//There are two types of Header File
//1. System header file: It comes with the compiler
//2. User defined header files: It is written by programmer
//User Define headder file are like what we did in our Numerical assignment
//defining an .hpp fiel and calling it in a main file

int main(){
    int a = 4, b = 3;
    cout<<"Operators in c++" << endl;
    cout<<"Following are the types of operators in C++" << endl;
    cout << "This value of a + b is " << a+b << endl;
    cout << "This value of a - b is " << a-b<< endl;
    cout << "This value of a * b is " << a*b << endl;
    cout << "This value of a / b is " << a/b << endl;
    cout << "This value of a % b is " << a%b << endl;
    cout << "This value of a ++ is " << a++ << endl;
    cout << "This value of a -- is " << a-- << endl;
    cout << "This value of ++a is " << ++a << endl;
    cout << "This value of --a is " << --a << endl;
}