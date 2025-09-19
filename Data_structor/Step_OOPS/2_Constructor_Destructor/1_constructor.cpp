#include<iostream>
using namespace std;

class Customer{
    private:
        string name;
        int account_number;
        int balance;
    public:
        //Default Constructor
        // Customer(){
        //     name = "Rohit";
        //     account_number = 5;
        //     balance = 100;
        // }
        // //parameterized Connstructor
        // Customer(string name,int account_number, int balance){
        //     this->name = name;
        //     this->account_number = account_number;
        //     this->balance = balance;
        // }

        Customer(string a, int b){
            name = a;
            account_number = b;
            balance = 50;
        }

        void display(){
            cout<<name<<" "<<account_number<<" "<<balance<<endl;
        }
        
        //Inline Constructor
        inline Customer(string a,int b, int c): name(a), account_number(b), balance(c){
            
        }
};

int main(){
    // Customer A1;
    // A1.display();
    Customer A2("Varun",23,100);
    A2.display();
    Customer A3("Karan",24);
    A3.display();
    return 0;
}