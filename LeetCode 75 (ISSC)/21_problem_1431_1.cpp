//1431. Kids With The Greatest Number of Candies 
//self
//array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int currentMax = 0;

        for (int i = 0; i < candies.size(); i++) {
            currentMax = max(currentMax, candies[i]);
        }
        vector<bool> result(candies.size());

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= currentMax) {
                result[i] = true;
            } else {
                result[i] = false;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> candies1 = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    vector<bool> result1 = solution.kidsWithCandies(candies1, extraCandies1);
    cout << "Test case 1 result: ";
    for (bool val : result1) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> candies2 = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    vector<bool> result2 = solution.kidsWithCandies(candies2, extraCandies2);
    cout << "Test case 2 result: ";
    for (bool val : result2) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> candies3 = {12, 1, 12};
    int extraCandies3 = 10;
    vector<bool> result3 = solution.kidsWithCandies(candies3, extraCandies3);
    cout << "Test case 3 result: ";
    for (bool val : result3) {
        cout << (val ? "true" : "false") << " ";
    }
    cout << endl;

    return 0;
}
