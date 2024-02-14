#pragma once

template <class Mint> struct Binomial {
    std::vector<Mint> f, g;

    Binomial(int N = 0) {
        f.resize(1, Mint(1));
        g.resize(1, Mint(1));
        while (N >= (int)f.size()) extend();
    }

    void extend() {
        int n = (int)f.size();
        int m = n * 2;
        f.resize(m);
        g.resize(m);
        for (int i = n; i < m; i++) f[i] = f[i - 1] * Mint(i);
        g[m - 1] = 1 / f[m - 1];
        for (int i = m - 2; i >= n; i--) g[i] = g[i + 1] * Mint(i + 1);
    }

    Mint fact(int i) {
        if (i < 0) return Mint(0);
        while (i >= (int)f.size()) extend();
        return f[i];
    }

    Mint finv(int i) {
        if (i < 0) return Mint(0);
        while (i >= (int)g.size()) extend();
        return g[i];
    }

    Mint C(int N, int K) {
        // N 個から重複を許さずに K 個取る
        if (N < 0 or K < 0 or N < K) return Mint(0);
        return fact(N) * finv(N - K) * finv(K);
    }

    Mint P(int N, int K) {
        // N 個から重複を許さずに K 個取って並べる
        if (N < 0 or K < 0 or N < K) return Mint(0);
        return fact(N) * finv(N - K);
    }

    Mint H(int N, int K) {
        // N 個から重複を許して K 個取る
        if (N < 0 or K < 0) return Mint(0);
        if (K == 0) return Mint(1);
        return C(N + K - 1, K);
    }

    Mint C_naive(int N, int K) {
        if (N < 0 or K < 0 or N < K) return Mint(0);
        Mint res = 1;
        K = std::min(K, N - K);
        for (int i = 1; i <= K; i++) {
            res *= N--;
            res /= i;
        }
        return res;
    }
};