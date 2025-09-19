#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    // double cgpa;
    double *cgpaPtr;

    // constructor Shallo copy constructor
    Student(string name, double cgpa)
    {
        this->name = name;
        // this->cgpa = cgpa;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    //deep copy
    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main()
{
    Student s1("Varun", 8.9);
    Student s2(s1);

    s1.getInfo();
    *s2.cgpaPtr = 9.2;
    s2.name = "Neha";
    s1.getInfo();
    s2.getInfo();
    return 0;
}