#include <bits/stdc++.h>
using namespace std;

int main(){
    long long unsigned n; cin >> n;
    cout << n << " ";
    while(n != 1){
        if(n % 2){
            n = n*3+1;
            cout << n << " ";
        }
        else{
            n/=2;
            cout << n << " ";
        }
    }
    cout << "\n";
}
