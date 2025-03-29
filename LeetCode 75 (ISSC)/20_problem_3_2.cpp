//3. Longest Substring Without Repeating Character
//class bf

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
    
        std::unordered_set<char>st;
        int left=0,right=0,ans=0;
        int n=s.length();
        while(right< n){
            if(st.count(s[right])==0){
                st.insert(s[right]);
                right++;
                ans=max(ans,right-left);   
            }
            else{
                st.erase(s[left]);
                left++;
                } 
            }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "abcabcbb";
    cout << "Length of the longest substring without repeating characters in \"abcabcbb\": " 
    << solution.lengthOfLongestSubstring(s1) << endl;
    
    // Test case 2
    string s2 = "bbbbb";
    cout << "Length of the longest substring without repeating characters in \"bbbbb\": " 
        << solution.lengthOfLongestSubstring(s2) << endl;
    
    // Test case 3
    string s3 = "pwwkew";
    cout << "Length of the longest substring without repeating characters in \"pwwkew\": " 
        << solution.lengthOfLongestSubstring(s3) << endl;
    
    return 0;
}
    