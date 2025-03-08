// 933. Number of Recent cells

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> Q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        Q.push(t);
        
        int temp = t - 3000;
        while(Q.front() < temp)
            Q.pop();
        
        return Q.size();
    }
};

int main() {
    // Create an instance of RecentCounter class
    RecentCounter recentCounter;

    // Test the ping function with different inputs
    cout << recentCounter.ping(1) << endl;    // Output: 1
    cout << recentCounter.ping(100) << endl;  // Output: 2
    cout << recentCounter.ping(3001) << endl; // Output: 3
    cout << recentCounter.ping(3002) << endl; // Output: 3

    return 0;
}
