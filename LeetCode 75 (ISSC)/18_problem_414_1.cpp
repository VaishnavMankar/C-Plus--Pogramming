//414. Third Maximum Number
//self

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1 = LLONG_MIN;
        long long max2 = LLONG_MIN;
        long long max3 = LLONG_MIN;

        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num < max1 && num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num < max2 && num > max3) {
                max3 = num;
            }
        }
        if (max3 == LLONG_MIN) {
            return max1;
        }
        return max3;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 2, 1};
    cout << "Third Maximum of {3, 2, 1} is: " << solution.thirdMax(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 2};
    cout << "Third Maximum of {1, 2} is: " << solution.thirdMax(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {2, 2, 3, 1};
    cout << "Third Maximum of {2, 2, 3, 1} is: " << solution.thirdMax(nums3) << endl;

    return 0;
}
