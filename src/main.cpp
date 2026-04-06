#include <iostream>
#include <string>
#include <unordered_map>
#include "hvlcs.h"

using namespace std;

int main() {
    int k;
    cin >> k;

    unordered_map<char, int> values;
    for (int i = 0; i < k; i++) {
        char ch;
        int val;
        cin >> ch >> val;
        values[ch] = val;
    }

    string a, b;
    cin >> a >> b;

    auto result = computeHVLCS(a, b, values);

    cout << result.first << '\n';
    cout << result.second << '\n';

    return 0;
}