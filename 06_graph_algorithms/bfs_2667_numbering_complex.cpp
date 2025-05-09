// Problem: https://www.acmicpc.net/problem/2667
// Title: Numbering Housing Complexes
// Algorithm: Breadth-First Search (BFS)
// Description:
// Given a binary 2D grid representing houses (1) and empty land (0),
// count the number of connected housing complexes (4-directional adjacency),
// and print the size of each complex in ascending order.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[26][26];
bool visited[26][26];

int dx[4] = {0, 0, 1, -1};   // right, left, down, up
int dy[4] = {1, -1, 0, 0};

// Perform BFS from (x, y), return size of connected component
int bfs(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    int cnt = 1;

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (!visited[ny][nx] && map[ny][nx] == 1) {
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> complex_sizes;

    // Input the map
    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < n; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    int total_complexes = 0;

    // Scan all cells to find starting points for BFS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                int size = bfs(j, i, n);
                complex_sizes.push_back(size);
                total_complexes++;
            }
        }
    }

    // Output total number of complexes
    cout << total_complexes << '\n';

    // Sort and output sizes in ascending order
    sort(complex_sizes.begin(), complex_sizes.end());
    for (int size : complex_sizes) {
        cout << size << '\n';
    }

    return 0;
}
