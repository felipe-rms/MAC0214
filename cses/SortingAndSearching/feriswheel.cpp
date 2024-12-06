#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x; cin >> n >> x;
    vector<long long> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int ng = 0;
    int i = 0;
    int j = 0;
    while(i+j < n){
        if(p[i] + p[n-1-j] <= x){
            //printf("coube criança %lld e %lld\n", p[i], p[j]);
            i++; j++; ng++;
        }
        else{
            //printf("criança %lld sozinha\n", p[i]);
            j++; ng++;
        }

    }
    cout << ng << endl;
}
