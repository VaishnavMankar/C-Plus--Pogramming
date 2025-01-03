//1051.Height Checker
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    int heightChecker(vector<int>& heights){
        vector<int> sorted_heights = heights;// making the copy of original
        sort(sorted_heights.begin(),sorted_heights.end());//sort the copy 
        // this comand is an inbuild function 
        int count = 0;
        for(int i = 0; i < heights.size(); i++){
            if(heights[i] != sorted_heights[i]){
                count ++;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;

    vector<int> heights = {1, 1, 4, 2, 1, 3};
    int result = solution.heightChecker(heights);
    cout << "Number of student in incorrect position: " << result << endl;

    return 0;
}