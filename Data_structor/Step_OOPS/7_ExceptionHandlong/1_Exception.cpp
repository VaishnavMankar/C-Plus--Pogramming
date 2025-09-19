#include<iostream>
using namespace std;
class Customer{
    public:
        string name;
        int balance, account_number;
    public: 
        Customer(string name, int balance,int account_number)
        {
            this->name = name;
            this->balance = balance;
            this->account_number = account_number;
        }
        //deposit
        void deposit(int amount){
            if(amount>0){
                balance += amount;
                cout << "Amount is creadit sucessfully\n";
            }
            else{
                cout << "amount should be greater than 0\n";
            }
        }

        void withdraw(int amount){
            if(amount>0 && amount <= balance){
                balance -= amount;
                cout << amount<< " is debited successfully\n";
            }
            else if(amount < 0){
                cout << "amount should be greater than 0\n";
            }
            else{
                cout << "Your balance is low\n"; 
            }
        }
};

int main(){
    Customer C1("Rohit",5000,10);
    C1.deposit(100);
    C1.withdraw(8000);
}