// 766.Toeplitz Matrix
//(class)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size() - 1; i++) {
            for(int j = 0; j < matrix[0].size() - 1; j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    }; // Example input

    Solution sol;
    bool result = sol.isToeplitzMatrix(matrix);

    cout << "Is the matrix a Toeplitz matrix? " << (result ? "Yes" : "No") << endl;

    return 0;
}
