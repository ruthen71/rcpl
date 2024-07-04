#pragma once

#include <vector>
#include <limits>
#include <algorithm>

template <class T> int longest_increasing_subsequence(const std::vector<T>& a, bool strict = true) {
    // strict = true  -> A[i] <  A[i + 1]
    // strict = false -> A[i] <= A[i + 1]
    const int n = (int)(a.size());
    const T INF = std::numeric_limits<T>::max();
    std::vector<T> dp(n, INF);
    // dp 配列中に A[i] があったときに, どの値を書き換えるかを考えると lower か upper を区別できる
    if (strict) {
        for (int i = 0; i < n; i++) {
            *std::lower_bound(dp.begin(), dp.end(), a[i]) = a[i];  // strict なのでその値
        }
    } else {
        for (int i = 0; i < n; i++) {
            *std::upper_bound(dp.begin(), dp.end(), a[i]) = a[i];  // strict ではないのでその次の値
        }
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}