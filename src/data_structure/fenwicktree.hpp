#pragma once

template <class T> struct fenwicktree {
    int N;
    std::vector<T> seg;
    fenwicktree(int N) : N(N), seg(N + 1, 0) {}
    fenwicktree(std::vector<T> &A) {
        N = (int)A.size();
        seg.resize(N + 1);
        for (int i = 0; i < N; i++) add(i, A[i]);
    }
    // A[i] += x
    void add(int i, T x) {
        i++;  // 1-indexed
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }
    // A[0] + ... + A[i - 1]
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    // A[a] + ... + A[b - 1]
    T sum(int a, int b) { return sum(b) - sum(a); }
};

/**
 * @brief Fenwick Tree (Binary Indexed Tree)
 * @docs docs/data_structure/fenwicktree.md
 */
