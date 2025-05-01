//2974. Minimum Number Game
//Heap (Priority Queue)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<>> minHeap(nums.begin(), nums.end());
        vector<int> arr;

        while(minHeap.size() >= 2){
            int alice = minHeap.top();
            minHeap.pop();
            int bob = minHeap.top();
            minHeap.pop();

            arr.push_back(bob); //Bob
            arr.push_back(alice); // Alice
        }

        // nums.size is odd
        if (!minHeap.empty()) {
            arr.push_back(minHeap.top());
            minHeap.pop();
        }
        return arr;
    }
};

// Function to print the result array
void printResult(const vector<int>& arr) {
    cout << "[ ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Example test cases
    vector<int> nums1 = {5, 4, 2, 3}; // Expected output: [3, 2, 5, 4]
    vector<int> nums2 = {2, 5};       // Expected output: [5, 2]

    Solution solution;

    // Running test cases
    cout << "Result for nums1 = {5, 4, 2, 3}: ";
    printResult(solution.numberGame(nums1));

    cout << "Result for nums2 = {2, 5}: ";
    printResult(solution.numberGame(nums2));

    return 0;
}
