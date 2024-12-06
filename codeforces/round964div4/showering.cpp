#include <iostream>
using namespace std;

int main() {
    long testCases;
    cin >> testCases;

    while (testCases--) {
        long segments, distance, maxLength;
        cin >> segments >> distance >> maxLength;

        long lastRight = 0;
        bool canReach = false;

        for (long i = 0; i < segments; ++i) {
            long start, end;
            cin >> start >> end;

            if (lastRight + distance <= start) {
                canReach = true;
            }

            lastRight = end; 
        }

        if (lastRight + distance <= maxLength) {
            canReach = true;
        }

        cout << (canReach ? "YES" : "NO") << endl;
    }

    return 0;
}

