#include <bits/stdc++.h>
using namespace std;

int mymin(int a, int b){
    return (a < b) ? a : b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
//    sort(c.begin(), c.end());
    vector<vector<int>> dp(x+1);
    dp[0].resize(n, 0);
    for(int i = 1; i <=x; i++) dp[i].resize(n, x+1);
    for(int i = 0; i <= x; i++)
        if(i%c[0] == 0) dp[i][0] = i/c[0];
    for(int i = 1; i <= x; i++){
        for(int j = 1; j < n; j++){
            if(0 <= i-c[j]){
                dp[i][j] = mymin(dp[i-c[j]][j]+1, dp[i][j-1]);
            }
            else dp[i][j] = dp[i][j-1];
        }
    }

//    printf("MATRIZ DP:\n");
//    for(int i = 0; i <= x; i++){
//        for(int j = 0; j < n; j++)
//            cout << dp[i][j] << ' ';
//        cout << endl;
//    }

    if(dp[x][n-1] > x) cout << -1 << endl;
    else cout << dp[x][n-1] << endl;
}
