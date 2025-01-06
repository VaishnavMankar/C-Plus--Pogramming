//9.Palindrome Number
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};

int main(){
    Solution solution;
    int x = 121;
    bool ans = solution.isPalindrome(x);
    cout <<"palindrom: " << ans << endl;
    return 0;
}