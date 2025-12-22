#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n = 5; // number of energy nodes (microgrids)
    vector<vector<int>> cost = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> key(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    key[0] = 0;

    for (int count = 0; count < n-1; count++) {
        int u = -1;
        int minKey = numeric_limits<int>::max();
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (cost[u][v] && !inMST[v] && cost[u][v] < key[v]) {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in the Minimum Spanning Tree for Microgrid:\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << " (Cost: " << cost[i][parent[i]] << ")\n";

    return 0;
}
