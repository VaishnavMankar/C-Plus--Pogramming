//26. Remove Duplicate from sorted array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int left = 1;
        for(int right = 1; right < nums.size(); right++) {
            if(nums[right] != nums[right - 1]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};
    int newLength = solution.removeDuplicates(nums);
    cout << "The new length is: " << newLength << endl;
    cout << "The array after removing duplicates: ";
    for(int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
