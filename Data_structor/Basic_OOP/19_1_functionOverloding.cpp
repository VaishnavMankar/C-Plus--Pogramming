#include<iostream>
using namespace std;

int sum(int a, int b){
    return a+b;
}

int sum(int a,int b,int c){
    return a+b+c;
}

//calculating the volme of a cylinder
int volume(double r, int h){
    return (3.14 * r * r * h);
}

//calculatine the volume of a cube
int volume(int a){
    return a * a * a;
}

//rectangular box
int volume(int l,int b,int h){
    return (l*b*h);
}
int main(){
    cout << "The sum of 3 and 6 is " << sum(3,6)<< endl;
    cout << "The sum of 3,7 and 6 is " << sum(3,6,7) << endl;
    cout << "The volume of cubite of 3,7 and 6 is "<< volume(3,7,6) << endl;
    cout << "The volume of cylinder of radius 3 and hight 4 is "<< volume(3,6) << endl;
    cout << "The volume of cube of side 3 is " << volume(3) << endl;

    return 0;
}