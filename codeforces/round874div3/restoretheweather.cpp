#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> values(n);
    vector<int> b(n), result(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> values[i].first;
        values[i].second = i;
    }
    for (int &x : b) cin >> x;

    sort(values.begin(), values.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        result[values[i].second] = b[i];
    }

    for (int x : result) cout << x << " ";
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

