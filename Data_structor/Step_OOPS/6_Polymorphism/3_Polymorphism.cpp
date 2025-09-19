#include<iostream>
using namespace std;

class Animal{
    public:
        virtual void speak(){
            cout << "Huhu\n";
        }
};

class Dog: public Animal{
    public:
        void speak(){
            cout << "Bark\n";
        }
};

int main(){
    Animal *p;
    p = new Dog();
    p->speak();
}