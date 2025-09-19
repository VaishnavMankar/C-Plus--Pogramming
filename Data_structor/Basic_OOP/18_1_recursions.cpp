#include<iostream>
using namespace std;

//writing function for finding factorial
int factorial(int n){
    if(n <= 1){
        return 1;
    }
    return n * factorial(n-1);
}

//Writing function for fibonachi serirs;
int fib(int n){
    if(n < 2){
        return 1;
    }
    return fib(n-2) + fib(n-1);
} 

int main(){
    int a;
    cout << "Enter a number" << endl;
    cin >> a;
    cout << "The factorial of a is " << factorial(a) << endl;
    cout << "The term is fibonachi sequence at position " << a << " is " <<  fib(a) <<end   l; 
    return 0;

}