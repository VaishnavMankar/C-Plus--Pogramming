#include<iostream>
#include<string>
using namespace std;

class ABC {
    public:
        ABC(){
            cout << "Constructors\n";
        }
        ~ABC(){
          cout << "destructor\n";
        }
};

int main(){
    if(true){
        static ABC obj;
    }
    cout << "end of main function\n";
    return 0;
}