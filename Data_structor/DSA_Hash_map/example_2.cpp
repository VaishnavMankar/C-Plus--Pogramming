//Find First Non-Repeating Element
//Given an array, find the first non-repeating element.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> freq;

    // Count occurrences
    for (int num : nums) {
        freq[num]++;
    }

    // Print the hash table (freq map)
   cout << "Hash Table (Element -> Frequency):" << endl;
   for (auto it : freq) {
       cout << it.first << " -> " << it.second << endl;
   }

    // Find the first non-repeating element
    for (int num : nums) {
        if (freq[num] == 1) {
            return num;
        }
    }

    return -1; // If no non-repeating element found
}

int main() {
    vector<int> arr = {4, 5, 1, 2, 5, 1, 2, 3};
    cout << "First non-repeating element: " << firstNonRepeating(arr) << endl;
    //cout << 
    return 0;
}
