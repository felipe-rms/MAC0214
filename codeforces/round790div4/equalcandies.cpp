#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int min = 100000000;
    long long come = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < min) min = a[i];
    }
    for(int i = 0; i < n; i++)
        come += a[i] - min;
    cout << come << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}
