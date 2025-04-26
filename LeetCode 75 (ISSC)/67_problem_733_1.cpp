//733. Flood Fill
//Graph

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for performing flood fill on an image.
 */
class Solution {
public:
    // Depth-First Search function to update adjacent pixels
    void dfs(vector<vector<int>>& image, int x, int y, int newColor, int originalColor) {
        if (x < 0 || y < 0 || x >= image.size() || y >= image[0].size()) {
            return; // Out of bounds check
        }
        if (image[x][y] != originalColor) {
            return; // If pixel is not the original color, stop recursion
        }

        image[x][y] = newColor; // Change pixel color

        // Recursively fill adjacent pixels
        dfs(image, x - 1, y, newColor, originalColor); // Up
        dfs(image, x + 1, y, newColor, originalColor); // Down
        dfs(image, x, y + 1, newColor, originalColor); // Right
        dfs(image, x, y - 1, newColor, originalColor); // Left
    }

    // Main function to initiate flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) { // Avoid unnecessary work if color is already set
            dfs(image, sr, sc, color, originalColor);
        }
        return image;
    }
};

// Function to print an image
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example test case
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1, sc = 1, color = 2; // Starting position and new color

    Solution solution;

    cout << "Original Image:" << endl;
    printImage(image);

    vector<vector<int>> result = solution.floodFill(image, sr, sc, color);

    cout << "\nUpdated Image after Flood Fill:" << endl;
    printImage(result);

    return 0;
}
