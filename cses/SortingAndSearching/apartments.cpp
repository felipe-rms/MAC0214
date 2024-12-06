#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, k; cin >> n >> m >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<long long> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    //cout << "sortou tudo\n";
    int i, j;
    i = j = 0;
    int cont = 0;
    while(i < n && j < m){
        if(a[i] < b[j]-k) i++;
        else if(a[i] > b[j]+k) j++;
        else{
            i++; j++; cont++;
        }
    }
    cout << cont << endl;

}
