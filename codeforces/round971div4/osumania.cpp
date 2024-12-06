#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    list<int> s;
    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> c;
            if(c == '#')
                s.push_front(j+1);
        }
    }
    for (auto i : s) cout << i << ' ';
    cout << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
