//3289. The two sneaky Number of Diditville
//Class op
//unordered maps
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int sz = nums.size();
        unordered_map<int, int> umap;
        vector<int> ans;
        for (int i = 0; i < sz; i++) {
            if (umap.find(nums[i]) != umap.end()) {
                ans.push_back(nums[i]);
            } else {
                umap[nums[i]] = 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {0, 1, 1, 0};
    vector<int> result1 = solution.getSneakyNumbers(nums1);
    cout << "Sneaky numbers in {0, 1, 1, 0}: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {0, 3, 2, 1, 3, 2};
    vector<int> result2 = solution.getSneakyNumbers(nums2);
    cout << "Sneaky numbers in {0, 3, 2, 1, 3, 2}: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Test case 3
    vector<int> nums3 = {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2};
    vector<int> result3 = solution.getSneakyNumbers(nums3);
    cout << "Sneaky numbers in {7, 1, 5, 4, 3, 4, 6, 0, 9, 5, 8, 2}: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
