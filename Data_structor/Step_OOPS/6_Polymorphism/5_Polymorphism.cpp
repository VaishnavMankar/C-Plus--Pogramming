#include<iostream>
#include<vector>
using namespace std;

class Animal{
    public:
    //pure virtual function
        virtual void speak()=0;//Abstract class
};

class Dog: public Animal{
    public:
        void speak(){
            cout << "Bark\n";
        }
};

class Cat: public Animal{
    public:
        void speak(){
            cout <<"Meow\n";
        }
};

int main(){
    Animal *p;
    vector<Animal*>animal;
    animal.push_back(new Dog());
    animal.push_back(new Cat());
    animal.push_back(new Dog());
    animal.push_back(new Cat());

    for(int i = 0; i < animal.size(); i++){
        p = animal[i];
        p->speak();
    }
}