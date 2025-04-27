//9171. Fins if Path Exist in Graph
//Graph

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Depth-First Search (DFS) function to check if a path exists
    bool dfs(int current, int destination, vector<vector<int>>& adj, vector<bool>& visited){
        if(current == destination){
            return true; // If we reach the destination, return true
        }
        visited[current] = true; // Mark current node as visited

        for(int neighbor : adj[current]){
            if(!visited[neighbor]){
                if(dfs(neighbor, destination, adj, visited)){
                    return true; // If any recursive call finds a path, return true
                }
            }
        }
        return false; // No valid path found
    }

    // Function to check if there is a valid path in the graph
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        
        // Build adjacency list representation of the graph
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false); // Initialize visited array
        return dfs(source, destination, adj, visited); // Start DFS search
    }
};

int main() {
    // Example test cases
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1},{1,2},{2,0}};
    int source1 = 0, destination1 = 2;

    int n2 = 6;
    vector<vector<int>> edges2 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int source2 = 0, destination2 = 5;

    Solution solution;

    // Checking paths for both test cases
    cout << "Is there a path from " << source1 << " to " << destination1 << "? "
         << (solution.validPath(n1, edges1, source1, destination1) ? "Yes" : "No") << endl;

    cout << "Is there a path from " << source2 << " to " << destination2 << "? "
         << (solution.validPath(n2, edges2, source2, destination2) ? "Yes" : "No") << endl;

    return 0;
}
