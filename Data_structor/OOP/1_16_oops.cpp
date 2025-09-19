//Abstract class
#include<iostream>
#include<vector>
using namespace std;

class Shape{//abstract class
    virtual void draw() = 0;//pure virrtual function
};

class Circle : public Shape{
    public:
        void draw(){
            cout << "drawing a circle\n";
        }
};

int main(){
    Circle c1;
    c1.draw();
    return 0;
}