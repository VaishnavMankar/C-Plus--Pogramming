#include<iostream>
using namespace std;

int main(){
    int n;
    cout<< "Enter no. of terms"<<endl;
    cin >> n;
    float X[n], Y[n], x, sum = 0, term;
    int i,j;

    cout << "Enter Value of X \n";
    for(i = 0; i < n; i++){
        cin >> X[i];
    }
    cout << "Enter value  of Y \n";
    for(i = 0; i < n; i++){
        cin >> Y[i];
    }
    cout << "Enter the value of x for which you want y \n";
    cin >> x;

    //Applying the formula 
    for(i = 0; i < n; i++){
        term = 1;
        for(j = 0; j < n; j++)
        {
            if(i!=j){
                term = term * ((x - X[j])/(X[i]-X[j]));
            }
        }
        sum = sum + term * Y[i];
    }
    cout << "Value at X = "<< x << " is = "<< sum << endl;
    return 0;

}