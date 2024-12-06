#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    int lr = 1;
    int cr = 1;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1]){
            cr++;
            if(cr > lr) lr = cr;
        }
        else
            cr = 1;
    }
    cout << lr << endl;
}

