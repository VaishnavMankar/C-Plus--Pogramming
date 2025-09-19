#include<iostream>
using namespace std;

int main(){
    //What is a pointer? ---> data type which holds the address of other data type
    int a = 3;
    int *b = &a;
    // & ---> (Address) of operators
    cout << "The address of a is "<< &a << endl;
    cout << "The address if a is "<< b << endl;
    cout << &b << endl;
    
    //Now you know how to print the location of the address
    //how to print thee value which is present at that location
    // * ---> using dereference operator
    cout << "The value at address b is " << *b << endl;

    int** c = &b;
    //Pointer to pointer 
    cout << "The address of b is "<< &b << endl;
    cout << "The address of b is "<< c << endl;
    cout << "The value of address c is "<< *c << endl;
    //cout << &c << endl;
    cout << "The value at address value_at(value_at(c)) is "<< **c << endl;
    
    int &d = a;
    int &e = a;
    cout << "d = " << &d << endl << "e = " << &e << endl;
}