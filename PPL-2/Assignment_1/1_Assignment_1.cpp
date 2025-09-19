#include<iostream>
using namespace std;

float celciousToFarenheit(float celcious){
    float farenheit = (1.8*celcious) + 32;
    return farenheit;
}

int main(){
    float celcious = 0;
    cout << "Enter the temprature in celcious: ";
    cin >> celcious;
    float farenheit = celciousToFarenheit(celcious) ;
    cout << "The temprature you entered in Farenheit will be: " << farenheit << endl;
    return 0;
}


