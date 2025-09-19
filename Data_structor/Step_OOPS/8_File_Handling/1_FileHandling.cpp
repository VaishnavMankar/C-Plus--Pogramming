#include<iostream>
#include<fstream>
using namespace std;
//this code is to create and write from the file 
int main(){
    //file ko open karna
    ofstream fout;
    fout.open("zoom.txt");//create kar dega aur fr open kar dega
    //Write kar sakta hu
    fout<<"Hello India!";

    fout.close();//To release the resources   
    return 0;
}