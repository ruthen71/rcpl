#pragma once

#include <vector>
#include <string>

template <class T> std::vector<T> longest_common_subsequence(std::vector<T>& a, std::vector<T>& b) {
    const int n = (int)(a.size()), m = (int)(b.size());
    // -INF
    constexpr int e = -1000000000;
    std::vector dp(n + 1, std::vector<int>(m + 1, e));
    std::vector pd(n + 1, std::vector<int>(m + 1, -1));
    // initialize
    for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
    for (int j = 0; j < m + 1; j++) dp[0][j] = 0;
    // dp
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                if (dp[i + 1][j + 1] < dp[i][j] + 1) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    pd[i + 1][j + 1] = 0;
                }
            } else {
                if (dp[i + 1][j + 1] < dp[i + 1][j]) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                    pd[i + 1][j + 1] = 1;
                }
                if (dp[i + 1][j + 1] < dp[i][j + 1]) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                    pd[i + 1][j + 1] = 2;
                }
            }
        }
    }
    // 復元
    std::vector<T> res;
    res.reserve(dp[n][m]);
    int i = n, j = m;
    while (pd[i][j] != -1) {
        if (pd[i][j] == 0) {
            i--, j--;
            res.push_back(a[i]);
        } else if (pd[i][j] == 1) {
            j--;
        } else {
            // pd[i][j] == 2
            i--;
        }
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::string longest_common_subsequence(std::string& s, std::string& t) {
    const int n = (int)(s.size()), m = (int)(t.size());
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) a[i] = s[i];
    for (int j = 0; j < m; j++) b[j] = t[j];
    auto lcs = longest_common_subsequence(a, b);
    const int k = (int)(lcs.size());
    std::string res;
    res.reserve(k);
    for (int i = 0; i < k; i++) res += lcs[i];
    return res;
}