#include<iostream>
using namespace std;
//Function overloding 
class Area{
    public:
    
    int calculateArea(int r){
        return 3.14*r*r;
    }

    int calculateArea(int l,int b){
        return l*b;
    }
};   

int main(){
    Area A1,A2;
    cout << A1.calculateArea(4) << endl;//this decision has been made in compile time
    cout << A2.calculateArea(3,4) << endl;
    return 0;
}