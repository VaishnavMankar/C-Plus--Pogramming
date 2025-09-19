#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec (5,0);
                                //the data type of vector and varialble in for loop should be same
    for(int i : vec){          //this is for each loop use to print vector
        cout << i << endl;
    }
    return 0;
}