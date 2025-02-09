//Sum of all Odd numbers from 1 to N
#include<iostream>
using namespace std;

int main(){
    int n= 10;
    int oddSum = 0;

    for(int i = 1; i <= n; i++){
        if( i%2 != 0){
            oddSum += i;
        }
    }
    cout << "sum of odd numbers fro  1 to n: " << oddSum << endl;   
    return 0;
}
