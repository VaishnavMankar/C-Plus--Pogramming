#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;

public:
    void read(void);
    void chk_bin(void);
    void ones_compliment(void);
    void display(void);
};

void binary ::read(void)
{
    cout << "Enter a binary number " << endl;
    cin >> s;
}

void binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary ::ones_compliment(void)
{
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}

void binary ::display(void)
{
    cout << "Display your binary number" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{
    // OOPs - Class and object

    // C++ --> initally called --> C with class by stoustroup
    // class --> extension of structures (in c)
    // Structure has limitations
    //       -members are public
    //       -No methods
    // classes --> structure + more
    // classes --> can have methods and properties
    // classes --> can make few member as private & few as public
    // structures in c++ are typedefed
    // you can declare objects along with the class declaration like this:
    /*Class Employee{
           class definition
   } harry, rohan, lovish */

    // Nesting of member function
    binary b; // b is an object which we have created for class binary
    b.read();
    b.chk_bin();
    b.display();
    b.ones_compliment();
    b.display();

    return 0;
}