#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<array<int, 2>> p(n+1, {{0, 0}});
    int x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        p[x][y] = 1;
    }
    long long nr = 0;
    for(int i = 0; i <= n; i++){
        if(p[i][0] && p[i][1]) nr+=(n-2);
        if(0 < i && i < n){
            if(p[i][0] && p[i-1][1] && p[i+1][1]) nr++;
            if(p[i][1] && p[i-1][0] && p[i+1][0]) nr++;
        }
    }
    cout << nr << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}
