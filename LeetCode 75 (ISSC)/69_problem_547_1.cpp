//547. Number of Provinces
//Graph

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
        visited[city] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[city][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                stack<int> stk;
                stk.push(i);

                while (!stk.empty()) {
                    int city = stk.top();
                    stk.pop();

                    if (!visited[city]) {
                        visited[city] = true;
                    }
                    for (int j = 0; j < n; j++) {
                        if (isConnected[city][j] == 1 && !visited[j]) {
                            stk.push(j);
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};

// Function to print adjacency matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example test cases
    vector<vector<int>> isConnected1 = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    vector<vector<int>> isConnected2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    Solution solution;

    // Print test case details
    cout << "Test Case 1:" << endl;
    printMatrix(isConnected1);
    cout << "Number of provinces: " << solution.findCircleNum(isConnected1) << endl;

    cout << "\nTest Case 2:" << endl;
    printMatrix(isConnected2);
    cout << "Number of provinces: " << solution.findCircleNum(isConnected2) << endl;

    return 0;
}
