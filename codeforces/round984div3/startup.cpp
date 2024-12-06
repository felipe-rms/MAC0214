#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findMaxCost() {
    int n, k;
    cin >> n >> k;
    vector<int> costs(k, 0);
    for (int i = 0; i < k; ++i) {
        int brand, cost;
        cin >> brand >> cost;
        costs[brand - 1] += cost;
    }
    sort(costs.begin(), costs.end(), greater<int>());
    long long total = 0;
    for (int i = 0; i < min(n, k); ++i) {
        total += costs[i];
    }
    cout << total << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        findMaxCost();
    }
    return 0;
}

