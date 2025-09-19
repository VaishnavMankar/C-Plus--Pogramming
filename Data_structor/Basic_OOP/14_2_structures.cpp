#include<iostream>
using namespace std;

typedef struct employee
{
    int eID;
    char favChar;
    float salary;
}ep;

int main(){
    ep harry;
    ep shubham;
    ep rohan;
    
    harry.eID = 1;
    harry.favChar = 'c';
    harry.salary = 120000;

    cout<<"The value is "<<harry.eID<<endl;
    cout<<"The value is "<<harry.favChar<<endl;
    cout<<"The value is "<<harry.salary<<endl;
    return 0;
}
//this is how you can create data  types in c++
// there is another method to write this we can replace struch with ep

