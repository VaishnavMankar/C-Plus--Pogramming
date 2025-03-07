// 724. Find Pivot Index         
//using set
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int rightSum = accumulate(nums.begin(), nums.end(), 0);
            int leftSum = 0;
            for (int i = 0; i < nums.size(); i++) {
                rightSum -= nums[i];
                if (leftSum == rightSum) {
                    return i;
                }
                leftSum += nums[i];
            }
            return -1;
        }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pivotIndex = solution.pivotIndex(nums);
    cout << "The pivot index is: " << pivotIndex << endl;
    return 0;
}
