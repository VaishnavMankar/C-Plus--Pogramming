//Class using static data member
//Static member function --> This function helps to axcess the static function which is declare as private member
#include<iostream>
using namespace std;

class Customer{
    private:
        string name;
        int accoutn_number, balance,age;

    public:
        //static int total_count;
        //If your static function is public you can axcess it from main function
        Customer(string name, int account_number, int balance,int age){
            this->name = name;
            this->accoutn_number = account_number;
            this->balance = balance;
            this->age = age;
        } 
        
        void deposit(int amount){
            if(amount > 0){
                balance += amount;
            }
            else{
                cout<<"Invalid amount\n";
            }
        }
        
        void updateage(int age){
            if(age>0 && age < 100){
                this->age = age;
            }else{
                cout << "Invalid age\n";
            }
        }

        void withdraw(int amount){
            if(amount <= balance && amount > 0){
                balance -= amount;
            }
        }

        void display(){
            cout <<name << " "<<accoutn_number<<" "<<balance <<" "<< age << endl;
        }
};

int main(){
    Customer A1("Rohit",1,1000,3);
    Customer A2("Mohit",2,1600,4);
    Customer A3("Varun",3,2000,8);
    A1.updateage(10);
    A1.display();
    return 0;
}