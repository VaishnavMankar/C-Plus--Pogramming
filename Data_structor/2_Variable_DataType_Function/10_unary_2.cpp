#include<iostream>
using namespace std;

int main(){
    int a = 10;
    
    int b = ++a; // update :: kaam
    cout << "b = " << b << endl;//11
    cout << "a = " << a << endl;//11
    return 0;
}