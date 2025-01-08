//448.Find All Numbers Disappeared In An Array
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int sz = nums.size();

        vector<bool> arr(sz + 1, false); // Initialize the array with `false`
        vector<int> ans;
        for (int i = 0; i < sz; i++)
            arr[nums[i]] = true;

        for (int i = 1; i <= sz; ++i)
            if (!arr[i])
                ans.push_back(i);

        return ans;
    }
};
