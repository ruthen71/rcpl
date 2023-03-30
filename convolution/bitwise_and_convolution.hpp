#pragma once

#include "convolution/fast_zeta_mobius_transform.hpp"

// bitwise and convolution
// input: A, B
// output: C
// C_i = \sum_{j \& k = i} A_j B_k
template <class T> std::vector<T> bitwise_and_convolution(std::vector<T> a, std::vector<T> b) {
    const int n = (int)a.size();
    assert(a.size() == b.size());
    assert((n & (n - 1)) == 0);
    fast_zeta_transform_supset(a);
    fast_zeta_transform_supset(b);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fast_mobius_transform_supset(a);
    return a;
}