#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    sort(s.begin(), s.end());
    cout << (int)(s[s.size()-1] - 'a')+1 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
