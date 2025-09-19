#include <iostream>
using namespace std;

class basic_23
{
private:
    int itemID[100];
    int itemPrint[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void setPrice(void);
    void displayPrice(void);
};