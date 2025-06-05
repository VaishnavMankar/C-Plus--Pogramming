#include "question_1.hpp"
using namespace std;

int main() {
    int number, base;
    cout << "Enter a positive integer: ";
    cin >> number;
    cout << "Enter the base (2-36): ";
    cin >> base;

    if (number < 0) {
        cout << "Invalid input! Please enter a positive integer." << std::endl;
        return 1;
    }

    question_1 converter;
    converter.setValues(number, base);
    string result = converter.convert();

    cout << "Converted Number: " << result << std::endl;
    return 0;
}
