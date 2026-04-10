#pragma once

#include "../misc/bit_ceil.hpp"
#include "../misc/countr_zero.hpp"
#include "../misc/topbit.hpp"

#include <cassert>
#include <vector>

// Lazy Segment Tree
template <class AM> struct LazySegmentTree {
  public:
    using MS = typename AM::MS;
    using MF = typename AM::MF;
    using S = typename MS::value_type;
    using F = typename MF::value_type;

    LazySegmentTree() = default;

    explicit LazySegmentTree(int n)
        : LazySegmentTree(std::vector<S>(n, MS::identity())) {}

    explicit LazySegmentTree(const std::vector<S>& v) : n((int)(v.size())) {
        size = bit_ceil(n);
        log = countr_zero(size);
        d = std::vector<S>(size << 1, MS::identity());
        lz = std::vector<F>(size, MF::identity());
        for (int i = 0; i < n; i++) d[i + size] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void chset(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = MS::operation(d[p], x);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S operator[](int p) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S get(int p) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        if (l == r) return MS::identity();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = MS::identity(), smr = MS::identity();
        while (l < r) {
            if (l & 1) sml = MS::operation(sml, d[l++]);
            if (r & 1) smr = MS::operation(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return MS::operation(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, const F& f) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = AM::mapping(f, d[p], 1);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, const F& f) {
        assert(0 <= l and l <= r and r <= n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <class G> int max_right(int l, G& g) {
        assert(0 <= l and l <= n);
        assert(g(MS::identity()));
        if (l == n) return n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = MS::identity();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!g(MS::operation(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l <<= 1;
                    if (g(MS::operation(sm, d[l]))) {
                        sm = MS::operation(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = MS::operation(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <class G> int min_left(int r, G& g) {
        assert(0 <= r and r <= n);
        assert(g(MS::identity()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = MS::identity();
        do {
            r--;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!g(MS::operation(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (r << 1) | 1;
                    if (g(MS::operation(d[r], sm))) {
                        sm = MS::operation(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = MS::operation(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    std::vector<S> make_vector() {
        std::vector<S> vec(n);
        for (int i = 0; i < n; i++) vec[i] = get(i);
        return vec;
    }

  private:
    int n, log, size;
    std::vector<S> d;
    std::vector<F> lz;

    inline void update(int k) {
        d[k] = MS::operation(d[k << 1], d[(k << 1) | 1]);
    }

    void all_apply(int k, const F& f) {
        d[k] = AM::mapping(f, d[k], 1 << (log - topbit(k)));
        // MF::operation(f, g), g(f(x))
        if (k < size) lz[k] = MF::operation(lz[k], f);
    }

    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) | 1, lz[k]);
        lz[k] = MF::identity();
    }
};
