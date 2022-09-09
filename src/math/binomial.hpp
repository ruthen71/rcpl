#pragma once

template <class Mint> struct binomial {
    std::vector<Mint> fact, finv;

    binomial(int N) : fact(N + 1), finv(N + 1) {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;
        finv[N] = 1 / fact[N];
        for (int i = N - 1; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1);
    }

    Mint C(int N, int K) {
        if (N < 0 || K < 0 || N < K) return 0;
        return fact[N] * finv[N - K] * finv[K];
    }

    Mint P(int N, int K) {
        if (N < 0 || K < 0 || N < K) return 0;
        return fact[N] * finv[N - K];
    }

    Mint C_naive(int N, int K) {
        if (N < 0 || K < 0 || N < K) return 0;
        Mint res = 1;
        K = min(K, N - K);
        for (int i = 1; i <= K; i++) {
            res *= N--;
            res /= i;
        }
        return res;
    }
};

/**
 * @brief Binomial (前計算あり二項係数)
 * @docs docs/math/binomial.md
 */