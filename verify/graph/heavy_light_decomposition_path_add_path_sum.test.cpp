#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include <iostream>

#include "../../algebra/acted_monoid/acted_monoid_plus_plus.hpp"
#include "../../segment_tree/lazy_segment_tree.hpp"
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../graph/read_graph.hpp"

int main() {
    int N;
    std::cin >> N;
    Graph<int> g(N, false);

    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        for (int j = 0; j < K; j++) {
            int c;
            std::cin >> c;
            g.add_edge(i, c, 1);
        }
    }
    const int root = N / 2;  // verify のために適当に決める
    HeavyLightDecomposition hld(g, root);
    LazySegmentTree<ActedMonoidPlusPlus<long long>> seg(N - 1);

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int v, w;
            std::cin >> v >> w;
            auto intervals = hld.path_query(0, v, true);
            for (auto&& [l, r] : intervals) {
                seg.apply(l, r, w);
            }
        } else {
            int v;
            std::cin >> v;
            auto intervals = hld.path_query(0, v, true);
            auto res = ActedMonoidPlusPlus<long long>::MS::identity();
            for (auto&& [l, r] : intervals) {
                res = ActedMonoidPlusPlus<long long>::MS::operation(
                    res, seg.prod(l, r));
            }
            std::cout << res << '\n';
        }
    }

    return 0;
}
