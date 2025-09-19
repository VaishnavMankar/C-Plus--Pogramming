#include<iostream>
using namespace std;

int main(){
    int marks[4] = {23,45,56,89};
    //pointer in array
    int* p = marks;
    // cout << "The value of marks[0] is: " << *p << endl; 
    // cout << "The value of marks[0] is: " << *(p+1) << endl;
    // cout << "The value of marks[0] is: " << *(p+2) << endl;
    // cout << "The value of marks[0] is: " << *(p+3) << endl;
    cout << *(p++)<< endl;
    cout<< *(++p) << endl;
    return 0;
}
