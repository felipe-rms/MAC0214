#include <bits/stdc++.h>
using namespace std;

void BFS(vector<vector<char>> &M, pair<int, int> begin, pair<int, int> end, int n, int m){
    list<pair<int, int>> queue;
    queue.push_back(begin);
    while(!queue.empty()){
        auto at = queue.front();
        queue.pop_front();
        if(at.first == end.first && at.second == end.second) return;
        if(0 < at.first && (M[at.first-1][at.second] == '.' || M[at.first-1][at.second] == 'B')){
            M[at.first-1][at.second] = 'U';
            queue.push_back(make_pair(at.first-1, at.second));
        }
        if(at.first < n-1 && (M[at.first+1][at.second] == '.' || M[at.first+1][at.second] == 'B')){
            M[at.first+1][at.second] = 'D';
            queue.push_back(make_pair(at.first+1, at.second));
        }
        if(0 < at.second && (M[at.first][at.second-1] == '.' || M[at.first][at.second-1] == 'B')){
            M[at.first][at.second-1] = 'L';
            queue.push_back(make_pair(at.first, at.second-1));
        }
        if(at.second < m-1 && (M[at.first][at.second+1] == '.' || M[at.first][at.second+1] == 'B')){
            M[at.first][at.second+1] = 'R';
            queue.push_back(make_pair(at.first, at.second+1));
        }
    }
}
int main(){
    int n, m; cin >> n >> m;
    vector<vector<char>> M(n);
    pair<int, int> begin, end;
    for(int i = 0; i < n; i++){
        M[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> M[i][j];
            if(M[i][j] == 'A'){
                begin.first = i; begin.second = j;
            }
            else if(M[i][j] == 'B'){
                end.first = i; end.second = j;
            }
        }
    }
    //printf("LEU M:\n");
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++)
//            cout << M[i][j];
//        cout << endl;
//    }
    BFS(M, begin, end, n, m);
    //cout << "FEZ BFS\n";
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < m; j++)
//            cout << M[i][j];
//        cout << endl;
//    }

    if(M[end.first][end.second] == 'B'){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    list<char> path;
    while(M[end.first][end.second] != 'A'){
        path.push_front(M[end.first][end.second]);
        switch(M[end.first][end.second]){
            case 'L':
                end.second++;
                break;
            case 'R':
                end.second--;
                break;
            case 'U':
                end.first++;
                break;
            case 'D':
                end.first--;
                break;
        }
    }
    cout << path.size() << endl;
    //cout << "CONSTRUIU O PATH\n";
    while(!path.empty()){
        cout << path.front();
        path.pop_front();
    }
    cout << endl;
}
