//Check if a number id prime or not.
#include<iostream>
using namespace std;

int main(){
    int n = 7;
    bool isPrime = true;

    for(int i = 2; i < n; i++){
        if(n%i == 0){//non primeif
            isPrime = false;
            break;
        }
    }
    if(isPrime == true){
        cout << "Prime number\n";
    }
    else{
        cout << "not a Prime number\n";
    }
    return 0;
}