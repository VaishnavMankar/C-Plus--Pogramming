//451 Sort Characters By Frequency.
//Heap(Priority Queue)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
    public:
        string frequencySort(string s) {
            unordered_map<char, int> freq;
            for (char ch : s) {
                freq[ch]++;
            }
    
            priority_queue<pair<int, char>> maxHeap;
    
            // Create heap from frequency table
            for (auto& entry : freq) {
                maxHeap.push({entry.second, entry.first});
            }
    
            string result;
    
            while (!maxHeap.empty()) {
                pair<int, char> topElement = maxHeap.top();
                maxHeap.pop();
    
                int count = topElement.first;
                char ch = topElement.second;
    
                result += string(count, ch);
            }
            return result;
        }
    };

int main() {
    string s = "tree"; // Example input
    Solution solution;
    cout << "Sorted by frequency: " << solution.frequencySort(s) << endl;
    return 0;
}


// int main() {
//     // Example test cases
//     string s1 = "tree";      // Expected output: "eert" or "eetr"
//     string s2 = "cccaaa";    // Expected output: "aaaccc" or "cccaaa"
//     string s3 = "Aabb";      // Expected output: "bbAa" or "bbaA"

//     Solution solution;

//     // Running test cases
//     cout << "Sorted frequency for 'tree': " << solution.frequencySort(s1) << endl;
//     cout << "Sorted frequency for 'cccaaa': " << solution.frequencySort(s2) << endl;
//     cout << "Sorted frequency for 'Aabb': " << solution.frequencySort(s3) << endl;

//     return 0;
// }
