//605.Can Place Flowers
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            if (flowerbed[i] == 0 &&   //
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                count++;
                i++; // Skip the next plot as we can't plant adjacent flowers
            }
        }
        
        return count >= n;
    }
};

int main() {
    Solution solution;

    // Test case
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool result = solution.canPlaceFlowers(flowerbed, n);
    cout << (result ? "true" : "false") << endl; // Expected output: true

    return 0;
}
