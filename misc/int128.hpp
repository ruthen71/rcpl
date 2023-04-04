#pragma once

std::istream &operator>>(std::istream &is, __int128_t &x) {
    std::string s;
    is >> s;
    x = 0;
    int i = s[0] == '-' ? 1 : 0;
    while (i < (int)s.size()) {
        x = 10 * x + s[i] - '0';
        i++;
    }
    if (s[0] == '-') x = -x;
    return is;
}
std::ostream &operator<<(std::ostream &os, const __int128_t &x) {
    if (x == 0) {
        return os << 0;
    }
    __int128_t y = std::abs(x);
    std::string res = "";
    while (y) {
        res += y % 10 + '0';
        y /= 10;
    }
    if (x < 0) res += '-';
    std::reverse(res.begin(), res.end());
    return os << res;
}