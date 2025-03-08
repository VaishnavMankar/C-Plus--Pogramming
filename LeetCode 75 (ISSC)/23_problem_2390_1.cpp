// 2390. Removing Stars from a String
//using stack
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
       stack<char> st;
       for(int i = 0; i < s.length(); i++) {
           if(s[i] == '*')
               st.pop();
           else
               st.push(s[i]);
       }
       string result = "";
       while(!st.empty()) {
           result.push_back(st.top());
           st.pop();
       }
       reverse(begin(result), end(result));
       return result;
    }
};

int main() {
    Solution solution;
    string s = "leet**cod*e";
    string result = solution.removeStars(s);
    cout << "The result after removing stars is: " << result << endl;
    return 0;
}
