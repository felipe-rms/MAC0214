#include <bits/stdc++.h>
using namespace std;

void pinta(vector<vector<char>> &M, int i, int j, int n, int m){
        if(0 <= i && i < n && 0 <= j && j < m){
            if(M[i][j] == '.'){
                M[i][j] = '#';
                //printf("pintou M[%d][%d]\n", i, j);
                pinta(M, i+1, j, n, m); pinta(M, i-1, j, n, m);
                pinta(M, i, j+1, n, m); pinta(M, i, j-1, n, m);
            }
        }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<char>> M(n);
    for(int i = 0; i < n; i++){
        M[i].resize(m);
        for(int j = 0; j < m; j++)
            cin >> M[i][j];
    }
//    cout << "LEU M\n";
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++)
//            cout << M[i][j];
//        cout << endl;
//    }
    int nrooms = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(M[i][j] == '.'){
                nrooms++;
                //cout << "ACHOU ESPAÇO EM " << i << ", " << j << endl;
                pinta(M, i, j, n, m);
            }
    cout << nrooms << endl;
}

