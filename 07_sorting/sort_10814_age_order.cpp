#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Member {
    string name;
    int age;
};

bool compare (const Member& a, const Member& b) {
    return a.age < b.age;
}

int main() {
    int n;
    cin >> n;
    vector<Member> v;
    
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cin >> age >> name;
        
        v.push_back(Member{name, age});
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for (const auto& p : v) {
        cout << p.age << " " << p.name << endl;
    }
    
    return 0;
}
