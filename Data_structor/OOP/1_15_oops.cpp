//Run time polymorphism using function overloding
#include<iostream>
#include<string>
using namespace std;

class Parent{
    public:
        void getInfo() {
            cout << "Parent class\n";
        }

        virtual void hello(){
            cout << "Hello from parent\n";
        }
};

class Child : public Parent{
    public:
        void getInfo(){
            cout << "child class\n";
        }

        void hello(){
            cout << "Hello from child\n";
        }
};

int main(){
//     Parent p1;
//     p1.getInfo();

    Child c1;
    c1.hello();
    return 0;
}