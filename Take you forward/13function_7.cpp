#include<bits/stdc++.h>
using namespace std;

//pass by reference
void doSomething(string &s){ //& will help to make modigication from every location 
    s[0] = 't';
    cout << s << endl;
}
int main(){
    string s = "raj";
    doSomething(s);
    cout << s << endl;
    return 0;
}
