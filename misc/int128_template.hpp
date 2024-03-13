#pragma once

#include <my_template.hpp>
// type definition
using i128 = __int128_t;
using u128 = __uint128_t;
// infinity
template <> constexpr i128 INF<i128> = i128(INF<i64>) * INF<i64>;  // 4e36
template <> constexpr u128 INF<u128> = INF<i128>;                  // 4e36
// input
std::istream& operator>>(std::istream& is, i128& x) {
    std::string s;
    is >> s;
    x = 0;
    int i = s[0] == '-' ? 1 : 0;
    while (i < (int)(s.size())) x = 10 * x + s[i++] - '0';
    if (s[0] == '-') x = -x;
    return is;
}
std::istream& operator>>(std::istream& is, u128& x) {
    std::string s;
    is >> s;
    assert(s[0] != '-');
    x = 0;
    int i = 0;
    while (i < (int)(s.size())) x = 10 * x + s[i++] - '0';
    return is;
}
// output
std::ostream& operator<<(std::ostream& os, const i128& x) {
    if (x == 0) {
        return os << 0;
    }
    i128 y = (x > 0 ? x : -x);
    std::string res;
    while (y) {
        res += y % 10 + '0';
        y /= 10;
    }
    if (x < 0) res += '-';
    std::reverse(res.begin(), res.end());
    return os << res;
}
std::ostream& operator<<(std::ostream& os, const u128& x) {
    if (x == 0) {
        return os << 0;
    }
    u128 y = x;
    std::string res;
    while (y) {
        res += y % 10 + '0';
        y /= 10;
    }
    std::reverse(res.begin(), res.end());
    return os << res;
}