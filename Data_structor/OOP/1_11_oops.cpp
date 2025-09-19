//Hierarchial Inheritance
#include<iostream>
#include<string>
using namespace std;

class Person{
    public:
        string name;
        int age;
};

class Student  : public Person{
    public: 
        int roll;
};
class Teacher : public Person {
    public:
        string subject;  
        double salary;
};

class TA : public Student, public Teacher{

};

int main(){
    // TA t1;
    // t1.name = "tony stark";
    // t1.subject = "Conputer Science";

    // cout << t1.name << endl;
    // cout << t1.subject << endl;
    return 0;
}