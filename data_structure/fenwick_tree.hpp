#pragma once

template <class T> struct FenwickTree {
    int n;
    std::vector<T> seg;
    FenwickTree() : n(0) {}
    FenwickTree(int n) : n(n), seg(n + 1, 0) {}
    FenwickTree(std::vector<T>& arr) {
        n = int(arr.size());
        seg.resize(n + 1);
        for (int i = 0; i < n; i++) add(i, arr[i]);
    }
    // A[i] += x
    void add(int i, const T& x) {
        assert(0 <= i and i < n);
        i++;  // 1-indexed
        while (i <= n) {
            seg[i] += x;
            i += i & -i;
        }
    }
    // A[0] + ... + A[i - 1]
    T sum(int i) const {
        assert(0 <= i and i <= n);
        T s = T(0);
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    // A[a] + ... + A[b - 1]
    T sum(int a, int b) const {
        assert(0 <= a and a <= b and b <= n);
        return sum(b) - sum(a);
    }
    // return A[i]
    T get(int i) const { return sum(i, i + 1); }
    // A[i] = x
    void set(int i, const T x) { add(i, x - get(i)); }
    // output
    friend std::ostream& operator<<(std::ostream& os, const FenwickTree& fen) {
        for (int i = 0; i < fen.n; i++) os << fen.get(i) << " \n"[i == fen.n - 1];
        return os;
    }
};