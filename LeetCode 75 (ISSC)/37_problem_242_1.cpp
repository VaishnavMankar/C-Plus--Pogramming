// 242. Valid Anagram
//using two for loop
#include<iostream>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; // Added this check to ensure both strings are of the same length
        
        int ss = s.size();
        int st = t.size();
        for(int i = 0; i < ss; i++) {
            bool flag = false;
            for(int j = 0; j < st; j++) {
                if(t[j] != '#' && s[i] == t[j]) {
                    t[j] = '#'; // Added semicolon here
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                return false;
            }
        }
        return true;
    }
};
