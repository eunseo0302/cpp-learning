#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(); // 개행 문자 제거

    vector<long long> numbers;
    string line;
    int count = 0;

    while (count < n && getline(cin, line)) {
        stringstream ss(line);
        string token;
        while (ss >> token && count < n) {
            reverse(token.begin(), token.end());
            numbers.push_back(stoll(token));
            count++;
        }
    }

    sort(numbers.begin(), numbers.end());

    for (const auto& num : numbers) {
        cout << num << '\n';
    }

    return 0;
}
