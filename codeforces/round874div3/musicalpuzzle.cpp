#include <iostream>
#include <set>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> pairs;
    for (int i = 1; i < n; ++i) {
        pairs.insert(s.substr(i - 1, 2));
    }
    cout << pairs.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

