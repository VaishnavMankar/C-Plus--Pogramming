//pass my reference using pointer and pass by reference using ali
//Mostly we usd pass my reference sunig ali
#include<iostream>
using namespace std;

void changeA(int* a){//without pointers it is still pass by val
    //using pointers we are doint pass by reference usinng pointer
    *a = 20;// and * helps ous to axcess the value at that location
}

void changeB(int &b){//Pass by reference using ali
    b = 20;
}

int main(){
    int a = 10;
    changeA(&a); //Here we are passing the memory address of a
    cout << "Inside main function: " << a << endl;

    changeB(a);
    cout << "inside main fnx : " << a << endl;

    return 0;
}