//Class using static data member
//Static member function --> This function helps to axcess the static function which is declare as private member
#include<iostream>
using namespace std;

class Customer{
    private:
        string name;
        int accoutn_number, balance;
        static int total_count;
        static int total_balance; 
    
    public:
        //static int total_count;
        //If your static function is public you can axcess it from main function
        Customer(string name, int account_number, int balance){
            this->name = name;
            this->accoutn_number = account_number;
            this->balance = balance;
            total_count++;
            total_balance += balance;
        } 
        
        static void acceStatic(){
            cout<<"Total nummber of Customer: "<< total_count<<endl;
            cout<<"Total Balance: "<<total_balance<<endl;
        }
        
        void deposit(int amount){
            if(amount > 0){
                balance += amount;
                total_balance += amount;
            }
        }

        void withdraw(int amount){
            if(amount <= balance && amount > 0){
                balance -= amount;
                total_balance -= amount;
            }
        }

        void display(){
            cout <<name << " "<<accoutn_number<<" "<<balance<<" "<<total_count<<endl;
        }
        
        void display_total(){
            cout<<total_count<<endl;
        }
};
int Customer::total_count=0;
int Customer::total_balance=0;

int main(){
    Customer A1("Rohit",1,1000);
    //A1.display();
    Customer A2("Mohit",2,1600);
    A2.display_total();
    //Customer::total_count = 5;
    //This is how you can axcess your static functio if it is locakated in public;
    A1.deposit(800);
    Customer::acceStatic();
    A2.withdraw(500);
    Customer::acceStatic();
    return 0;
}