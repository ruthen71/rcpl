#pragma once

#include <vector>
#include <algorithm>

// 二項係数ライブラリ
template <class Mint> struct Binomial {
    std::vector<Mint> f, g, h;

    Binomial(const int n_max = 0) {
        f.resize(1, Mint(1));
        g.resize(1, Mint(1));
        h.resize(1, Mint(1));
        if (n_max > 0) extend(n_max);
    }

    // 基本は長さを倍にする
    void extend(int m = -1) {
        const int n = (int)(f.size());  // n >= 1
        if (m == -1) m = n * 2;         // m >= 2
        m = std::min(m, Mint::mod());
        if (n >= m) return;
        f.resize(m);
        g.resize(m);
        h.resize(m);
        // calc f
        for (int i = n; i < m; i++) f[i] = f[i - 1] * Mint(i);
        // calc g
        g[m - 1] = 1 / f[m - 1];
        for (int i = m - 2; i >= n; i--) g[i] = g[i + 1] * Mint(i + 1);
        // calc h
        h[m - 1] = g[m - 1] * f[m - 2];
        for (int i = m - 2; i >= n; i--) h[i] = g[i] * f[i - 1];
    }

    // fact(n) = n!
    Mint fact(const int n) {
        if (n < 0) return Mint(0);
        while (n >= (int)(f.size())) extend();
        return f[n];
    }

    // finv(n) = 1 / n!
    Mint finv(const int n) {
        if (n < 0) return Mint(0);
        while (n >= (int)(g.size())) extend();
        return g[n];
    }

    // inv(n) = 1 / n
    Mint inv(const int n) {
        if (n < 0) return Mint(0);
        while (n >= (int)(h.size())) extend();
    }

    // n C k
    Mint C(const int n, const int k) {
        if (n < 0 or k < 0 or n < k) return Mint(0);
        return fact(n) * finv(n - k) * finv(k);
    }

    // n P k
    Mint P(const int n, const int k) {
        if (n < 0 or k < 0 or n < k) return Mint(0);
        return fact(n) * finv(n - k);
    }

    // n H k
    // n 個から k 個重複を許して取る組合せ
    Mint H(const int n, const int k) {
        if (n < 0 or k < 0) return Mint(0);
        if (k == 0) return Mint(1);
        return C(n + k - 1, k);
    }

    Mint C_naive(int n, int k) {
        if (n < 0 or k < 0 or n < k) return Mint(0);
        Mint res = Mint(1), res_inv = Mint(1);
        k = std::min(k, n - k);
        for (int i = 1; i <= k; i++) {
            res *= (n--);
            res_inv *= i;
        }
        res /= res_inv;
        return res;
    }
};