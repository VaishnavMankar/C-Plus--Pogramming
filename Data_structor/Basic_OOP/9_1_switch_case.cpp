#include<iostream>
using namespace std;

int main(){
    int age = 0;
    cout << "Enter your age: " << endl;
    cin >> age;
    switch (age)
    {
    case 18:
        cout << "You are 18" << endl;
        break;
    case 22:
        cout << "You are 22" << endl;
        break;
    case 2:
        cout << "You are 2" << endl;
        break;
        
    default:
        cout << "Envalid entry!"<< endl;
        break;
    }
    return 0;
}