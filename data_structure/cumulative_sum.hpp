#pragma once

template <class T> struct CumulativeSum {
    int n;
    std::vector<T> seg;

    CumulativeSum() = default;

    CumulativeSum(int n) : n(n), seg(n + 1, T(0)) {}

    CumulativeSum(std::vector<T>& a) {
        n = (int)a.size();
        seg.assign(n + 1, T(0));
        for (int i = 0; i < n; i++) seg[i + 1] = seg[i] + a[i];
    }

    // [l, r)
    T sum(int l, int r) const {
        assert(0 <= l and l <= r and r <= n);
        return seg[r] - seg[l];
    }

    // A[l] += x, A[l + 1] += x, ... , A[r - 1] += x
    void imos(int l, int r, T x = T(1)) {
        assert(0 <= l and l <= r and r <= n);
        seg[l] += x;
        seg[r] -= x;
    }

    void build() {
        for (int i = 0; i < n; i++) seg[i + 1] += seg[i];
    }

    // return A[p]
    T get(int p) const {
        assert(0 <= p and p < n);
        return seg[p];
    }

    std::vector<T> make_vector() { return seg; }
};