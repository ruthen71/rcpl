#pragma once

#include "icpc/template.hpp"

constexpr ll MOD = 998244353;

using Mat = V<V<ll>>;
Mat mul(Mat& a, Mat& b) {
    int N = int(a.size());
    Mat c(N, V<ll>(N));
    REP(i, N) REP(k, N) REP(j, N) c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
    return c;
}

Mat pow(Mat& a, ll k) {
    int N = int(a.size());
    Mat res(N, V<ll>(N));
    REP(i, N) res[i][i] = 1;
    while (k) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}