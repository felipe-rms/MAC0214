#include <bits/stdc++.h>
using namespace std;

int diff(string &r, string &s){
    int d = 0;
    for(int i = 0; i < r.size(); i++) d+=abs(r[i]-s[i]);
    return d;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int res = diff(s[0], s[1]);
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            res = min(res, diff(s[i], s[j]));
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
