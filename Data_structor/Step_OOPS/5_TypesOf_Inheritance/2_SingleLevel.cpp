#include<iostream>
using namespace std;

class Human
{
    protected:
        string name;
        int age;
    
    public:

    Human(){
        cout << "Hello human\n";
    }
    
    ~Human(){
        cout << "Hello human destrictur\n";
    }

    void work(){
        cout <<"I am working\n";
    }
};

class Student: public Human{
    int roll_number, fees;

    public: 
    // Student(string name,int age, int roll_number, int fees){
    //     this->name = name;
    //     this->age = age;
    //     this->roll_number = roll_number;
    //     this->fees = fees;
    // }
    Student(){
        cout << "Hello Student\n";
    }
    
    ~Student(){
        cout << "Hello Student districtur\n";
    }
};

int main(){
    //Student A1("Rohit", 26, 32, 99);
    Student A1;
    A1.work();//Because this function was public in its parent class

}