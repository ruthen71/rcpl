#pragma once

struct Osak {
    int n;
    std::vector<int> min_factor;

    Osak(int n) : n(n), min_factor(n + 1) {
        std::iota(min_factor.begin(), min_factor.end(), 0);
        if (n >= 0) min_factor[0] = -1;
        if (n >= 1) min_factor[1] = -1;
        for (int p = 2; p * p <= n; p++) {
            if (min_factor[p] != p) continue;
            for (int i = p * p; i <= n; i += p) {
                if (min_factor[i] != i) continue;
                min_factor[i] = p;
            }
        }
    }

    bool is_prime(int x) {
        assert(x <= n);
        return min_factor[x] == x;
    }

    std::map<int, int> prime_factor(int x) {
        assert(x <= n);
        std::map<int, int> pf;
        while (x > 1) {
            pf[min_factor[x]]++;
            x /= min_factor[x];
        }
        return pf;
    }
};