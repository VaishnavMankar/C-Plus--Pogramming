//682. Baseball Game
//Class OP
//Stack
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> stk;
        for (auto o : operations)
        {
            if (o == "C" && !stk.empty()) // "C" - Remove previous score
            {
                stk.pop();
            }
            else if (o == "D" && !stk.empty()) // "D" - Double previous score and add to stack
            {
                stk.push(2 * stk.top());
            }
            else if (o == "+" && stk.size() > 1) // "+" - Add sum of last two scores
            {
                int temp = stk.top();
                stk.pop();
                int n = temp + stk.top();
                stk.push(temp);
                stk.push(n);
            }
            else // Push numeric score
            {
                stk.push(stoi(o));
            }
        }
        int ans = 0;
        while (!stk.empty()) // Compute total sum of scores
        {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<string> test1 = {"5", "2", "C", "D", "+"};
    vector<string> test2 = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    vector<string> test3 = {"1", "C"};

    // Calling calPoints function and displaying results
    cout << "Total score for test1: " << solution.calPoints(test1) << endl;
    cout << "Total score for test2: " << solution.calPoints(test2) << endl;
    cout << "Total score for test3: " << solution.calPoints(test3) << endl;

    return 0;
}
