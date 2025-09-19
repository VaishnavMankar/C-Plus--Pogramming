#include<iostream>
#include<string>
using namespace std;

class Customer{
    private: 
        string name;
        int *data;
    public:
        Customer(){
            name = "4";
            cout << "constructor is " << name << endl;
        }
        Customer(string name){
            this->name = name;
            cout<<"constructor is " << name <<endl;
        }
        ~Customer(){
            cout <<"destructor is " << name << endl;
        }
};

int main(){
    Customer a1("1"), a2("2"), a3("3");
    Customer *a4 = new Customer;
    delete a4;
    return 0;
}