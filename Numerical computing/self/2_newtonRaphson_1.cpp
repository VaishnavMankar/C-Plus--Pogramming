//https://youtu.be/b70Op6iZh2s?si=ntCshU1jnXqsRPOY
#include<iostream>
#include<math.h>
using namespace std;
#define EPSILON 0.0001

float f(float x){
    return x*x*x - 3*x - 5;
}
float differentiate(float x){
    return 3*x*x - 3;
}

int main(){
    int maxIteration,i;
    float x1,x2,x,x0;
    cout << "enter the maximum no of Integers" << endl;
    cin >> maxIteration ;
  //--------------compute x1 and x2 ----------------------

  do{
    cout << "Enter the  value of x1 and x2(starting boundary): " << endl;
    cin >> x1;
    cin >> x2;
    if(f(x1)*f(x2) > 0){
        cout << "Boundary values are Invalid" << endl;
        continue;
    }
    else{
        cout << "Root lie between " << x1 << " and " <<  x2 << endl;
        break;
    }
  }while(1);

  //finx x0
  if(fabs(f(x1)) < fabs(f(x2)))
    x0 = x1;
  else
    x1 = x2;
  
  //apply successive appprroximation to find the root b/w x1 and x2
  //------------Find root--------------
  for(i = 1;i <= maxIteration;i++){
    x = x0 - (f(x0)/differentiate(x0));
    if(fabs(x-x0)<EPSILON){
        cout << "Iteractions = " << i << " Final Root = " << x << endl;
        return 0;
    }
    cout << "Iteratitons = " << i << " Root = " << x << endl;
    x0 = x;
  } 
  cout << "Root = " << x << "Total Iteration = " << --i << endl;
  return 0;
}