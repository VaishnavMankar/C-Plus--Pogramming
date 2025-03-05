//941.valid mountain array
//class.s

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int sz = arr.size();
        
        if (sz < 3)
            return false;
        
        int i = 0;

        //1. walk up
        while (i + 1 < sz && arr[i] < arr[i + 1])
            ++i;

        //peak can't be the first or last element
        if (i == 0 || i == sz - 1) return false;

        //2. walk down
        while (i + 1 < sz && arr[i] > arr[i + 1])
            ++i;

        return i == sz - 1;     
    }
};

int main() {
    Solution solution;
    vector<int> test1 = {2, 1}; // Expected output: false
    vector<int> test2 = {3, 5, 5}; // Expected output: false
    vector<int> test3 = {0, 3, 2, 1}; // Expected output: true
    vector<int> test4 = {0, 2, 3, 3, 5, 2, 1, 0}; // Expected output: false
    vector<int> test5 = {0, 2, 3, 4, 5, 2, 1, 0}; // Expected output: true

    cout << boolalpha; // to print boolean values as true/false
    cout << "Test case 1: " << solution.validMountainArray(test1) << endl;
    cout << "Test case 2: " << solution.validMountainArray(test2) << endl;
    cout << "Test case 3: " << solution.validMountainArray(test3) << endl;
    cout << "Test case 4: " << solution.validMountainArray(test4) << endl;
    cout << "Test case 5: " << solution.validMountainArray(test5) << endl;

    return 0;
}
