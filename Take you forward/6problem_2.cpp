#include<bits/stdc++.h>
using namespace std;
/*
A school has following rule for grading system:
a. Below 25 - F
b. 25 to 45 - E
c. 45 to 49 - D
d. 50 to 59 - C
e. 60 to 79 - B
f. 80 to 100 - c
 */
int main(){                              //this is less effecient
    int marks;
    cin >> marks;

    if(marks < 25){
        cout << "F";
    }
    else if(marks >= 24 && marks <= 44){
        cout << "E";
    }
    else if(marks >= 45 && marks <= 49){
        cout << "D";
    }
    else if(marks >= 50 && marks <= 59){
        cout << "C";
    }
    else if(marks >= 60 && marks <= 79){
        cout << "B";
    }
    else{
        cout << "A";
    }
    return 0;
}