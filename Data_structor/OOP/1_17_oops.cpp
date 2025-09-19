//Static Keyword using static variable
#include<iostream>
#include<string>
using namespace std;

void fun(){
    static int x = 0;//init statement - 1 run
    cout << "x : " << x << endl;
    x++;
}

class A{
    public:
        int x;
        
        void incX(){
            x = x + 1;
        }
};

int main(){
    fun();
    fun();
    fun();

    A obj;
    obj.x = 0;
    cout << obj.x << endl;
    obj.incX();
    cout << obj.x << endl;
    return 0;
}