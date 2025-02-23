#include<iostream>
using namespace std;

int main(){
    int size = 5;
    int marks[size];

    for(int i = 0; i < size; i++){
        cin >> marks[i];
    }
    for(int j = 0; j < size; j++){
        cout << marks[j] << endl;
    }
    return 0;
}