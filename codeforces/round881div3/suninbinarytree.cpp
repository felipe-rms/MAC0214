#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long s = 0;
    while (n >= 1) {
        s += n;
        n /= 2;
    }
    cout << s << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

