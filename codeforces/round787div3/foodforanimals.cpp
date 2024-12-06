#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;

        int usedA = min(a, x);
        x -= usedA;
        a -= usedA;

        int usedB = min(b, y);
        y -= usedB;
        b -= usedB;

        if (c >= x + y) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}

