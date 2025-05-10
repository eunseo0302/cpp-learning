#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coordinate {
    int x;
    int y;
};

bool compare (const Coordinate& a, const Coordinate& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Coordinate> coords;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        coords.push_back({a, b});
    }
    
    sort(coords.begin(), coords.end(), compare);
    
    for (const auto& p : coords) {
        cout << p.x << " " << p.y << '\n';
    }
    
    return 0;
}
