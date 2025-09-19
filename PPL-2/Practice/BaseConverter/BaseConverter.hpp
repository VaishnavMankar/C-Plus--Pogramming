#include<iostream>
#include<string>
using namespace std;

class BaseConverter{
    private:
        int number;
        int base;
    public:
        void setValues(int num, int baseValue);
        string converter();
};