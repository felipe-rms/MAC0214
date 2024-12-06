#include <bits/stdc++.h>
using namespace std;

struct Info {
    int mn_suf = 0, mx_suf = 0;
    int mn_ans = 0, mx_ans = 0;
};

void solve() {
    int n;
    cin >> n;

    vector<Info> st;
    Info start;
    start.mx_suf = start.mx_ans = 1;
    st.push_back(start);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "+") {
            int v, x;
            cin >> v >> x;
            v--; // ajustar para índice 0

            Info pref = st[v];
            Info cur;

            cur.mn_suf = min(0, pref.mn_suf + x);
            cur.mx_suf = max(0, pref.mx_suf + x);
            cur.mn_ans = min(pref.mn_ans, cur.mn_suf);
            cur.mx_ans = max(pref.mx_ans, cur.mx_suf);

            st.push_back(cur);
        } else {
            int v, x;
            cin >> v >> x;
            v--; // ajustar para índice 0

            if (st[v].mn_ans <= x && x <= st[v].mx_ans) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

