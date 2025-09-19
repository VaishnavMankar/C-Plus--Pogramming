#include<iostream>
using namespace std;

class Engineer{
    public:
        string specilization;

        Engineer(){
            cout << "Engineer consttructor\n";
        }

        void work(){
            cout << "I have specialization in "<< specilization << endl;
        }
};

class Youtuber{
    public:
        int subscribers;

        Youtuber(){
            cout << "Youtuber constructor\n";
        }

        void contentcreation(){
            cout << "I have a subscriber base of "<< subscribers << endl;
        }
};
//The swquence of call constructor depends on this whic parent call you call in the child class
class CodeTeacher: public Engineer, public Youtuber{
    public:
        string name;

        CodeTeacher(){
            cout << "CodeTeacher constructor\n";
        }
    
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
    CodeTeacher A1;
}

