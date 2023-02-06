#pragma once

std::map<long long, int> prime_factor(long long n) {
    std::map<long long, int> res;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) res[n]++;
    return res;
}