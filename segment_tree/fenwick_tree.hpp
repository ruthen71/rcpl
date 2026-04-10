#pragma once

#include <cassert>
#include <vector>

// Fenwick Tree
template <class MS> struct FenwickTree {
  public:
    using S = typename MS::value_type;

    FenwickTree() = default;

    explicit FenwickTree(int n)
        : FenwickTree(std::vector<S>(n, MS::identity())) {}

    explicit FenwickTree(const std::vector<S>& v) : n((int)(v.size())) {
        d = std::vector<S>(n + 1, MS::identity());
        for (int i = 1; i <= n; i++) {
            d[i] = MS::operation(d[i], v[i - 1]);
            int j = i + (i & -i);
            if (j <= n) {
                d[j] = MS::operation(d[j], d[i]);
            }
        }
    }

    void set(int p, const S& x) {
        assert(0 <= p and p < n);
        add(p, MS::operation(MS::inverse(get(p)), x));
    }
    void add(int p, const S& x) {
        assert(0 <= p and p < n);
        p++;  // 1-indexed
        while (p <= n) {
            d[p] = MS::operation(d[p], x);
            p += p & -p;
        }
    }

    S operator[](int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S get(int p) const {
        assert(0 <= p and p < n);
        return prod(p, p + 1);
    }

    S prod(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        return MS::operation(prod(r), MS::inverse(prod(l)));
    }

    S prod(int p) const {
        assert(0 <= p and p <= n);
        S s = MS::identity();
        while (p > 0) {
            s = MS::operation(s, d[p]);
            p -= p & -p;
        }
        return s;
    }

    S all_prod() const { return prod(n); }

    std::vector<S> make_vector() {
        std::vector<S> vec(n);
        for (int i = 0; i < n; i++) vec[i] = get(i);
        return vec;
    }

  private:
    int n;
    std::vector<S> d;
};
