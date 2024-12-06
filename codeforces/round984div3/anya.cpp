#include <iostream>
#include <cstring>
using namespace std;
using l = long long;

char buffer[1000000];
l length;

bool hasPattern(l index) {
    if (index < 0 || index >= length - 3) return false;
    return buffer[index] == '1' && buffer[index + 1] == '1' && buffer[index + 2] == '0' && buffer[index + 3] == '0';
}

void processQuery() {
    cin >> buffer;
    length = strlen(buffer);
    l patternCount = 0;

    for (l i = 0; i < length; ++i) {
        if (hasPattern(i)) ++patternCount;
    }

    l queries;
    cin >> queries;

    while (queries--) {
        l index, value;
        cin >> index >> value;
        --index;

        if (buffer[index] != ('0' + value)) {
            bool before = hasPattern(index - 3) || hasPattern(index - 2) || hasPattern(index - 1) || hasPattern(index);
            buffer[index] = '0' + value;
            bool after = hasPattern(index - 3) || hasPattern(index - 2) || hasPattern(index - 1) || hasPattern(index);
            patternCount += after - before;
        }
        cout << (patternCount > 0 ? "YES" : "NO") << endl;
    }
}

int main() {
    l t;
    cin >> t;
    while (t--) processQuery();
    return 0;
}

