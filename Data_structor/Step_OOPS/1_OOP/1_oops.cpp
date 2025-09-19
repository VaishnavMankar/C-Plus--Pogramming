#include<iostream>
#include<string>
using namespace std;
//public data-types 
class Student{
    public:
        string name;
        int age,roll_num;
        string grade;
};

int main(){
    Student s1;
    s1.name = "Rohit";
    s1.age = 10;
    s1.roll_num = 100;  
    s1.grade = "A";

    Student s2;
    s2.name = "Mohit";
    s2.age = 11;
    s2.roll_num = 101;
    s2.grade = "A+";
    cout << s2.name << "\n";
    return 0;
}