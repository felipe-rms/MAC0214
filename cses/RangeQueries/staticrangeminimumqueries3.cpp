#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 200000;
vector<int> segtree(4 * MAXN, -1);
vector<int> x;

// Função para calcular o mínimo com condições adicionais
int mymin(int a, int b) {
    if (a < 0) return b;
    if (b < 0) return a;
    return min(a, b);
}

// Função para calcular o ponto médio
int mid(int a, int b) {
    return (a + b) / 2;
}

// Função para construir a árvore segmentada
int buildtree(int left, int right, int node) {
    if (left == right) {
        segtree[node] = x[left];
        return x[left];
    } else {
        int midPoint = mid(left, right);
        segtree[node] = mymin(buildtree(left, midPoint, 2 * node + 1),
                              buildtree(midPoint + 1, right, 2 * node + 2));
        return segtree[node];
    }
}

// Função para realizar consultas na árvore segmentada
int query(int a, int b, int na, int nb, int node) {
    if (a <= na && b >= nb) {
        return segtree[node];
    } else if (b < na || nb < a) {
        return -1;
    } else {
        int midPoint = mid(na, nb);
        return mymin(query(a, b, na, midPoint, 2 * node + 1),
                     query(a, b, midPoint + 1, nb, 2 * node + 2));
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    // Construindo a árvore segmentada
    buildtree(0, n - 1, 0);

    // Realizando as consultas
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b - 1, 0, n - 1, 0) << endl;
    }

    return 0;
}

