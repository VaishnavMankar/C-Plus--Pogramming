// 20. Valid parentheses
//class OP
#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  // Corrected stack variable name
        for(int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } 
            else {
                if(!st.empty()) {
                    if((ch == ')' && st.top() == '(') || 
                       (ch == '}' && st.top() == '{') || 
                       (ch == ']' && st.top() == '[')) {  // Fixed condition for brackets
                        st.pop();
                    } 
                    else {
                        return false;
                    }
                } 
                else {
                    return false;
                }
            }
        }
        if(st.empty()) {  // Fixed typo: empy() -> empty()
            return true;   // Fixed typo: ture -> true
        } 
        else {
            return false;
        }
    }
};
