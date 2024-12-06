#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> dp(x+1);
    dp[0].resize(n, 1);
    for(int i = 1; i <= x; i++){
        dp[i].resize(n, 0);
        if(i%c[0] == 0) dp[i][0] = 1;
    }
    for(int i = 1; i <= x; i++)
        for(int j = 1; j < n; j++)
            for(int k = 0; 0 <= i-k*c[j]; k++)
                dp[i][j] = (dp[i][j] + dp[i-k*c[j]][j-1])%MOD;

    printf("MATRIZ DP:\n");
    for(int i = 0; i <= x; i++){
        for(int j = 0; j < n; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }

    cout << dp[x][n-1] << endl;
}
