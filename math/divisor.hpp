#pragma once

std::vector<long long> divisor(long long n) {
    std::vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}
