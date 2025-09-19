#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a = 5;
    int* b = &a;
    int** c = &b;

    cout <<"Address of a: "<<  b << endl;
    cout <<"Address of a: "<< *c << endl;
    cout <<"Address of a: "<< &a << endl;
   
    cout <<"Address of b: "<< &b << endl;
    cout <<"Address of b: "<< c << endl;
    return 0;
}