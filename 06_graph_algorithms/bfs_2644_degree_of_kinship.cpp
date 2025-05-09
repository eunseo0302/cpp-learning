// Problem: https://www.acmicpc.net/problem/2644
// Title: Degree of Kinship
// Algorithm: Breadth-First Search (BFS)
// Description:
// Given a family relationship graph, find the degree of kinship between two people.
// If they are not connected, return -1.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[101];     // Adjacency list
bool visited[101];        // Visited nodes tracker

int bfs(int start, int target) {
    queue<pair<int, int>> q;  // pair<current node, degree>
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front().first;
        int degree = q.front().second;
        q.pop();

        if (curr == target) return degree;

        for (int next : adj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, degree + 1});
            }
        }
    }

    return -1;  // No connection found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, m;
    cin >> n >> a >> b >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);  // Undirected edge
    }

    cout << bfs(a, b) << '\n';

    return 0;
}
