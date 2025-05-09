// Problem: https://www.acmicpc.net/problem/2606
// Title: Virus
// Algorithm: Depth-First Search (DFS)
// Description:
// Given a network of computers, count how many computers will be infected by a virus starting from computer 1.
// The graph is undirected, and each edge represents a direct connection between two computers.

#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101];
bool visited[101];
int cnt = 0;

void dfs(int node) {
    visited[node] = true;
    cnt++;
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected edge
    }

    dfs(1);
    cout << cnt - 1 << '\n';  // Exclude the initially infected computer

    return 0;
}
