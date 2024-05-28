#pragma once

template <class T> std::vector<T> divisor(const T n) {
    std::vector<T> res;
    for (T i = T(1); i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}
