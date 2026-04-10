#pragma once

#include "../misc/bit_ceil.hpp"
#include "../misc/countr_zero.hpp"

#include <cassert>
#include <vector>

// Segment Tree
template <class MS> struct SegmentTree {
  public:
    using S = typename MS::value_type;

    SegmentTree() = default;

    explicit SegmentTree(int n)
        : SegmentTree(std::vector<S>(n, MS::identity())) {}

    explicit SegmentTree(const std::vector<S>& v) : n((int)(v.size())) {
        size = bit_ceil(n);
        log = countr_zero(size);
        d = std::vector<S>(size << 1, MS::identity());
        for (int i = 0; i < n; i++) d[size + i] = v[i];
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

    void add(int p, const S& x) {
        assert(0 <= p and p < n);
        p += size;
        d[p] = MS::operation(d[p], x);
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
        S sml = MS::identity(), smr = MS::identity();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = MS::operation(sml, d[l++]);
            if (r & 1) smr = MS::operation(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return MS::operation(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <class G> int max_right(int l, G& g) const {
        assert(0 <= l and l <= n);
        assert(g(MS::identity()));
        if (l == n) return n;
        l += size;
        S sm = MS::identity();
        do {
            while ((l & 1) == 0) l >>= 1;
            if (!g(MS::operation(sm, d[l]))) {
                while (l < size) {
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

    template <class G> int min_left(int r, G& g) const {
        assert(0 <= r and r <= n);
        assert(g(MS::identity()));
        if (r == 0) return 0;
        r += size;
        S sm = MS::identity();
        do {
            r--;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!g(MS::operation(d[r], sm))) {
                while (r < size) {
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

    inline void update(int k) {
        d[k] = MS::operation(d[k << 1], d[(k << 1) | 1]);
    }
};
