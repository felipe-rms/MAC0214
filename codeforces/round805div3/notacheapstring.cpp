#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string input;
        cin >> input;
        int maxCost;
        cin >> maxCost;

        string sortedInput = input;
        sort(sortedInput.rbegin(), sortedInput.rend());

        int totalCost = 0;
        for (char ch : input) {
            totalCost += ch - 'a' + 1;
        }

        map<char, int> toRemove;
        for (char ch : sortedInput) {
            if (totalCost > maxCost) {
                toRemove[ch]++;
                totalCost -= ch - 'a' + 1;
            }
        }

        for (char ch : input) {
            if (toRemove[ch] > 0) {
                toRemove[ch]--;
            } else {
                cout << ch;
            }
        }
        cout << endl;
    }
    return 0;
}

