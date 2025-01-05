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

        for(int g : gain){
            currentAltitude += g;
            highestAltitude = max(highestAltitude, currentAltitude);
        }
        return highestAltitude;
    }
};

int main(){
    Solution solution;
    //test case
    vector<int> gain = {-5,1,5,0,-7};
    int result = solution.largestAltitude(gain);
    cout << "Highest altitude: " << result << endl;

    return 0;
}