#include<iostream>
using namespace std;

int main(){
    try{
    int *p = new int[100000000];
    cout <<"Momory allocation is sucessfully\n";
    delete []p;
    }
    catch(const exception &e){
        cout << "Exception occurance due to line 9: " << e.what()<<endl;
    }
}