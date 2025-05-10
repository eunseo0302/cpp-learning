#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> height(9);

    for (int i = 0; i < 9; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            int sum = 0;
            vector<int> selected;

            for (int k = 0; k < 9; k++) {  // 여기 수정
                if (k != i && k != j) {
                    selected.push_back(height[k]);
                    sum += height[k];
                }
            }

            if (sum == 100) {
                sort(selected.begin(), selected.end());
                for (int h : selected) {
                    cout << h << '\n';
                }
                return 0;
            }
        }
    }
}
