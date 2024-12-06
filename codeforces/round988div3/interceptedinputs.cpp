#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    while (testcases--) {
        int k;
        cin >> k;

        vector<int> freq(k + 1, 0);
        vector<int> numbers(k);
        
        for (int i = 0; i < k; ++i) {
            cin >> numbers[i];
            freq[numbers[i]]++;
        }

        pair<int, int> solution = {-1, -1};

        for (int i = 1; i <= k; ++i) {
            if (i * i == k - 2) {
                if (freq[i] > 1) {
                    solution = {i, i};
                }
            } else if ((k - 2) % i == 0) {
                int pairVal = (k - 2) / i;
                if (pairVal <= k && freq[i] > 0 && freq[pairVal] > 0) {
                    solution = {i, pairVal};
                }
            }
        }

        cout << solution.first << " " << solution.second << endl;
    }

    return 0;
}

