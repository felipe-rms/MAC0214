#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<int, int> frequency;
        for (int x : a) {
            frequency[x]++;
        }

        int pairs = 0;
        for (int i = 0; i <= n; ++i) {
            pairs += frequency[i] / 2;
        }

        cout << pairs << endl;
    }

    return 0;
}

