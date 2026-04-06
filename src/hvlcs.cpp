#include "hvlcs.h"
#include <vector>
#include <algorithm>

using namespace std;

pair<int, string> computeHVLCS(
    const string& a,
    const string& b,
    const unordered_map<char, int>& values
) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            if (a[i - 1] == b[j - 1]) {
                int charValue = 0;
                auto it = values.find(a[i - 1]);
                if (it != values.end()) {
                    charValue = it->second;
                }

                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + charValue);
            }
        }
    }

    string subsequence;
    int i = n;
    int j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            int charValue = 0;
            auto it = values.find(a[i - 1]);
            if (it != values.end()) {
                charValue = it->second;
            }

            if (dp[i][j] == dp[i - 1][j - 1] + charValue) {
                subsequence.push_back(a[i - 1]);
                i--;
                j--;
                continue;
            }
        }

        if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(subsequence.begin(), subsequence.end());

    return {dp[n][m], subsequence};
}