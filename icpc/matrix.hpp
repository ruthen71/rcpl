#pragma once

#include "icpc/template.hpp"

constexpr ll MOD = 998244353;

V<V<ll>> mul(V<V<ll>> a, V<V<ll>> b) {
    int N = int(a.size());
    V<V<ll>> c(N, V<ll>(N));
    REP(i, N) REP(k, N) REP(j, N) c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
    return c;
}

V<V<ll>> pow(V<V<ll>> a, ll k) {
    int N = int(a.size());
    V<V<ll>> res(N, V<ll>(N));
    REP(i, N) res[i][i] = 1;
    while (k) {
        if (k & 1) res = mul(res, a);
        a = mul(a, a);
        k >>= 1;
    }
    return res;
}