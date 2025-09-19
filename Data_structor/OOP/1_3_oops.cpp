#include<iostream>
using namespace std;

class Teacher{
    private:
        double salary;
    public:
    //non-parameterized
    //    Teacher(){ //This is our constuctor 
    //     //cout<<"Hi, I am const ructor\n";
    //     dept = "Computer Science"; //This will be our default value for all the object
    //    }Constructor should be always declared in public

       string name;
       string dept;
       string subject;
       //parameterize constructor
       Teacher(string n, string d, string s, double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
       }
       
       void getInfo(){
        cout << "name: " << name << endl;
        cout << "subject : " << subject << endl;
        cout << "salary: " << salary << endl;
       }
};

int main(){
    Teacher t1("Varun","CS","Couputer Science",15000);
    t1.getInfo();
    return 0;
}