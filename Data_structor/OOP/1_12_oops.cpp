#include<iostream>
#include<string>
using namespace std;
//Polymorphism 
class Student{
    public:
        string name;

        Student(){
            cout << "non_parameterized\n";
        }

        Student(string name){
            this->name = name;
            cout<<"parameterized\n";
        }
};

int main(){
    Student s1;
    s1.name = "Varun";
    cout <<"Non-Parameterized constructor: "<< s1.name << endl;

    Student s2("Rahul");
    cout << "Parameterize constructor\n";
    return 0;
}