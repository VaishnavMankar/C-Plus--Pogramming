#include<iostream>
using namespace std;

//Function prototype
//Type function-name (arguments);
//int sum(int a,int b); ---> acceptable
//int sum(int a,b) ---> not acceptable
int sum(int, int); //----> acceptable

//empty ffunction to print something
void g();
void g(void);

int main(){
    int n1, n2;
    cout << "Enter first number "<< endl;
    cin >> n1;
    cout << "Enter second number "<< endl;
    cin >> n2;
    // n1 and n2 are acutal parameters
    cout << "The sum of two number are: " << sum(n1,n2) << endl;
    g();
    return 0;
}

int sum(int a,int b){
    //formal parameter a and b will be taking values from actual parameter
    //n1 and n2
    int c = a+b;
    return c;
}

void g(){
    cout << "\n Hello world";
}