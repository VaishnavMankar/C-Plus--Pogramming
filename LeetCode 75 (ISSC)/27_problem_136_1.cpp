//136.Single Number
//XOR
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int val: nums){
            ans ^= val;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2}; // Example input

    Solution sol;
    int result = sol.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}
