#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    int sum;

    // Declare pointers
    int *ptrA = &a;
    int *ptrB = &b;
    int *ptrSum = &sum;

    // Perform addition using pointers
    *ptrSum = *ptrA + *ptrB;

    // Output the result
    cout << "Sum of " << *ptrA << " and " << *ptrB << " is: " << *ptrSum << endl;

    return 0;
}
