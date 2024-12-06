#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector<tuple<int, int, int>> EV;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            EV.emplace_back(a, b, 1);
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            EV.emplace_back(a, b, 0);
        }

        sort(EV.begin(), EV.end());
        int k = 1;
        priority_queue<int> pwr;

        for (auto &[a, b, t] : EV) {
            if (t == 0) {
                pwr.push(-b);
            } else {
                while (!pwr.empty() && k < b - a + 2) {
                    k -= pwr.top();
                    pwr.pop();
                }
                if (k < b - a + 2) {
                    cout << -1 << endl;
                    goto next_case;
                }
            }
        }

        cout << m - pwr.size() << endl;
    next_case:;
    }
    return 0;
}

