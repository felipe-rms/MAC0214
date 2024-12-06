#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a, b; a = b = 0;
    for(int i = 0; i < 3; i++){
        a += n % 10;
        n /= 10;
    }
    for(int i = 0; i < 3; i++){
        b += n % 10;
        n /= 10;
    }
    if(a == b) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
