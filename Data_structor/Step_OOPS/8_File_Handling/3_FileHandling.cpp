#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr(5);
    cout<<"Enter the input";
    for(int i = 0; i < 5; i++){
        cin>>arr[i];
    }

    //file ko open karo
    ofstream fout;
    fout.open("zero.txt");
    fout<<"Original data\n";
    for(int i = 0; i < 5; i++){
        fout<<arr[i]<<" ";
    };
    fout<<"\nSort data\n";

    sort(arr.begin(), arr.end());
    for(int i = 0; i < 5; i++){
        fout<<arr[i]<<" ";
    };
    fout.close();
}