//503. Next Greater element ll
//class OP

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        stack<int> stk;
        vector<int> ans(sz, -1);

        for(int i = (2 * sz) - 1; i >= 0; --i){
            while(!stk.empty() && stk.top() <= nums[i % sz])
              stk.pop();

            if(i < sz && !stk.empty())
              ans[i] = stk.top();
            
            stk.push(nums[i % sz]);
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 1};

    // Create an instance of Solution class
    Solution sol;

    // Call the nextGreaterElements function
    vector<int> result = sol.nextGreaterElements(nums);

    // Display the result
    for(int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
