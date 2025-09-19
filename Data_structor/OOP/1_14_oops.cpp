//Run time polymorphism using function overloding
#include<iostream>
#include<string>
using namespace std;

class Parent{
    public:
        void getInfo(){
            cout << "Parent class\n";
        }
};

class Child : public Parent{
    void getInfo(){
        cout << "child class";
    }
};

int main(){
    Parent p1;
    p1.getInfo();
    return 0;
}