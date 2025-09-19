//An exception is an unexpected problem that arises during the execution of a program. 
//Our program terminates suddenly with some errors/issues. 
//Exception occurs during the running of the program.

//The try keyword represents a block of code that may throw an exception placed inside the try block. 
//It's followed by one or more catch blocks. If an exception occurs, the try block throws that exception.

//The catch statement represents a block of code that is executed when a particular exception is thrown from the try block. 
//The code to handle the exception is written inside the catch block.

//An exception in C++ can be thrown using the throw keyword. 
//When a program encounters a throw statement, it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.

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
                throw "amount should be greater than 0";
            }
        }

        void withdraw(int amount){
            if(amount>0 && amount <= balance){
                balance -= amount;
                cout << amount<< " is debited successfully\n";
            }
            else if(amount < 0){
                throw "amount should be greater than 0";
            }
            else{
                throw "Your balance is low"; 
            }
        }
};

int main(){
    Customer C1("Rohit",5000,10);
    try{
    C1.deposit(100);
    C1.withdraw(8000);
    }
    catch(const char *e){
        cout << "Exception Occured: " << e << endl;
    }
}