#pragma once

template <class T> struct cumulative_sum {
    std::vector<T> seg;
    int _n;

    cumulative_sum(int _n) : _n(_n), seg(_n + 1, 0) {}
    cumulative_sum(std::vector<T> &A) {
        _n = (int)A.size();
        seg.assign(_n + 1, T(0));
        for (int i = 0; i < _n; i++) seg[i + 1] = seg[i] + A[i];
    }

    // [l, r)
    T sum(int l, int r) const {
        assert(0 <= l and l <= r and r <= _n);
        return seg[r] - seg[l];
    }

    // A[p] = x
    void set(int p, T x) {
        assert(0 <= p and p < _n);
        seg[p + 1] = x;
    }

    // A[p] += x
    void add(int p, T x) {
        assert(0 <= p and p < _n);
        seg[p + 1] += x;
    }

    // A[l] += x, A[l + 1] += x, ... , A[r - 1] += x
    void imos(int l, int r, T x = T(1)) {
        add(l, x);
        add(r, -x);
    }

    void build() {
        for (int i = 0; i < _n; i++) seg[i + 1] += seg[i];
    }

    T operator[](int p) const {
        assert(0 <= p and p < _n);
        return seg[p + 1];
    }

    // output
    friend std::ostream &operator<<(std::ostream &os, const cumulative_sum &A) {
        for (int i = 0; i <= A._n; i++) os << A.seg[i] << " \n"[i == A._n];
        return os;
    }
};
