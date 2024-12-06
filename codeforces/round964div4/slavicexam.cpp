#include <iostream>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        string strA, strB;
        cin >> strA >> strB;

        int matched = 0, indexA = -1;

        for (int i = 0; i < strB.size(); ++i) {
            for (indexA = indexA + 1; indexA < strA.size(); ++indexA) {
                if (strB[i] == strA[indexA] || strA[indexA] == '?') {
                    matched++;
                    if (strA[indexA] == '?') strA[indexA] = strB[i];
                    break;
                }
            }
        }

        if (matched >= strB.size()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            continue;
        }

        for (char c : strA) {
            cout << (c != '?' ? c : 'a');
        }

        cout << endl;
    }

    return 0;
}

