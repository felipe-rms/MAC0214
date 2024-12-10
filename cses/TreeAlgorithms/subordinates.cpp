#include <bits/stdc++.h>
using namespace std;

const int MAXN = 202020;

vector<vector<int>> tree(MAXN);
vector<int> subtree_size(MAXN, 0);

int calculateSubtreeSize(int node) {
    if (tree[node].empty()) {
        return 1; 
    }

    for (int child : tree[node]) {
        subtree_size[node] += calculateSubtreeSize(child);
    }

    return subtree_size[node] + 1; 
}

int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }
    calculateSubtreeSize(1);

    for (int i = 1; i <= n; i++) {
        cout << subtree_size[i] << " ";
    }
    cout << endl;

    return 0;
}

