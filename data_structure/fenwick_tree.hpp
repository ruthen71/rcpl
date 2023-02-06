#pragma once

template <class T> struct fenwick_tree {
    int N;
    std::vector<T> seg;
    fenwick_tree(int N) : N(N), seg(N + 1, 0) {}
    fenwick_tree(std::vector<T> &A) {
        N = (int)A.size();
        seg.resize(N + 1);
        for (int i = 0; i < N; i++) add(i, A[i]);
    }
    // A[i] += x
    void add(int i, T x) {
        assert(0 <= i and i < N);
        i++;  // 1-indexed
        while (i <= N) {
            seg[i] += x;
            i += i & -i;
        }
    }
    // A[0] + ... + A[i - 1]
    T sum(int i) const {
        assert(0 <= i and i <= N);
        T s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    // A[a] + ... + A[b - 1]
    T sum(int a, int b) const {
        assert(0 <= a and a <= b and b <= N);
        return sum(b) - sum(a);
    }

    // output
    friend std::ostream &operator<<(std::ostream &os, const fenwick_tree &A) {
        for (int i = 0; i < A.N; i++) os << A.sum(i, i + 1) << " \n"[i == A.N - 1];
        return os;
    }
};

/**
 * @brief Fenwick Tree (Binary Indexed Tree)
 * @docs docs/data_structure/fenwick_tree.md
 */
