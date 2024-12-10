#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long
const ll INF = 1e12;
const ll MX = 2e5 + 5;

vector<ll> Adj[MX];
ll dp[2][MX];

void DFS(ll u, ll p) {
    dp[0][u] = 0;
    dp[1][u] = -INF;

    for (ll v : Adj[u]) {
        if (v == p) continue;

        DFS(v, u);

        dp[0][u] += max(dp[1][v], dp[0][v]);
        ll opt = min(dp[0][v] - dp[1][v], 0LL);
        dp[1][u] = max(dp[1][u], opt);
    }

    dp[1][u] += dp[0][u];
    dp[1][u]++;
}

int main() {
    ll n = 10;
    ll edges[][2] = { {5, 8}, {4, 6}, {9, 1}, {10, 4}, {1, 3}, {2, 3}, {7, 9}, {6, 2}, {5, 10} };

    for (ll i = 0; i < n - 1; ++i) {
        ll a = edges[i][0] - 1;
        ll b = edges[i][1] - 1;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    DFS(0, -1);

    ll ans = max(dp[0][0], dp[1][0]);
    cout << ans << endl;

    return 0;
}

