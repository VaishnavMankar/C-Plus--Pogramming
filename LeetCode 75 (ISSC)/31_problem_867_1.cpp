//867. Transpose Matrix
//matrix (class)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> matrix2(col, vector<int>(rows)); // Use col and rows

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < col; j++) {
                matrix2[j][i] = matrix[i][j];
            }
        }
        return matrix2;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    }; // Example input

    Solution sol;
    vector<vector<int>> result = sol.transpose(matrix);

    // Display the transposed matrix
    cout << "Transposed matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
