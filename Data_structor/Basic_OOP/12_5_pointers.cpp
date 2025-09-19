//pointer subtractio and relational  operator
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5};

    int* ptr1;//100
    int* ptr2 = ptr1 + 2;

    cout << ptr2 - ptr1 << endl;

    cout << ptr1 << endl;
    cout << ptr2 << endl;

    cout << (ptr1 != ptr2) << endl;
    cout << (ptr1 > ptr2) << endl;
    return 0;
}