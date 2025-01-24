#pragma once

#include <vector>
#include <string>

template <class T>
int levenshtein_distance(std::vector<T>& a, std::vector<T>& b, const int inf = 1000000000) {
    const int n = (int)(a.size()), m = (int)(b.size());
    std::vector dp(n + 1, std::vector<int>(m + 1, inf));
    // initialize
    for (int i = 0; i < n + 1; i++) dp[i][0] = i;
    for (int j = 0; j < m + 1; j++) dp[0][j] = j;
    // dp
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // a += ?
            if (j + 1 <= m and dp[i][j + 1] > dp[i][j] + 1) {
                dp[i][j + 1] = dp[i][j] + 1;
            }
            // b += ?
            if (i + 1 <= n and dp[i + 1][j] > dp[i][j] + 1) {
                dp[i + 1][j] = dp[i][j] + 1;
            }
            // a[i] = b[i]
            if (i + 1 <= n and j + 1 <= m) {
                int cost = a[i] == b[j] ? 0 : 1;
                if (dp[i + 1][j + 1] > dp[i][j] + cost) {
                    dp[i + 1][j + 1] = dp[i][j] + cost;
                }
            }
        }
    }
    return dp[n][m];
}

int levenshtein_distance(std::string& s, std::string& t, const int inf = 1000000000) {
    const int n = (int)(s.size()), m = (int)(t.size());
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = s[i];
    for (int j = 0; j < m; j++) b[j] = t[j];
    return levenshtein_distance(a, b, inf);
}