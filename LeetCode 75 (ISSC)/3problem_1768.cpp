//1768.Merge Strings Alternately.
#include<iostream>
#include<string>
//#include<algorithm>
using namespace std;

class Solution{
    public:
    string mergeAlternately(string word1, string word2){
        string ans;
        int i = 0, j = 0;
        
        //merge alternately
        while(i < word1.length() && j < word2.length()){
            ans += word1[i++];
            ans += word2[j++];
        }
        //add remaining characters
        while(i < word1.length()){
            ans += word1[i++];
        }
        while(j < word2.length()){
            ans += word2[j++];
        }
        return ans;
    }
};

int main(){
    Solution solution;

    string word1 = "abc";
    string word2 = "pqr";
    string ans = solution.mergeAlternately(word1,word2);
    cout << "Merge string: " << ans << endl;
    
    return 0;
}