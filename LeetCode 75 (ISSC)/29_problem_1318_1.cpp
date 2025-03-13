//1318. Minimum Flips to Make a OR b Equal to c
// Or operation (|)
//(class)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcountl((unsigned long)((a | b) ^ c) << 32 | (a & b & ~c));
    }
};

int main() {
    int a = 2; // Example input
    int b = 6; // Example input
    int c = 5; // Example input

    Solution sol;
    int result = sol.minFlips(a, b, c);

    cout << "The minimum number of flips required: " << result << endl;

    return 0;
}
