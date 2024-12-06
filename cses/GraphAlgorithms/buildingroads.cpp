#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> bss;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for(auto v : bss[u])
        if(!visited[v]) dfs(v);
}

int main(){
    int n, m; cin >> n >> m;
    int u, v;
    bss.resize(n);
    visited.resize(n, false);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        bss[u-1].push_back(v-1);
        bss[v-1].push_back(u-1);
    }
    int ncomps = 1;
    dfs(0);
    vector<pair<int, int>> edgestoadd;
    int last = 0;
    for(int i = 1; i < n; i++){
        if(!visited[i]){
            dfs(i);
            ncomps++;
            edgestoadd.push_back(make_pair(last, i));
            last = i;
        }
    }
    cout << ncomps-1 << endl;
    for(auto e : edgestoadd) cout << e.first+1 << ' ' << e.second+1 << endl;
}
