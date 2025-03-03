//169. Majority Element
// In place
//(self)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0) {
                result = nums[i];
            }
            if(result == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {3, 2, 3}; // Example input

    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "The majority element is: " << result << endl;

    return 0;
}
