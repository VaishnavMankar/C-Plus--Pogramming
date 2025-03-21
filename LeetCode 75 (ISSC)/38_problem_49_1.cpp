//49. Group Anagrams
//class OP
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for(const auto& s : strs) {
           string sortS = s;
           sort(sortS.begin(), sortS.end());
           um[sortS].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto& e : um)
            ans.push_back(e.second);
    
        return ans;
    }
};

int main() {
    // Example input
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Create an instance of Solution class
    Solution sol;
    
    // Call the groupAnagrams function
    vector<vector<string>> result = sol.groupAnagrams(strs);

    // Display the result
    for(const auto& group : result) {
        for(const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
