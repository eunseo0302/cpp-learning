// Problem: https://www.acmicpc.net/problem/1697
// Title: Hide and Seek
// Algorithm: Breadth-First Search (BFS)
// Description:
// Given two positions x and y on a 1D number line (0 <= x, y <= 100000),
// find the minimum time (in seconds) to move from x to y using the following rules:
// - x-1, x+1, or x*2 per move, each taking 1 second.
// Output the minimum time to reach y from x.

#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];  // Tracks whether a position has been visited

void bfs(int x, int y) {
    if (x == y) {
        cout << 0 << '\n';
        return;
    }

    queue<pair<int, int>> q;  // {position, time_elapsed}
    q.push({x, 0});
    visited[x] = true;

    while (!q.empty()) {
        auto [curr, time] = q.front();
        q.pop();

        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (next >= 0 && next <= 100000 && !visited[next]) {
                if (next == y) {
                    cout << time + 1 << '\n';
                    return;
                }
                visited[next] = true;
                q.push({next, time + 1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    bfs(x, y);

    return 0;
}
