#pragma once

#include "icpc/template.hpp"

template <class S, S (*op)(S, S), S (*e)()> struct Segtree {
    int n, size, log;
    V<S> d;
    Segtree() : Segtree(0) {}
    Segtree(int n) : Segtree(V<S>(n, e())) {}
    Segtree(V<S>& v) : n(int(v.size())) {
        log = 0;
        while ((1 << log) < n) log++;
        size = 1 << log;
        d = V<S>(size << 1, e());
        REP(i, n) d[i + size] = v[i];
        for (int i = size - 1; i >= 1; i--) update(i);
    }

    void update(int k) { d[k] = op(d[k << 1], d[(k << 1) | 1]); }

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p and p < n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        S sml = e(), smr = e();
        l += size, r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1, r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <class F> int max_right(int l, F f) {
        assert(0 <= l and l <= n);
        assert(f(e()));
        if (l == n) return n;
        l += size;
        S sm = e();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l <<= 1;
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <class F> int min_left(int r, F& f) {
        assert(0 <= r and r <= n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (r << 1) | 1;
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
};