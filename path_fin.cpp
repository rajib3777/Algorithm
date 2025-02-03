#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj_list(n);
        vector<bool> vis(n, false);  // Use vector<bool> to avoid global memory issues

        // Step 1: Build adjacency list
        for(auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // Step 2: Perform BFS
        return bfs(source, destination, adj_list, vis);
    }

private:
    bool bfs(int source, int destination, vector<vector<int>>& adj_list, vector<bool>& vis) {
        queue<int> q;
        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int par = q.front();
            q.pop();

            // Step 3: Check if we reached the destination
            if (par == destination) {
                return true;
            }

            // Step 4: Traverse all unvisited neighbors
            for (int child : adj_list[par]) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }

        return false;  // If BFS completes without finding destination
    }
};

// Main function to run the program
int main() {
    int n, m;
    cout << "Enter number of nodes (n) and edges (m): ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    Solution solution;
    bool result = solution.validPath(n, edges, source, destination);

    cout << "Path exists: " << (result ? "true" : "false") << endl;

    return 0;
}
