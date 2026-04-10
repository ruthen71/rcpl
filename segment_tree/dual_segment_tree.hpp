#pragma once

#include "../misc/bit_ceil.hpp"
#include "../misc/countr_zero.hpp"

#include <cassert>
#include <vector>

// Dual Segment Tree
template <class MF> struct DualSegmentTree {
  public:
    using F = typename MF::value_type;

    DualSegmentTree() = default;

    explicit DualSegmentTree(int n)
        : DualSegmentTree(std::vector<F>(n, MF::identity())) {}

    explicit DualSegmentTree(const std::vector<F>& v) : n((int)(v.size())) {
        size = bit_ceil(n);
        log = countr_zero(size);
        lz = std::vector<F>(size << 1, MF::identity());
        for (int i = 0; i < n; i++) lz[i + size] = v[i];
    }

    F operator[](int p) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return lz[p];
    }

    F get(int p) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return lz[p];
    }

    void apply(int p, const F& f) {
        assert(0 <= p and p < n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        lz[p] = f;
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
    }

    std::vector<F> make_vector() {
        std::vector<F> vec(n);
        for (int i = 0; i < n; i++) vec[i] = get(i);
        return vec;
    }

  private:
    int n, log, size;
    std::vector<F> lz;

    void all_apply(int k, const F& f) { lz[k] = MF::operation(lz[k], f); }

    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply((k << 1) | 1, lz[k]);
        lz[k] = MF::identity();
    }
};
