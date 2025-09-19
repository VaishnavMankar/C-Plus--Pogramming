#include<iostream>
#include"GlcLcm.hpp"
#include<exception>
using namespace std;

int main(){
    int a ,b;
    cout << "Enter a and b\n";
    cin >> a >> b;

    try{
        GcdLcm num(a, b);
        cout << num.getGcd()<<endl;
        cout << num.getLcm()<<endl;
    }
    catch(const char* msg){
        cout << "Exception occur: " << msg << endl;
    }
    return 0;
}