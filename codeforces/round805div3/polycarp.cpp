#include <iostream>
#include <string>
#include <set>
using namespace std;

void process() {
    string input;
    cin >> input;
    set<char> uniqueChars;
    int partitions = 0;

    for (char ch : input) {
        uniqueChars.insert(ch);
        if (uniqueChars.size() > 3) {
            ++partitions;
            uniqueChars.clear();
            uniqueChars.insert(ch);
        }
    }

    if (!uniqueChars.empty()) {
        ++partitions;
    }

    cout << partitions << endl;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        process();
    }

    return 0;
}

