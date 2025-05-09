// Problem: https://www.acmicpc.net/problem/2178
// Title: Maze Exploration
// Algorithm: Breadth-First Search (BFS)
// Description:
// Given a 2D grid representing a maze of 0s (walls) and 1s (paths),
// find the shortest path from the top-left corner to the bottom-right corner,
// moving only in four directions (up, down, left, right).

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int maze[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};   // right, left, down, up
int dy[4] = {1, -1, 0, 0};

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            // Check boundary and if it's a path (1) and unvisited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && maze[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    maze[nx][ny] = maze[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return maze[n - 1][m - 1];  // Return distance to bottom-right corner
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < m; ++j) {
            maze[i][j] = row[j] - '0';  // Convert char to int
        }
    }

    cout << bfs(0, 0) << '\n';

    return 0;
}
