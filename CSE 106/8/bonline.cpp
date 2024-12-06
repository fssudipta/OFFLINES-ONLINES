#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string t, s;
    getline(cin, t);
    getline(cin, s);
    int m = t.length();
    int n = s.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0; // First row: LCS with an empty `t`
    }
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0; // First column: LCS with an empty `s`
    }

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (t[i - 1] == s[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take the max of excluding one char
            }
        }
    }

    // Output the length of the LCS
    cout << dp[m][n] << endl;

    return 0;
}
