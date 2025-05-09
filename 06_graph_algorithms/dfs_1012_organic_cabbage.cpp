// Problem: https://www.acmicpc.net/problem/1012
// Title: Organic Cabbage
// Algorithm: Depth-First Search (DFS)
// Description:
// Given a 2D field with cabbage locations, count how many disconnected cabbage clusters exist.
// A worm is needed per cluster (connected component), so the goal is to count the number of worms.

#include <iostream>
using namespace std;

int field[51][51];
bool visited[51][51];

int dx[4] = {0, 0, -1, 1};  // left, right, up, down
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int m, int n) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Valid coordinates, unvisited, and contains cabbage
        if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
            field[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(nx, ny, m, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int m, n, k;
        cin >> m >> n >> k;

        // Reset arrays
        for (int i = 0; i < 51; i++) {
            for (int j = 0; j < 51; j++) {
                field[i][j] = 0;
                visited[i][j] = false;
            }
        }

        // Input cabbage locations
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int wormCount = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (field[y][x] == 1 && !visited[y][x]) {
                    dfs(x, y, m, n);
                    wormCount++;
                }
            }
        }

        cout << wormCount << '\n';
    }

    return 0;
}
