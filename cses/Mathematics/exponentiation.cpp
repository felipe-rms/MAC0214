#include <bits/stdc++.h>
using namespace std;

long long unsigned MOD = 1e9+7;

long long unsigned myexp(long long a, long long b){
    if(b == 1) return a;
    if(b == 0) return 1;
    long long unsigned res = myexp(a, b/2)%MOD;
    res = (res*res)%MOD;
    if(b % 2) res = (res*a)%MOD;
    return res%MOD;
}

int main(){
    int n; cin >> n;
    long long unsigned a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << myexp(a, b) << endl;
    }
}

