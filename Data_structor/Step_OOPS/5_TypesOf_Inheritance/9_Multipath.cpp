#include<iostream>
using namespace std;

class Human{
    public:
        string name;
        
        void display(){
            cout << "My name is "<< name<<endl;;
        }
};

class Engineer: public virtual Human{
    public:
        string specilization;

        void work(){
            cout << "I have specialization in "<< specilization << endl;
        }
};

class Youtuber: public virtual Human {
    public:
        int subscribers;

        void contentcreation(){
            cout << "I have a subscriber base of "<< subscribers << endl;
        }
};
//The swquence of call constructor depends on this whic parent call you call in the child class
class CodeTeacher: public Engineer, public Youtuber{
    public:
        int salary;

        CodeTeacher(){

        }
 
    
        CodeTeacher(string name, string specilization, int subscribers,int salary){
            this->name = name;
            this->specilization = specilization;
            this->subscribers = subscribers;
            this->salary = salary;
        } 
        
        void showcase(){
            cout << "My name is "<< name << endl;
            work();
            contentcreation();
        }
};

int main(){
    CodeTeacher A1("Rohit","CS",49000,99);
    A1.display();
}

