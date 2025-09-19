//copy constructor
#include<iostream>
using namespace std;

class Customer{
    private:
        string name;
        int account_number;
        int balance;
    public:
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
        //coppy constructor 
        Customer(Customer &B){
            name = B.name;
            account_number = B.account_number;
            balance = B.balance;
        }
};

int main(){
    // Customer A1;
    // A1.display();
    Customer A2("Varun",23,100);
    A2.display();
    Customer A3("Karan",24);
    A3.display();
    Customer A4(A3);
    A4.display();
    return 0;
}  