// N Factorial
// N = 5 : 5x4x3x2x1
#include<iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1;
    }
     return n * factorial(n-1);
}

int main(){
    cout << factorial(5) << endl;
    return 0;   
}