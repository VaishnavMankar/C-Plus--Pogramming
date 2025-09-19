//Count Frequency of Elements in an Array
//Given an array of integers, count the frequency of each element using a hash map.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freqMap;

    // Count occurrences
    for (int num : nums) {
        freqMap[num]++;
    }

    // Print frequencies
    for (auto it : freqMap) {
        cout << "Element: " << it.first << " -> Frequency: " << it.second << endl;
    }
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 1, 4, 2, 3, 3, 3};
    countFrequency(arr);
    return 0;
}
