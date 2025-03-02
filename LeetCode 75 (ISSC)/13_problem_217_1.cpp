//217. Contains duplicate
//Time Limit Exceeded for this problem
//using two for loop
//class
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz = nums.size();
        
        for(int i = 0; i < sz - 1; i++) {
            for(int j = i + 1; j < sz; j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1}; // Example input

    Solution sol;
    bool result = sol.containsDuplicate(nums);

    cout << "Contains duplicate: " << (result ? "Yes" : "No") << endl;

    return 0;
}
