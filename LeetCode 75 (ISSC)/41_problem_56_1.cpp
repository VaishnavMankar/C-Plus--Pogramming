//56. Merge Sort
//Class OP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return {}; // Return empty result if input is empty

        // Sort intervals based on starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]); // Initialize result with first interval

        for (int i = 1; i < intervals.size(); ++i)
        {
            // Check if the current interval overlaps with the last one in result
            if (result.back()[1] >= intervals[i][0])
            {
                // Merge overlapping intervals
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else
            {
                // No overlap, add new interval to result
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Example input intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Call merge function
    vector<vector<int>> merged_intervals = sol.merge(intervals);

    // Print merged intervals
    cout << "Merged Intervals: ";
    for (const auto &interval : merged_intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
