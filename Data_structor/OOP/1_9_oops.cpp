#include <iostream>
#include<string>
using namespace std;
//Multi-level Inheritance
class Person{
    public:
        string name;
        int age;
};
class Student : public Person{
    public:
        int roll;
};
class GradStudent : public Student{
    public:
        string researchArea;
};

int main(){
    GradStudent s1;
    s1.name = "Varun";
    s1.roll = 234;
    s1.researchArea = "Computer science";

    cout << s1.name << endl;
    cout << s1.roll << endl;
    cout << s1.researchArea << endl;
    return 0;
}