// Problem: https://www.acmicpc.net/problem/11724
// Title: Connected Components
// Algorithm: Depth-First Search (DFS)
// Description:
// Count the number of connected components in an undirected graph.
// Each connected component is a group of nodes where each pair is reachable via some path.

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;  // Number of nodes and edges
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected edge
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
