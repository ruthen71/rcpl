#pragma once

#include "icpc/template.hpp"

// https://onlinejudge.u-aizu.ac.jp/problems/2751

template <class T> struct Binomial {
    V<T> f, g;

    Binomial(const int n = 0) {
        f.resize(n);
        g.resize(n);
        f[0] = g[0] = 1;
        for (int i = 1; i < n; i++) f[i] = f[i - 1] * T(i);
        g[n - 1] = T(1) / f[n - 1];
        for (int i = n - 2; i >= 1; i--) g[i] = g[i + 1] * T(i + 1);
    }

    T C(int N, int K) {
        if (N < 0 or K < 0 or N < K) return 0;
        return f[N] * g[N - K] * g[K];
    }

    T P(int N, int K) {
        if (N < 0 or K < 0 or N < K) return 0;
        return f[N] * g[N - K];
    }

    T C_naive(int N, int K) {
        if (N < 0 or K < 0 or N < K) return 0;
        T res(1);
        K = min(K, N - K);
        for (int i = 1; i <= K; i++) {
            res *= N--;
            res /= i;
        }
        return res;
    }
};