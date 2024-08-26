#pragma once

#include <cassert>
#include <string>
#include <utility>
#include <vector>

template <class T> std::vector<std::pair<T, int>> run_length_encoding(const std::vector<T>& s) {
    assert((int)(s.size()) > 0);
    std::vector<std::pair<T, int>> res = {{s.front(), 0}};
    for (auto&& si : s) {
        if (si != res.back().first) {
            res.emplace_back(si, 0);
        }
        res.back().second++;
    }
    return res;
}

std::vector<std::pair<char, int>> run_length_encoding(const std::string& s) {
    const int n = (int)(s.size());
    std::vector<char> s2(n);
    for (int i = 0; i < n; i++) s2[i] = s[i];
    return run_length_encoding(s2);
}