#include<iostream>
#include<string>
using namespace std;
//private data-types 
class Student{
    private:
        string name;
        int age,roll_num;
        string grade;
    public:
    //function getter and setter
        void setName(string n){
            if(n.size() == 0){
                cout << "invalid name: ";
                return;
            }
            name = n;
        }
        void setAge(int a){
            if(a < 0 || a > 100){
                cout <<"Invalid age: ";
                return;
            }
            age = a;
        }
        void setRoll(int r){
            roll_num = r;
        }
        void setGrade(string g){
            grade = g;
        }
        void getName(){
            cout << name << endl;
        }
        int rollNumber(){
            return roll_num;
        }
        string get_grades(int pin){
            if(pin = 123)
            return grade;

            return "";
        }
};

int main(){
    Student s1;
    s1.setName("");
    s1.setAge(10);
    s1.setRoll(100);  
    s1.setGrade("A");
    s1.getName();
    cout << s1.rollNumber() << endl;
    cout << s1.get_grades(123) << endl;
    return 0;
}