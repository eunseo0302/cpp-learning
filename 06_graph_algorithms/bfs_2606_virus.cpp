// Problem: https://www.acmicpc.net/problem/2606
// Title: Virus
// Algorithm: Breadth-First Search (BFS)
// Description:
// Starting from computer 1, count how many computers get infected through direct/indirect connections.
// The graph is undirected.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];
bool visited[101];

void bfs(int start) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    int count = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++;

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << count - 1 << '\n';  // Exclude the initially infected computer
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

    bfs(1);

    return 0;
}
