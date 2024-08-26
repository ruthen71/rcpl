#pragma once

#include <string>
#include <vector>

template <class T> bool is_palindrome(const std::vector<T>& s) {
    const int n = (int)(s.size());
    bool res = true;
    for (int i = 0; i < n / 2; i++) res &= s[i] == s[n - 1 - i];
    return res;
}

bool is_palindrome(const std::string& s) {
    const int n = (int)(s.size());
    std::vector<int> s2(n);
    for (int i = 0; i < n; i++) s2[i] = s[i];
    return is_palindrome(s2);
}