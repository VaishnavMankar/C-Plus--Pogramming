#include<iostream>
using namespace std;

typedef struct employee{
    int eID;
    char favChar;
    float salary;
}ep;

union money{
    int rice;
    char car;
    float pounds;
};

int main(){
    ep hatty;
    union money m1;
    m1.rice = 34;
    m1.rice = 34;
    m1.car = 'c';
    cout << m1.rice<<endl;

    enum Meal{breakfast, lunch, dinner};

    Meal b1 = lunch;
    cout << b1;
    cout << breakfast<<endl;
    cout << lunch<<endl;
    cout << dinner<<endl;
    return 0;

}