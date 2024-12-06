#include <iostream>
#include <string>
using namespace std;

void process() {
    int number;
    cin >> number;
    string digits = to_string(number);
    string base = "1";
    for (int i = 1; i < digits.size(); ++i) {
        base += '0';
    }
    int baseValue = stoi(base);
    cout << number - baseValue << endl;
}

int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        process();
    }
    return 0;
}

