#pragma once
#include <vector>
#include <cassert>
template <class MS> struct SegmentTree {
   public:
    using S = typename MS::S;
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n) : SegmentTree(std::vector<S>(n, MS::e())) {}
    SegmentTree(const std::vector<S>& v) : n((int)(v.size())) {
        log = 0;
        while ((1U << log) < (unsigned int)(n)) log++;
        size = 1 << log;
        d = std::vector<S>(size << 1, MS::e());
        for (int i = 0; i < n; i++) d[i + size] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void chset(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        d[p] = MS::op(d[p], x);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S operator[](int p) const {
        assert(0 <= p and p < n);
        return d[p + size];
    }

    S get(int p) const {
        assert(0 <= p && p < n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        S sml = MS::e(), smr = MS::e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = MS::op(sml, d[l++]);
            if (r & 1) smr = MS::op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return MS::op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <class G> int max_right(int l, G& g) const {
        assert(0 <= l and l <= n);
        assert(g(MS::e()));
        if (l == n) return n;
        l += size;
        S sm = MS::e();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!g(MS::op(sm, d[l]))) {
                while (l < size) {
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

    template <class G> int min_left(int r, G& g) const {
        assert(0 <= r and r <= n);
        assert(g(MS::e()));
        if (r == 0) return 0;
        r += size;
        S sm = MS::e();
        do {
            r--;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!g(MS::op(d[r], sm))) {
                while (r < size) {
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
    inline void update(int k) { d[k] = MS::op(d[k << 1], d[(k << 1) | 1]); }
};