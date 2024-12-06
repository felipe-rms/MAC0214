#include <bits/stdc++.h>
using namespace std;

int main(){
    int a; 
    int t; cin >> t;
    while(t--){
        cin >> a;
        int x = a % 10;
        a /= 10;
        cout << a + x << endl;
    }
}
