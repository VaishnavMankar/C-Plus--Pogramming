//find charater lowercase or uppercase
#include<iostream>
using namespace std;

int main(){
    char ch;
    cout << "Enter a character: ";
    cin >>  ch;

    if(ch >= 'a' && ch <= 'z'){
        cout << "lowercase\n";
    }
    else{
        cout << "uppercase\n";
    }
    return 0;
}