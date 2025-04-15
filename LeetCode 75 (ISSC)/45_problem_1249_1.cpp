//1249. Minimum Remove to Make Valid Parentheses
//class OP
//stack
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int sz = s.size();
        stack<int> stk;

        // Iterate over the string and mark invalid ')' for removal
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '(')
            {
                stk.push(i); // Store index of '('
            }
            else if (s[i] == ')')
            {
                if (!stk.empty())
                {
                    stk.pop(); // Valid pair found
                }
                else
                {
                    s[i] = '#'; // Mark invalid ')' for removal
                }
            }
        }

        // Mark unmatched '(' for removal
        while (!stk.empty())
        {
            s[stk.top()] = '#';
            stk.pop();
        }

        // Construct the valid string by skipping marked characters
        string ans = "";
        for (auto e : s)
        {
            if (e != '#')
                ans += e;
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Test cases
    string test1 = "lee(t(c)o)de)";
    string test2 = "a)b(c)d";
    string test3 = "))((";
    string test4 = "(a(b(c)d)";

    // Calling minRemoveToMakeValid function and displaying results
    cout << "Valid string for test1: " << solution.minRemoveToMakeValid(test1) << endl;
    cout << "Valid string for test2: " << solution.minRemoveToMakeValid(test2) << endl;
    cout << "Valid string for test3: " << solution.minRemoveToMakeValid(test3) << endl;
    cout << "Valid string for test4: " << solution.minRemoveToMakeValid(test4) << endl;

    return 0;
}
