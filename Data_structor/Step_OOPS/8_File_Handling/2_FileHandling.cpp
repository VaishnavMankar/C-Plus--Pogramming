#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream fin;
    //file ko open karo
    fin.open("zoom.txt");
    //fr read karo
    char c;
    c = fin.get();
    while(!fin.eof()){
        cout<<c;
        c = fin.get();
    }
    fin.close();
}