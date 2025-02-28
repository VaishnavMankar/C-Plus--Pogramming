//283.Move Zeroes
//In Place
//(class.O)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int position = 0;
        for(int i = 0; i < size; i++){
            if (nums[i] != 0){
                swap(nums[position++], nums[i]);
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12}; // Example input

    Solution sol;
    sol.moveZeroes(nums);

    // Display the result
    cout << "After moving zeroes: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
