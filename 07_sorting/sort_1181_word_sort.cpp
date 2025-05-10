#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> v;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        v.push_back(word);
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());

    for (const auto& p : v) {
        cout << p << '\n';
    }

    return 0;
}
