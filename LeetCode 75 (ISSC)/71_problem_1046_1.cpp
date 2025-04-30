//1046. Last Strong Weight
//Heap (Priority Queue)
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> mH(stones.begin(), stones.end());

        while(mH.size() >= 2){
            int s1 = mH.top();
            mH.pop();
            
            int s2 = mH.top();
            mH.pop();

            if(s1 != s2){
                mH.push(s1 - s2);
            }
        }
        return mH.empty() ? 0 : mH.top();
    }
};

int main() {
    // Example test cases
    vector<int> stones1 = {2, 7, 4, 1, 8, 1}; // Expected output: 1
    vector<int> stones2 = {1};                // Expected output: 1

    Solution solution;

    // Running test cases
    cout << "Last stone weight for {2, 7, 4, 1, 8, 1}: " << solution.lastStoneWeight(stones1) << endl;
    cout << "Last stone weight for {1}: " << solution.lastStoneWeight(stones2) << endl;

    return 0;
}
