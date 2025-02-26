//find smallest & largest in an array and print the index
#include<iostream>
using namespace std;

int main(){
    int nums[] = {5,15,22,1,-15,24};
    int size = 6;
    int min = 0;
    int max = 0;
    int smallest = INT8_MAX;
    int largest = INT8_MIN;
    
    for(int i = 0; i < size; i++){
        if(nums[i] < smallest){
            smallest = nums[i];
            min = i;
        }
        if(nums[i] > largest){
            largest = nums[i]; 
            max = i;
        }
    }

    cout << "minimum = " << min << endl;
    cout << "maximum = " << max << endl;

    return 0;
}