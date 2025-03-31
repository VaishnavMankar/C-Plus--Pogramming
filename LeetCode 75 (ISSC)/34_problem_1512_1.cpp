//1512. Number of Good Pairs
// Hash Table
//(class)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int sz = nums.size();
        
        unordered_map<int ,int> us;

        for(int i = 0; i < sz; i++)
          us[nums[i]]++;

        int cnt(0);
        for(auto e: us)
          if(e.second > 1)
             cnt += (e.second * (e.second - 1)) / 2;

        return cnt;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3}; // Example input

    Solution sol;
    int result = sol.numIdenticalPairs(nums);

    cout << "The number of good pairs is: " << result << endl;

    return 0;
}
