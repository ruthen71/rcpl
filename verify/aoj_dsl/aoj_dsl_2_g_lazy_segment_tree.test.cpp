#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include <bits/stdc++.h>

#include "src/algebra/lazy_sum_add.hpp"
#include "src/data_structure/lazy_segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    lazy_segment_tree<lazy_sum_add<long long>> seg(std::vector<std::pair<long long, int>>(N, {0, 1}));
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            l--;
            std::cout << seg.prod(l, r).first << '\n';
        }
    }
    return 0;
}
