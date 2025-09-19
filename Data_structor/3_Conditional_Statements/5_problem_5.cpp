//Nested loop
#include<iostream>
using namespace std;

int main(){
    for(int i = 0; i < 5; i++){
        int main = 5;
        for(int j = 0; j < main; j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}