//347. Top K Frequent Elements
//Heap
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // for(auto& [num, count] : um) {
        //     minHeap.push({count, num});
        //     if(minHeap.size() > k)
        //         minHeap.pop();
        // }
        for (auto& pair : um) {
            int num = pair.first;
            int count = pair.second;
            minHeap.push({count, num});
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<int> ans;
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = solution.topKFrequent(nums, k);

    cout << "Top " << k << " Frequent Elements: [ ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << "]" << endl;

    return 0;
}
