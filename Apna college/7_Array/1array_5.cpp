#include<iostream>
using namespace std;

void changeArray(int arr[], int size){
     cout << "in function\n";
    for(int i = 0; i < size; i++){ //arrays are alwas pass by referance
        arr[i]  = 2*arr[i];        // all the changes are done in original array no copies are created
    }
}
int main(){
    int arr[] = {1,2,3};
    changeArray(arr,3);
    cout << "in main\n";
    for(int i = 0; i < 3; i++){
        cout << arr[i] << " ";
    }
}