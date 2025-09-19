#include<iostream>
using namespace std;

int c = 45;
//This c is our global variable
int main(){
    int a, b, c;
    cout << "Enter the value of a: " << endl;
    cin >> a;
    cout << "Enter the value of b: " << endl;
    cin >> b;
    c = a + b;
    cout << "The sum is " << c << endl;
    cout << "The global c is "<< ::c << endl;
    // :: this is scope resolution operator. This helps to call the global variable  

    //****************** Rreference Variables**************************
    // means nothing bu assigning different name to the original Variable;
    float x = 455;
    float& y = x;
    cout << x << endl;
    cout << y << endl;

    //*****************Type casting*******************
    //Means changind the data type of he original variable;
    int d = 33;
    float e = 5343.4333;
    cout << "The value of d after type castind is  " << float(d) << endl;
    cout << "The value of d after type castind is  " << (float)d << endl;
    
    cout << "The value of e after type castind is  " << int(e) << endl;
    cout << "The value of e after type castind is  " << (int)e << endl;

    
    return 0; 
}