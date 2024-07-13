#pragma once
#include <vector>
#include <cassert>
template <class MSF> struct LazySegmentTree {
   public:
    using S = typename MSF::S;
    using F = typename MSF::F;
    using MS = typename MSF::MS;
    using MF = typename MSF::MF;
    LazySegmentTree() : LazySegmentTree(0) {}
    LazySegmentTree(int n) : LazySegmentTree(std::vector<S>(n, MS::e())) {}
    LazySegmentTree(const std::vector<S>& v) : n((int)(v.size())) {
        log = 0;
        while ((1U << log) < (unsigned int)(n)) log++;
        size = 1 << log;
        d = std::vector<S>(size << 1, MS::e());
        lz = std::vector<F>(size, MF::id());
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
        d[p] = MS::op(d[p], x);
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
        if (l == r) return MS::e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = MS::e(), smr = MS::e();
        while (l < r) {
            if (l & 1) sml = MS::op(sml, d[l++]);
            if (r & 1) smr = MS::op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return MS::op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, const F& f) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = MSF::mapping(f, d[p]);
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
        assert(g(MS::e()));
        if (l == n) return n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = MS::e();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!g(MS::op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l <<= 1;
                    if (g(MS::op(sm, d[l]))) {
                        sm = MS::op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = MS::op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return n;
    }

    template <class G> int min_left(int r, G& g) {
        assert(0 <= r and r <= n);
        assert(g(MS::e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = MS::e();
        do {
            r--;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!g(MS::op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (r << 1) | 1;
                    if (g(MS::op(d[r], sm))) {
                        sm = MS::op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = MS::op(d[r], sm);
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
    inline void update(int k) { d[k] = MS::op(d[k << 1], d[(k << 1) | 1]); }
    void all_apply(int k, const F& f) {
        d[k] = MSF::mapping(f, d[k]);
        if (k < size) lz[k] = MF::composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) | 1, lz[k]);
        lz[k] = MF::id();
    }
};