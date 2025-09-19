//Two Sum Problem
//Given an array nums and an integer target, return indices of the two numbers such 
//that they add up to target.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Stores value and index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // Check if the complement exists
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }

        // Store the index of the current element
        numMap[nums[i]] = i;
    }

    return {}; // No solution found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}

// Common unordered_map Functions

// Function	                             Description
// umap[key]	                Accesses or inserts a value for a key
// umap.insert({key, value})	Inserts a key-value pair
// umap.find(key)	            Returns an iterator to the key (or umap.end() if not found)
// umap.erase(key)	            Removes an element by key
// umap.size()	                Returns the number of key-value pairs
// umap.count(key)	            Returns 1 if key exists, 0 otherwise
// umap.clear()	                Removes all elements
// umap.empty()	                Returns true if empty, false otherwise