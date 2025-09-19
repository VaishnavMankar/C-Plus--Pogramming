#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    
    vec.push_back(0);
    vec.push_back(1);
    //every time you push an element in an vector the capacity will get double
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    
    vec.push_back(2);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    vec.push_back(3);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;

    vec.push_back(4);
    cout << vec.size() << endl;
    cout << vec.capacity() << endl;
    
    return 0;
}