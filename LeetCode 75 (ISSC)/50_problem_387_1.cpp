//387. Firstt Unique Character in a String
//Unordered map and que 
//class OP
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> freq; // Map to store frequency of characters
        queue<int> q; // Queue to track indices of unique characters

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++; // Increment character frequency
            q.push(i); // Push current index into queue

            // Remove indices from queue if the character is repeating
            while (!q.empty() && freq[s[q.front()]] > 1)
                q.pop();
        }

        // If queue is empty, return -1 (no unique character found), else return front index
        return q.empty() ? -1 : q.front();
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "leetcode";
    string test2 = "loveleetcode";
    string test3 = "aabb";

    // Calling firstUniqChar function and displaying results
    cout << "First unique character index in '" << test1 << "': " << solution.firstUniqChar(test1) << endl;
    cout << "First unique character index in '" << test2 << "': " << solution.firstUniqChar(test2) << endl;
    cout << "First unique character index in '" << test3 << "': " << solution.firstUniqChar(test3) << endl;

    return 0;
}
