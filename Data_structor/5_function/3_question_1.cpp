//Q1. Calculate 
#include<iostream>
using namespace std;

int sumN(int n){
    int sum = 0;
    for (int i = 1; i <= n;i++){
        sum += i;
    }
    return sum;
}
int main(){
    int n;
    cout << "enter a number";
    cin >> n;
    cout << sumN(n) << endl;
    return 0;
}