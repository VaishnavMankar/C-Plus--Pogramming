#include<iostream>
using namespace std;

int sum(int a,int b){
    int c = a + b;
    return c;
}
//This will not swap a and b
void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}
// to swap the values we need to use pointer
//call buy reference
void swapPointer(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapReferenceVar(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;  
}

int main(){
    int a = 4, b = 5;
    cout << "The sum of 4 and 5 is " << sum(4,5)<<endl;
    cout<< "The value a is "<<a<<" and the value of b is "<<b<< endl;
    swap(a,b);
    cout<< "The value a is "<<a<<" and the value of b is "<<b<< endl;
    //the above one will not work
    swapPointer(&a,&b);
    cout<< "The value a is "<<a<<" and the value of b is "<<b<< endl;
    //the below one is call
    swapReferenceVar(a,b);
    cout<< "The value of a is "<<a<<" And the value of b is "<< b<< endl; 
    
 
    return 0;
}