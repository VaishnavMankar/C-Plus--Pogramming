//sum of even from 1 to n
#include<iostream>
using namespace std;

int main(){
    int n = 10;
    int evenSum = 0;
    int i = 1;
    while(i <= n){
        if(i%2 == 0){
            evenSum += i;
        }
        i++;
    }
    cout<< "sum of even number from 1 to n: " << evenSum << endl;
    return 0;
}