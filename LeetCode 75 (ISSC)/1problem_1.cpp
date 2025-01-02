//1.Two Sum
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return{-1,-1};
    }
};

int main(){
    Solution solution;

    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1,target1);
    cout << "Inbdics: [" << result1[0] << "," << result1[1] << "]" <<endl;

    return 0;
}