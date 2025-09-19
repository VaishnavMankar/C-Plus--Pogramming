#include<iostream>
using namespace std;

inline int product(int a, int b){
    return a*b; 
}
//default afgument
//Some rooles:you cannot write directoly the default argument at first
//write the compulsery argument at first and then write the default argument 
float moneyReceived(int currentMoney, float factor = 1.04){
    return currentMoney * factor;
}

int main(){
    int a,b;
    cout<<"Enter the value of a and b";
    cin>>a>>b;
    cout<<"The product of a and b is "<<product(a,b);

    int money = 10000;
    cout<<"if you have "<< money << "Rs inn your accoutn, you will recive " << moneyReceived(money) <<" Rs after 1 year";
    cout<<"For VIP : if you have "<< money << "Rs inn your accoutn, you will recive " << moneyReceived(money,1.5) <<" Rs after 1 year";
    return 0;
}
//when not to use inline function
//when you are writing the code using recursion and when you are using static variable
 