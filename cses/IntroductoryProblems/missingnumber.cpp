#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<bool> presente(n, false);
    int at;
    for(int i = 0; i < n-1; i++){
        cin >> at;
        presente[at-1] = true;
    }
    for(int i = 0; i < n; i++){
        if(!presente[i]){
            cout << i+1 << "\n";
            return 0;
        }
    }
}
