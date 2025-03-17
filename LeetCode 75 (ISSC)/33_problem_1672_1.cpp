//1672. Richest Customer Wealth
//matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(int i = 0; i < accounts.size(); i++) {
            int rowMax = 0;
            for(int j = 0; j < accounts[0].size(); j++) {
                rowMax += accounts[i][j];
            }
            maxWealth = max(maxWealth, rowMax);
        }
        return maxWealth;
    }
};

int main() {
    vector<vector<int>> accounts = {
        {1, 2, 3},
        {3, 2, 1},
        {4, 5, 6}
    }; // Example input

    Solution sol;
    int result = sol.maximumWealth(accounts);

    cout << "The maximum wealth is: " << result << endl;

    return 0;
}
