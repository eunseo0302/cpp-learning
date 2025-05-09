// Problem: https://www.acmicpc.net/problem/7562
// Title: Knight's Move
// Algorithm: Breadth-First Search (BFS)
// Description:
// Given a chessboard of size n x n, calculate the minimum number of moves
// a knight needs to move from (x, y) to (u, v). Up to 100 test cases.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[301][301];
bool visited[301][301];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void bfs(int x, int y, int n, int u, int v) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    if (x == u && y == v) {
        cout << 0 << '\n';
        return;
    }

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[ny][nx]) {
                    visited[ny][nx] = true;
                    map[ny][nx] = map[curr.second][curr.first] + 1;
                    if (nx == u && ny == v) {
                        cout << map[ny][nx] << '\n';
                        return;
                    }
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y, u, v;
        cin >> n >> x >> y >> u >> v;
        bfs(x, y, n, u, v);
    }

    return 0;
}
