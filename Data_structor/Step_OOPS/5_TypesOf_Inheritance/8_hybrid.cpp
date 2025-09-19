//Hybrid Inheritance
#include<iostream>
using namespace std;
//student
//boy
//girl
//male
//female
class Male{
    public:
        void MalePrint(){
            cout << "I am Male\n";
        }
};

class Female{
    public:
        void FemalePrint(){
            cout << "I am FeMale\n";
        }
};

class Student
{
    public:
        void print(){
            cout << "I am student\n";
        }
};

class Boy : public Student, public Male{
    public:
        void Boyprint(){
            cout <<"I am boy\n";
        }
};
class Girl: public Student, public Female{
    public:
        void Girlprint(){
            cout << "I am a girl\n";
        }
};

int main(){
     Girl G1;
     G1.Girlprint();
}