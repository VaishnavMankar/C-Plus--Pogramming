#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;

    cout<< "size = " << vec.size() << endl;
    vec.push_back(25);    //push_back will add the value in the vector at last index
    vec.push_back(35);
    vec.push_back(45);
    cout<< "after push back size = " << vec.size() << endl;
 
    vec.pop_back();  //pop_banck will delete the element at the last index
    
    for(int i : vec){           //For each loop
        cout << i << endl;
    }

    cout << "first value of vector: " << vec.front() << endl;//.front will print the first value of the vector

    cout << "last value of vector: " << vec.back() << endl; //.back will print the last value of the vector

    cout << "Value at position: " << vec[1] << endl;
    //another method of printing a value at perticular position 
    cout<< "value at position: " << vec.at(0) << endl;
    return 0;
}