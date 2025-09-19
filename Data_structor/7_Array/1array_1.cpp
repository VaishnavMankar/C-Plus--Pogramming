#include<iostream>
using namespace std;

int main(){
    int marks[5] ={99,100,54,36,88};
    cout << marks[0] << endl;
    marks[0] = 101;
    cout << marks[0] << endl;
    cout << sizeof(marks) << endl; // sizeof() tells the total amount of memory it takes to store the values
    cout << sizeof(marks)/sizeof(int) << endl;//this tels ous the number of element of element in an array 

    double print[] = {98.88,105.67,30.00};
    
    int roll_no[10] = {1,2,3,4,5};
    return 0;
}