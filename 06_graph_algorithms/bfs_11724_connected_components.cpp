// Problem: https://www.acmicpc.net/problem/11724
// Title: Connected Components
// Algorithm: Breadth-First Search (BFS)
// Description:
// Count the number of connected components in an undirected graph using BFS.
// A component is a maximal set of nodes that are reachable from each other.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void bfs(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
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
            bfs(i);
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
