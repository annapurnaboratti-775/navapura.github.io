#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS to check connectivity of water network graph
void BFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << "Visited node: " << u << endl;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 5; // number of nodes (households/facilities)
    vector<vector<int>> adj(n);

    // Example water network edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(n, false);

    cout << "BFS traversal of the water network starting from node 0:\n";
    BFS(0, adj, visited);

    return 0;
}
