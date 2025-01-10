//1732. Find the Highest Altitude
#include<iostream>
#include<vector>
#include<algorithm> // for max
using namespace std;

class Solution{
    public:
    int largestAltitude(vector<int>& gain){
        int currentAltitude = 0; 
        int highestAltitude = 0; 
        int sz = gain.size(); 
        for(int i = 0; i < sz; i++){ 
            currentAltitude += gain[i]; 
            if(currentAltitude > highestAltitude){ 
              highestAltitude = currentAltitude;
            }
        }
        return highestAltitude;
    }
};

int main(){
    Solution solution;
    //test case
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    int result = solution.largestAltitude(gain);
    cout << "Highest altitude: " << result << endl;

    return 0;
}