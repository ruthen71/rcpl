#pragma once

// fast zeta transform (subset)
// input: A
// output: B
// B_i = \sum_{j \subset i} A_j
template <class T> void fast_zeta_transform_subset(std::vector<T> &a) {
    const int n = (int)a.size();
    assert((n & (n - 1)) == 0);
    for (int j = 1; j < n; j <<= 1) {
        for (int i = 0; i < n; i++) {
            if (i & j) {
                a[i] += a[i ^ j];
            }
        }
    }
}

// fast mobius transform (subset)
// input: B
// output: A
// B_i = \sum_{j \subset i} A_j
template <class T> void fast_mobius_transform_subset(std::vector<T> &b) {
    const int n = (int)b.size();
    assert((n & (n - 1)) == 0);
    for (int j = 1; j < n; j <<= 1) {
        for (int i = 0; i < n; i++) {
            if (i & j) {
                b[i] -= b[i ^ j];
            }
        }
    }
}

// fast zeta transform (supset)
// input: A
// output: B
// B_i = \sum_{j \supset i} A_j
template <class T> void fast_zeta_transform_supset(std::vector<T> &a) {
    const int n = (int)a.size();
    assert((n & (n - 1)) == 0);
    for (int j = 1; j < n; j <<= 1) {
        for (int i = 0; i < n; i++) {
            if (i & j) {
                a[i ^ j] += a[i];
            }
        }
    }
}

// fast mobius transform (supset)
// input: B
// output: A
// B_i = \sum_{j \supset i} A_j
template <class T> void fast_mobius_transform_supset(std::vector<T> &b) {
    const int n = (int)b.size();
    assert((n & (n - 1)) == 0);
    for (int j = 1; j < n; j <<= 1) {
        for (int i = 0; i < n; i++) {
            if (i & j) {
                b[i ^ j] -= b[i];
            }
        }
    }
}