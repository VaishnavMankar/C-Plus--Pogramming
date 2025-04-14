//496. Next Greatestt Eliment 1
//Class OP
//Unordered map and Stack
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap; // Stores the next gre ater element for each number in nums2
        stack<int> stk;
        int sz = nums2.size();

        // Traverse nums2 from right to left to find next greater elements
        for (int i = (sz - 1); i >= 0; --i)
        {
            while (!stk.empty() && stk.top() <= nums2[i])
            {
                stk.pop(); // Remove smaller elements
            }
            umap[nums2[i]] = stk.empty() ? -1 : stk.top(); // Store next greater element
            stk.push(nums2[i]); // Push current element to stack
        }

        vector<int> ans;
        // Find next greater element for each number in nums1
        for (int num : nums1)
        {
            ans.push_back(umap[num]);
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};

    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};

    // Calling nextGreaterElement function and displaying results
    vector<int> result1 = solution.nextGreaterElement(nums1_1, nums2_1);
    cout << "Next greater elements for {4, 1, 2} in {1, 3, 4, 2}: ";
    for (int num : result1)
        cout << num << " ";
    cout << endl;

    vector<int> result2 = solution.nextGreaterElement(nums1_2, nums2_2);
    cout << "Next greater elements for {2, 4} in {1, 2, 3, 4}: ";
    for (int num : result2)
        cout << num << " ";
    cout << endl;

    return 0;
}
