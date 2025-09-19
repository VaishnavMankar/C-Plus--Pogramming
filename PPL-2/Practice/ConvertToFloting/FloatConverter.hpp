#include<iostream>
#include<string>
using namespace std;

class ConvertFloat{
    private:
        string integerPart;
        string fractionalPart;
        
    public:
        void setValues(string number);
        string formatNumber();
};