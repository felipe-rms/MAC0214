#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
vector<long long> dp;

long long calcula(int n){
    if(dp[n]) return dp[n];
    for(int m = n-1; m >= 0 && n-m<=6; m--)
        dp[n] = (dp[n] + calcula(m))%MOD;
    return dp[n];
}

int main(){
    int n; cin >> n;
    dp.resize(n+1, 0);
    dp[0] = 1;
    cout << calcula(n) << endl;
//    for(int i = 0; i <= n; i++)
//        cout << dp[i] << ' ';
    cout << endl;
}
