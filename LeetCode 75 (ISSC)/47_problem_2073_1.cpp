//2073. Time Needed to Buy Tickets
//Queue
//self 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>  q;
        for(int i = 0; i < tickets.size(); i++) q.push(i);

        int timeNeeded = 0;
        while(!q.empty()){
            timeNeeded++;

            int idFront = q.front();
            q.pop();
            tickets[idFront]--;

            if(k == idFront && tickets[idFront] == 0) return timeNeeded;
            if(tickets[idFront] != 0) q.push(idFront);
        }
        return timeNeeded;
    }
};

int main() {
    Solution solution;
    
    vector<int> tickets = {2, 3, 2};  // Example values
    int k = 2;
    
    int result = solution.timeRequiredToBuy(tickets, k);
    cout << "Time required to buy ticket for person at position " << k << " is: " << result << " units of time." << endl;

    return 0;
}
