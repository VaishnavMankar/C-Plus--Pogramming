//941. Vallid Mountain Array
//self 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        int peak = 0;
        if (size < 3) return false;
        for(int i = 1; i < size - 1; i++) {
            int prev = arr[i - 1];
            int curr = arr[i];
            int next = arr[i + 1];
            if (prev == curr || curr == next)
                return false;
            if (prev > curr && curr < next)
                return false;
            if (prev < curr && curr > next) {
                peak++;
                if (peak > 1)
                    return false;
            }
        }
        return peak == 1;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1};  // Example input, you can change this
    bool result = sol.validMountainArray(arr);

    cout << "Is the array a valid mountain array? " << (result ? "Yes" : "No") << endl;

    return 0;
}
