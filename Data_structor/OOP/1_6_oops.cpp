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
        // this->cgpa =    cgpa;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    
    //destructor
    ~Student(){
        cout << "Hi, I delete everything\n";
        delete cgpaPtr;
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
    s1.getInfo();
    return 0;
}