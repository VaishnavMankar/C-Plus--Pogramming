#include<iostream>
using namespace std;

class Teacher{
    private:
        double salary;
    public:
       string name;
       string dept;
       string subject;

       void changeDept(string newDept){
        dept = newDept;
       }

       //setter
       double setSalary(double s){
        salary = s;
       }
       //getter
       double getSalary(){
        return salary;
       }
};

int main(){
    Teacher t1;
    t1.name = "Varun";
    t1.subject = "C++";
    t1.dept = "Camputer Science";
    t1.setSalary(25000);
     
    cout << t1.getSalary() << endl;
    cout << t1.name << endl;
    return 0;
}