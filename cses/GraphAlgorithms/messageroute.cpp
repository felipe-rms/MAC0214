#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    fastio;
    ll t = 1;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> adj(n);
        while (m--) {
            ll x, y;
            cin >> x >> y;
            x--; y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<ll> visited(n, 0);
        vector<ll> parent(n, -1);
        queue<ll> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            ll curr = q.front();
            q.pop();
            for (ll neighbor : adj[curr]) {
                if (visited[neighbor]) continue;
                q.push(neighbor);
                visited[neighbor] = 1;
                parent[neighbor] = curr;
            }
        }

        if (!visited[n - 1]) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        vector<ll> path;
        for (ll cur = n - 1; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for (ll node : path) {
            cout << node + 1 << " ";
        }
    }
}

