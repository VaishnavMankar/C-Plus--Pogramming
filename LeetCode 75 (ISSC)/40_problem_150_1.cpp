//150 Evaluation Reverse Polish Notation 
//Class OP
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto e : tokens) {
            if ((e == "+" || e == "-" || e == "/" || e == "*") && stk.size() >= 2) {
                int rgt = stk.top();
                stk.pop();
                int lft = stk.top();
                stk.pop();
                if (e == "+")
                    stk.push(lft + rgt);
                else if (e == "-")
                    stk.push(lft - rgt);
                else if (e == "*")
                    stk.push(lft * rgt);
                else if (e == "/")
                    stk.push(lft / rgt);
            } else {
                stk.push(stoi(e));
            }
        }
        return stk.top();
    }
};

int main() {
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"}; // Example input
    cout << "Result: " << sol.evalRPN(tokens) << endl; // Expected Output: 9
    
    return 0;
}
