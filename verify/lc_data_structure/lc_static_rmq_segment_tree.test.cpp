#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>

#include "algebra/monoid_min.hpp"
#include "data_structure/segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    SegmentTree<MonoidMin<int>> seg(A);
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << seg.prod(l, r) << '\n';
    }
    return 0;
}