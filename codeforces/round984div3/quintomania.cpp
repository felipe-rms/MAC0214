#include <iostream>
#include <vector>
using namespace std;

bool checkSequence(const vector<int>& a) {
    for (int i = 1; i < a.size(); ++i) {
        int diff = abs(a[i] - a[i - 1]);
        if (diff != 5 && diff != 7) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        cout << (checkSequence(a) ? "YES" : "NO") << endl;
    }
    return 0;
}

