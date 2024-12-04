#pragma once

#include <limits>
#include <string>
#include <vector>

// nextelement index
// res[i][c] = s[i, n) において次の c の登場位置を返す
template <class T> std::vector<std::vector<int>> next_element_index(const std::vector<T>& s) {
    const int n = (int)(s.size());
    T lb = std::numeric_limits<T>::max(), ub = std::numeric_limits<T>::min();
    for (int i = 0; i < n; i++) {
        if (lb > s[i]) lb = s[i];
        if (ub < s[i]) ub = s[i];
    }
    const int sigma = ub - lb + 1;
    std::vector res(n + 1, std::vector<int>(sigma, -1));
    for (int i = n - 1; i >= 0; i--) {
        res[i] = res[i + 1];
        res[i][s[i] - lb] = i;
    }
    return res;
}

std::vector<std::vector<int>> next_element_index(const std::string& s) {
    const int n = (int)(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) s2[i] = s[i];
    return next_element_index(s2);
}
