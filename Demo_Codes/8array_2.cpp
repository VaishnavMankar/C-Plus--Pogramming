#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[3][5];

    arr[1][3] = 78;
    cout << arr[1][2];  // It will give us a garbage Value
    return 0;
}