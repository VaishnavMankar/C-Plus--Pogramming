//1003. Check if Word is Valid After Substitutions
//Stack
//Class OP
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        // Iterate through each character in the string
        for (auto e : s)
        {
            if (e != 'c') // Push 'a' and 'b' onto the stack
            {
                stk.push(e);
            }
            else if (stk.size() >= 2) // When 'c' is encountered, check for "abc" pattern
            {
                if (stk.top() != 'b')
                    return false;
                stk.pop();

                if (stk.top() != 'a')
                    return false;
                stk.pop();
            }
        }

        // The stack must be empty for a valid string
        return stk.empty();
    }
};

int main()
{
    Solution solution;

    // Test cases
    vector<string> testCases = {"aabcbc", "abcabcababcc", "abccba", "abc", "aabbcc"};

    // Calling isValid function and displaying results
    for (const auto &test : testCases)
    {
        cout << "Is \"" << test << "\" a valid string? " << (solution.isValid(test) ? "True" : "False") << endl;
    }

    return 0;
}
