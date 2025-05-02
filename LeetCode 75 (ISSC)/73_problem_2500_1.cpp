//2500. Deleted Greatest Value in Each Row
//Heap (Priority Queue)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        vector<std::priority_queue<int>> heaps;

        // Max-heaps for each row
        for (const auto& row : grid) {
            priority_queue<int> pq(row.begin(), row.end());
            heaps.push_back(move(pq));
        }

        int ans = 0;
        int columns = grid[0].size();

        for (int i = 0; i < columns; i++) {
            int max_val = 0;

            for (int j = 0; j < rows; j++) {
                if (!heaps[j].empty()) {
                    int val = heaps[j].top();
                    heaps[j].pop();
                    max_val = max(max_val, val);
                }
            }
            ans += max_val;
        }
        return ans;
    }
};

int main() {
    // Example test cases
    vector<vector<int>> grid1 = {{1, 2, 4}, {3, 3, 1}}; // Expected output: 8
    vector<vector<int>> grid2 = {{10}}; // Expected output: 10

    Solution solution;

    // Running test cases
    cout << "Result for grid1 = {{1, 2, 4}, {3, 3, 1}}: " << solution.deleteGreatestValue(grid1) << endl;
    cout << "Result for grid2 = {{10}}: " << solution.deleteGreatestValue(grid2) << endl;

    return 0;
}
