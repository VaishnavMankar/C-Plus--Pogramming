#include<iostream>
using namespace std;

class GcdLcm{
    private:
        int num1, num2;
        int computeGcd(int a, int b);
    public:
        GcdLcm(int a, int b);
        int getGcd();
        int getLcm();
};