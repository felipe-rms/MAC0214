#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) cin >> x;

    long long sum = 0;
    long long cnt = 0;
    bool open = false;

    for (long long x : a) {
        sum += abs(x);
        if (x < 0 && !open) {
            open = true;
            cnt++;
        }
        if (x > 0) {
            open = false;
        }
    }

    cout << sum << " " << cnt << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

