//2215. Find the Difference of two array
//self
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        vector<vector<int>> ans;
        
        for(int i = 0; i < nums1.size(); i++) {
            set1.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            set1.erase(nums2[i]); // Erase all the values in set1 that are present in nums2
            set2.insert(nums2[i]);
        }
        // Collect values for nums1 not present in nums2
        vector<int> ans1;
        for(auto it : set1) {
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        ans1.clear();
        
        for(int i = 0; i < nums1.size(); i++) {
            set2.erase(nums1[i]);
        }
        // Collect values for nums2 not present in nums1
        for(auto it : set2) {
            ans1.push_back(it);
        }
        ans.push_back(ans1);
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    vector<vector<int>> result = solution.findDifference(nums1, nums2);
    cout << "Test case 1 result: ";
    for(const auto& vec : result) {
        cout << "{ ";
        for(int num : vec) {
            cout << num << " ";
        }
        cout << "} ";
    }
    cout << endl;

    // Test case 2
    nums1 = {1, 2, 3, 3};
    nums2 = {1, 1, 2, 2};
    result = solution.findDifference(nums1, nums2);
    cout << "Test case 2 result: ";
    for(const auto& vec : result) {
        cout << "{ ";
        for(int num : vec) {
            cout << num << " ";
        }
        cout << "} ";
    }
    cout << endl;

    return 0;
}
