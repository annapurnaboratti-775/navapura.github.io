#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS to detect connected components or blockages
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << "Visited node: " << node << endl;
    for (int v : adj[node]) {
        if (!visited[v]) DFS(v, adj, visited);
    }
}

// BFS to detect connectivity or leaks
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
    int n = 6; // number of sewage nodes
    vector<vector<int>> adj(n);

    // Example network edges
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1, 4};
    adj[4] = {3, 5};
    adj[5] = {4};

    cout << "DFS Traversal of sewage network:\n";
    vector<bool> visited(n, false);
    DFS(0, adj, visited);

    cout << "\nBFS Traversal of sewage network:\n";
    fill(visited.begin(), visited.end(), false);
    BFS(0, adj, visited);

    return 0;
}
