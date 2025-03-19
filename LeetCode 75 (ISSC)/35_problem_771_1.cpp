//771. Jewels and stones
//class OP
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int sz = stones.size();
        int js = jewels.size();
        unordered_map<char, int> um;
        for (int i = 0; i < sz; i++) {
            um[stones[i]]++;
        }
        int cnt = 0;
        for (int i = 0; i < js; i++) {
            if (um.find(jewels[i]) != um.end())
                cnt += um[jewels[i]];
        }
        return cnt;
    }
};

int main() {
    // create an instance of Solution class
    Solution solution;

    // define the jewels and stones strings
    string jewels = "aA";
    string stones = "aAAbbbb";

    // call the numJewelsInStones method and print the result
    int result = solution.numJewelsInStones(jewels, stones);
    cout << "Number of jewels in stones: " << result << endl;

    // another example
    string jewels2 = "z";
    string stones2 = "ZZ";
    result = solution.numJewelsInStones(jewels2, stones2);
    cout << "Number of jewels in stones: " << result << endl;

    return 0;
}
