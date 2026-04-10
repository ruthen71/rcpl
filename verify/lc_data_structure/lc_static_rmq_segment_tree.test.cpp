#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <limits>

#include "../../algebra/monoid/monoid_max.hpp"
#include "../../algebra/monoid/monoid_min.hpp"
#include "../../data_structure/segment_tree.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    std::vector<int> B(N);
    for (int i = 0; i < N; i++) B[i] = -A[i];
    constexpr int INF = std::numeric_limits<int>::max();
    SegmentTree<MonoidMin<int, INF>> segmin(A);
    SegmentTree<MonoidMax<int, INF>> segmax(B);
    while (Q--) {
        int l, r;
        std::cin >> l >> r;
        assert(segmin.prod(l, r) == -segmax.prod(l, r));
        std::cout << segmin.prod(l, r) << '\n';
    }
    return 0;
}
