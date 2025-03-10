//2425. Bitwise xor of all pairings
// using two for loop
//Time Limit Exceeded for this problem
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        int ans = 0;
        for(int i = 0; i < sz1; i++) {
            for(int j = 0; j < sz2; j++) {
                ans = ans ^ (nums1[i] ^ nums2[j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    cout << sol.xorAllNums(nums1, nums2) << endl;  // Output: 13

    return 0;
}
