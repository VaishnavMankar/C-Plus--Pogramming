//566. Reshape the matrix
//matrix
//(self)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat; // If reshape isn't possible, return the original matrix

        vector<vector<int>> reshapedMatrix(r, vector<int>(c));
        for (int i = 0; i < m * n; i++) {
            reshapedMatrix[i / c][i % c] = mat[i / n][i % n];
        }
        return reshapedMatrix;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2},
        {3, 4}
    }; // Example input

    int r = 1; // Desired number of rows
    int c = 4; // Desired number of columns

    Solution sol;
    vector<vector<int>> result = sol.matrixReshape(mat, r, c);

    // Display the reshaped matrix
    cout << "Reshaped matrix:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
