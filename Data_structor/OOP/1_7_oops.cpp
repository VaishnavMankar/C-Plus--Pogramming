#include<iostream>
#include<string>
using namespace std;

class Person{
    public:
        string name;
        int age;
    
    // Person(string name, int age){
    //     this->name = name;
    //     this->age = age;
    // }
    //This are defaut default constructor and non parametrise      
    Person(){
        cout<<"Parent constructor..\n";
    }   
};

class Student : public Person{
    public:
        int rollno;

        Student(){
            cout << "Child constructor..\n";
        }

        void getInfo(){
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
            cout << "roll NO : " << rollno << endl;
        }
};

int main(){
    Student s1;
    s1.name = "Rahul Kumar";
    s1.age = 21; 
    s1.rollno = 1234;
    s1.getInfo();
    return 0;
}