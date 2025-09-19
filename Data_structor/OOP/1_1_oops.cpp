#include<iostream>
using namespace std;

class Teacher{
    public:
       string name;
       string dept;
       string subject;
       double salary;

       void changeDept(string newDept){
        dept = newDept;
       }
};

int main(){
    Teacher t1;
    t1.name = "Varun";
    t1.subject = "C++";
    t1.dept = "Camputer Science";
    t1.salary = 25000;
    
    cout << t1.name << endl;
    return 0;
}