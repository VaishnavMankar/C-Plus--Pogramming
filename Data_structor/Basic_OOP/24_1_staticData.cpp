#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        static int count;//default value is zero
    public:
        void setData(void){
            cout << "Enter the id "<<endl;
            cin>>id;
            count++;
        }
        
        void getData(void){
            cout<<"The id of this employee is "<<id<< " and this is employee number"<<count<<endl;
        }
        //to get the axcess of static variable you need to  declare a static function
        static void getCount(void){
            cout<<"The value of count is "<< count << endl;
        } 

};
//Count is a static data member of class employee
int Employee :: count; //default value is 0;
//int Employee :: count=1000;
//we can also assign value of 1000 to count so the value will start incrementing form 1001, 1002, 1003 and so on

int main(){
    Employee harry,varun,darshan;
    // harry.id=1;
    // harry.count=1;  //cannot do this as id and count are private
    harry.setData();
    harry.getData();
    Employee::getCount(); //this is how you call a static function 

    varun.setData();
    varun.getData();
    Employee::getCount();

    darshan.setData();
    darshan.getData();
    Employee::getCount();

    return 0;
}