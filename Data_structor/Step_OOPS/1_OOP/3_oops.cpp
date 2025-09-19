#include<iostream>
using namespace std;

class A{
    char c;
    char d;
    int a;
    double e;
};

int main(){
    A obj;
    cout <<sizeof(obj) << "\n"; 
    return 0;
}