#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, y, k; cin >> x >> y >> k;
    int xj = x/k; if(x%k) xj++;
    int yj = y/k; if(y%k) yj++;
    if(xj > yj) cout << xj*2-1 << endl;
    else cout << yj*2 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
