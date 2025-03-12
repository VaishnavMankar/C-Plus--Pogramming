//2683. Neighboring bitwise XOR 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int sz = derived.size();

        int ans = 0;
        for(int i = 0; i < sz; i++){
            ans = ans ^ derived[i];
        }
        return (ans == 0);
    }
};

int main() {
    vector<int> derived = {1, 1, 0}; // Example input

    Solution sol;
    bool result = sol.doesValidArrayExist(derived);

    cout << "Does a valid array exist? " << (result ? "Yes" : "No") << endl;

    return 0;
}
