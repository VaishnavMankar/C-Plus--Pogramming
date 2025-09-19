#include<iostream>
using namespace std;

//function definition
int printHello(){
    cout << "Hello\n";
    return 3;
}

int main(){
  //function call / invoke
  int value = printHello();
  cout << "value = " << value << endl;

  printHello();

  cout << printHello() << endl;
  return 0;
}