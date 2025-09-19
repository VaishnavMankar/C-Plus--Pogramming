#include<iostream>
using namespace std;

class Teacher{
    private:
        double salary;
    public:
       string name;
       string dept;
       string subject;
       //parameterize constructor
       Teacher(string name, string dept, string subject, double salary){
        this -> name = name;
        this -> dept = dept;
        this -> subject = subject;
        this -> salary = salary;
       }
       //Copy constructor
       Teacher(Teacher &orjOb){
        cout << "i am custom copy constructor...\n";
        this->name = orjOb.name;
        this->dept = orjOb.dept;
        this->salary = orjOb.salary;

       }

       //this function is used wh en we have same vairiable name as our object and function variable 
       //the name which is present at the left is our object name 
       //the name present at the right is our function parameter 
       void getInfo(){
        cout << "name: " << name << endl;
        cout << "subject : " << subject << endl;
        cout << "salary: " << salary << endl;
       }
};

int main(){
    Teacher t1("Varun","CS","Couputer Science",15000);
    t1.getInfo();
    
    Teacher t2(t1);//custome copy constructore will get called
    t2.getInfo();
    return 0;
}