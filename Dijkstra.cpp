#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Dijkstra {
private:
    vector<int> dist, path;
    vector<bool> visited;
public:
    Dijkstra(int n) {
        dist.resize(n);
        path.resize(n);
        visited.resize(n, false);
    }

    void initialise(vector<vector<int>>& cost, int source) {
        int n = cost.size();
        for (int i = 0; i < n; i++) {
            dist[i] = (cost[source][i] == 0) ? numeric_limits<int>::max() : cost[source][i];
            path[i] = source;
        }
        dist[source] = 0;
        visited[source] = true;
    }

    int minimum() {
        int mini = numeric_limits<int>::max();
        int idx = -1;
        for (int i = 0; i < dist.size(); i++) {
            if (!visited[i] && dist[i] < mini) {
                mini = dist[i];
                idx = i;
            }
        }
        return idx;
    }

    void update(vector<vector<int>>& cost) {
        int u = minimum();
        if (u == -1) return;
        visited[u] = true;
        for (int i = 0; i < cost.size(); i++) {
            if (!visited[i] && cost[u][i] != 0) {
                if (dist[u] + cost[u][i] < dist[i]) {
                    dist[i] = dist[u] + cost[u][i];
                    path[i] = u;
                }
            }
        }
    }

    void shortestPath(vector<vector<int>>& cost, int source) {
        initialise(cost, source);
        for (int i = 0; i < cost.size() - 1; i++) update(cost);
    }

    void printPaths(int source) {
        for (int i = 0; i < dist.size(); i++) {
            if (i != source) {
                cout << "Shortest path from hub " << source << " to hub " << i 
                     << " (cost: " << dist[i] << "): ";
                int j = i;
                cout << j;
                while (path[j] != source) {
                    cout << " <- " << path[j];
                    j = path[j];
                }
                cout << " <- " << source << endl;
            }
        }
    }
};

int main() {
    vector<vector<int>> cost = {
        {0, 10, 0, 30},
        {10, 0, 20, 0},
        {0, 20, 0, 15},
        {30, 0, 15, 0}
    };
    int sourceHub = 0;

    Dijkstra dj(4);
    dj.shortestPath(cost, sourceHub);
    dj.printPaths(sourceHub);

    return 0;
}
