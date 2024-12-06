#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    long long ant, at, s;
    ant = s = 0;
    for(int i = 0; i < n; i++){
        cin >> at;
        if(at < ant){
            s += ant-at;
            at = ant;
        }
        ant = at;
    }
    cout << s << endl;
}

