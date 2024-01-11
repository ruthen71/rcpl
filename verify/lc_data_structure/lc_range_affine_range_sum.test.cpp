#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>

#include "algebra/lazy_sum_affine.hpp"
#include "data_structure/lazy_segment_tree.hpp"
#include "math/static_modint.hpp"
using mint = mint998;

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<std::pair<mint, int>> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A[i] = {mint(a), 1};
    }
    LazySegmentTree<LazySumAffine<mint>> seg(A);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, b, c;
            std::cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r).first.val() << '\n';
        }
    }
    return 0;
}
