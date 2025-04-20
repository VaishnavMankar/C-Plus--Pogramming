//189. Rotate Array

#include <iostream>
#include <vector>
#include <algorithm> // For reverse function

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n]

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the rest of the elements after k
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;

    cout << "Original array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    sol.rotate(nums1, k1);

    cout << "Rotated array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    return 0;
}
