#include<iostream>
using namespace std;

// class runtime_error :: public exception{
    
//     public:
//         runtime_error(const string &msg): exception(msg);

// }

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
            if(amount>0)
            throw runtime_error("amount should be greater than 0");
            
            balance += amount;
            cout << "Amount is creadit sucessfully\n";
        }
        //withdraw
        void withdraw(int amount){
            if(amount>0 && amount <= balance){
                balance -= amount;
                cout << amount<< " is debited successfully\n";
            }
            else if(amount < 0){
                throw runtime_error("amount should be greater than 0");
            }
            else{
                throw runtime_error("Your balance is low"); 
            }
        }
};

int main(){
    Customer C1("Rohit",5000,10);
    try{
    C1.deposit(100);
    C1.withdraw(8000);
    }
    catch(const runtime_error &e){
        cout << "Exception Occured: " << e.what() << endl;
    }
}