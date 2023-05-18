#pragma once

#include "icpc/template.hpp"

// https://onlinejudge.u-aizu.ac.jp/problems/3331

template <class Mint> void ntt(bool type, V<Mint>& a) {
    int n = int(a.size()), s = 0;
    while ((1 << s) < n) s++;
    assert(1 << s == n);

    static V<Mint> ep, iep;
    while (int(ep.size()) <= s) {
        ep.push_back(Mint::G.pow(Mint(-1).v / (1 << ep.size())));
        iep.push_back(ep.back().inv());
    }
    V<Mint> b(n);
    for (int i = 1; i <= s; i++) {
        int w = 1 << (s - i);
        Mint base = type ? iep[i] : ep[i], now = 1;
        for (int y = 0; y < n / 2; y += w) {
            REP(x, w) {
                auto l = a[y << 1 | x];
                auto r = now * a[y << 1 | x | w];
                b[y | x] = l + r;
                b[y | x | n >> 1] = l - r;
            }
            now *= base;
        }
        swap(a, b);
    }
}

template <class Mint> V<Mint> multiply(const V<Mint>& a, const V<Mint>& b) {
    int n = int(a.size()), m = int(b.size());
    if (!n || !m) return {};
    if (min(n, m) <= 8) {
        V<Mint> ans(n + m - 1);
        REP(i, n) REP(j, m) ans[i + j] += a[i] * b[j];
        return ans;
    }
    int lg = 0;
    while ((1 << lg) < n + m - 1) lg++;
    int z = 1 << lg;
    auto a2 = a, b2 = b;
    a2.resize(z);
    b2.resize(z);
    ntt(false, a2);
    ntt(false, b2);
    REP(i, z) a2[i] *= b2[i];
    ntt(true, a2);
    a2.resize(n + m - 1);
    Mint iz = Mint(z).inv();
    REP(i, n + m - 1) a2[i] *= iz;
    return a2;
}