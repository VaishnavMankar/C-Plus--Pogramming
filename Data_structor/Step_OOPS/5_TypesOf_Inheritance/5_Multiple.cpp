#include<iostream>
using namespace std;

class Engineer{
    public:
        string specilization;

        void work(){
            cout << "I have specialization in "<< specilization << endl;
        }
};

class Youtuber{
    public:
        int subscribers;

        void contentcreation(){
            cout << "I have a subscriber base of "<< subscribers << endl;
        }
};

class CodeTeacher: public Engineer, public Youtuber{
    public:
        string name;
    
        CodeTeacher(string name, string specilization, int subscribers){
            this->name = name;
            this->specilization = specilization;
            this->subscribers = subscribers;
        }
        
        void showcase(){
            cout << "My name is "<< name << endl;
            work();
            contentcreation();
        }
};

int main(){
    CodeTeacher A1("Rohit","CSE",49000);
    A1.showcase();
}

