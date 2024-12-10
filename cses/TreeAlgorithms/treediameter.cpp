#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];
int distance_from_root[MAXN];

void find_distances(int current, int parent) {
    for (int neighbor : tree[current]) {
        if (neighbor != parent) {
            distance_from_root[neighbor] = distance_from_root[current] + 1;
            find_distances(neighbor, current);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nodes = 5;

    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};

    for (const auto& edge : edges) {
        int u = edge.first, v = edge.second;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    distance_from_root[1] = 0;
    find_distances(1, -1);
    int farthest_node = 1;
    for (int i = 1; i <= nodes; i++) {
        if (distance_from_root[i] > distance_from_root[farthest_node]) {
            farthest_node = i;
        }
    }

    fill(distance_from_root, distance_from_root + nodes + 1, 0);
    find_distances(farthest_node, -1);
    int tree_diameter = *max_element(distance_from_root + 1, distance_from_root + nodes + 1);

    cout << tree_diameter << "\n";

    return 0;
}

