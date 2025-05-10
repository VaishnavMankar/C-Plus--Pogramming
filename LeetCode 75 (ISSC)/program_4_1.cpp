//4. Median of Two Sorted Array
//Array
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            // Get the sizes of both input arrays.
            int n = nums1.size();
            int m = nums2.size();
    
            // Merge the arrays into a single sorted array.
            vector<int> merged;
            for(int i = 0; i  < n; i++){
                merged.push_back(nums1[i]);
            }
            for(int i = 0; i < m; i++){
                merged.push_back(nums2[i]);
            }
            
            //Sort the merged array
            sort(merged.begin(), merged.end());
    
            // Calculate the total number of elements in the merged array.
            int total = merged.size();
    
            if(total % 2 == 1){
                 // If the total number of elements is odd, return the middle element as the median.
                return static_cast<double>(merged[total / 2]);
            } 
            else{
                // If the total number of elements is even, calculate the average of the two middle elements as the median.
                int mid1 = merged[total/2 - 1];
                int mid2 = merged[total/2];
                return (static_cast<double>(mid1) + static_cast<double>(mid2))/2;
            }
        }
    };

// Function to print an array
void printArray(const vector<int>& arr) {
    cout << "[ ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Example test cases
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};

    Solution solution;

    // Running test cases
    cout << "Test Case 1:" << endl;
    printArray(nums1);
    printArray(nums2);
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    cout << "\nTest Case 2:" << endl;
    printArray(nums3);
    printArray(nums4);
    cout << "Median: " << solution.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}
