//sum of number from 1 to n
#include<iostream>
using namespace std;

int main(){
    int n = 5;
    int sum = 0;

    for(int i = 0; i <= n; i++){
        sum += i;
    }

    cout << "sum = " << sum << endl;
    return 0;
}