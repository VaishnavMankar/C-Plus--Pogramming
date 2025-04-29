//785. Is Graph Bipartite?
//Graph

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for(int v : graph[u]) {
                        if(color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if(color[v] == color[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

// Function to print the graph adjacency list
void printGraph(const vector<vector<int>>& graph) {
    cout << "Graph adjacency list:\n";
    for (int i = 0; i < graph.size(); i++) {
        cout << i << ": ";
        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example test cases
    vector<vector<int>> graph1 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> graph2 = {{1,3},{0,2},{1,3},{0,2}};

    Solution solution;

    // Print test case details
    cout << "Test Case 1:\n";
    printGraph(graph1);
    cout << "Is the graph bipartite? " << (solution.isBipartite(graph1) ? "Yes" : "No") << endl;

    cout << "\nTest Case 2:\n";
    printGraph(graph2);
    cout << "Is the graph bipartite? " << (solution.isBipartite(graph2) ? "Yes" : "No") << endl;

    return 0;
}
