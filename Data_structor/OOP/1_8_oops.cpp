#include<iostream>
#include<string>
using namespace std;

class Person{
    public:
        string name;
        int age;
    
    //parametrise constructor
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    //This are defaut default constructor and non parametrise      
    // Person(){
    //     cout<<"Parent constructor..\n";
    // }   
};

class Student : public Person{
    public:
        int rollno;
        
        //paremetrise constructor needs to get called deferently
        Student(string name, int age,int rollno) : Person(name, age){
            this->rollno = rollno;
            cout << "Child constructor..\n";
        }

        void getInfo(){
            cout << "name : " << name << endl;
            cout << "age : " << age << endl;
            cout << "roll NO : " << rollno << endl;
        }
};

int main(){
    Student s1("Rahul Kumar",21,1234);
    return 0;
}