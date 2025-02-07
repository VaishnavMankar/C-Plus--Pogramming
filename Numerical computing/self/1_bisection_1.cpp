//Bisection method
#include<iostream>
using namespace std;
float findValueAt(float x){
    return (x*x*x) - (2*x) -5;
}

float bisect(float x1, float x2){
    return (x1+x2)/2;
}

int main(){
    int maxIteration, i = 1;
    float x1,x2,x;
    cout << "Enter maximum number of iteration: " << endl;
    cin >> maxIteration;
//-----------------------------------------------------------
 do {
    cout << "enter the value of x1 and x2(starting boundary)" << endl;
    cin >> x1;
    cin >> x2;
    if(findValueAt(x1)*findValueAt(x2)> 0){
        cout << "Roots are invalid" << endl;
        continue;
    }
    else{
        cout << "roots lie between " << x1 << "and " << x2 << endl;
        break;
    }
 }while(1);
//-----------------------------------------------------------------
    //x1 and x2 -> finalised
    while (i <= maxIteration){
        x = bisect(x1,x2); //find the mid point
        if(findValueAt(x)*findValueAt(x1)<0){
            x2 = x; // x2 is shifted
        }
        else if (findValueAt(x)*findValueAt(x2)<0){
            x1 = x; //x1 is shifted
        }
        cout << "Iteration = " << i << "root = " << x << endl;
        i++;
    }
    cout << "Root = " << x << "Total Iteration = " << --i << endl;
    
    return 0;

}