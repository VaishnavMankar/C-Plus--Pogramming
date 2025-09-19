#include<iostream>
using namespace std;

int sum(int a, int b){
    int s = a + b;
    return s;
}
int minOfTwo(int a, int b){
    return(a > b)? a : b;
}

int main(){
    cout << sum(5,5) << endl;

    cout << minOfTwo(3,4) << endl;

    return 0;
}

// int minTo(int a, int b){
//     if(a > b){
//         return a;
//     }
//     else{
//         return b;
//     }
// }