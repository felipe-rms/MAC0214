#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long powerof(long long a, long long b, long long mod){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long res = powerof(a, b/2, mod);
    res = (res * res)%mod;
    if(b % 2) res = (res * a)%mod;
//    printf("%lld^%lld = %lld\n", a, b, res);
    return res%mod;
}

long long myexp(long long a, long long b, long long c){
    long long e = powerof(b, c, MOD-1);
    //cout << "e = " << e << endl;
    return powerof(a, e, MOD);
}


int main(){
    int n; cin >> n;
    long long a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        cout << myexp(a, b, c) << endl;
    }
}
