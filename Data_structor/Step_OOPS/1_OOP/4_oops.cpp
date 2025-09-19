#include<iostream>
using namespace std;

class Student{
    public:
        string name;
        int age, roll_no;
        string grade;
};

int main(){
    Student *s = new Student;
    (*s).name = "Rohit";
    (*s).age = 10;
    (*s).roll_no = 21;
    (*s).grade = "A";
    //we use -> this notation to axcess the diminically allocakated variable
    cout << s->name<<endl;
}