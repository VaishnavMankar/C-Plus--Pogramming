#include<iostream>
using namespace std;

class Human{
    private:
        string Religion, color;
    protected:
        string name;
        int age, weight;
};

class Student: public Human{
    private:
        int roll_number, fees;
    
    public:
    
    Student(string name, int age, int weight, int roll_number, int fees){
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_number = roll_number;
        this->fees = fees;

    }
    void fun(string n, int a, int w){
        name = n;
        age = a;
        weight = w;
    }

    void display()
    {
        cout << name << " age is " << age << " weight is " << weight << " roll number is "<< roll_number<< " fess is"<<fees<<endl;
    }
};

int main(){
    Student A("Rohit",12,400,13,200);
    A.display();

}