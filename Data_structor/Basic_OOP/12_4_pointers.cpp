//Pointer Array
#include<iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int a = 10;
    int* ptr = &a;
    
    cout << ptr << endl;
    ptr--;
    cout << ptr << endl;

    ptr = ptr + 2; // 2int = 8 bit
    cout << ptr << endl;
    cout << *arr << endl;
    cout << *arr+1<<endl;
    cout << *(arr+2)<<endl;
    return 0;
}