//717: 1-bits and 2-bits character
// using sets
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int sz = bits.size();
        int i = 0;
        for(i = 0; i < (sz - 1); i++) {
            if(bits[i] == 1) {
                i++;
            }
        }
        //return i == (sz - 1);
        if(i == sz - 1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> bits1 = {1, 0, 0};
    cout << (sol.isOneBitCharacter(bits1) ? "true" : "false") << endl;  // Output: true
    
    // Example 2
    vector<int> bits2 = {1, 1, 1, 0};
    cout << (sol.isOneBitCharacter(bits2) ? "true" : "false") << endl;  // Output: false

    return 0;
}
