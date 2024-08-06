#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/heavy_light_decomposition.hpp"
#include "data_structure/lazy_segment_tree.hpp"
#include "algebra/monoid_s_f/monoid_sum_size_add.hpp"

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
    std::vector<std::pair<long long, int>> segi(N - 1, {0, 1});
    LazySegmentTree<MonoidSumSizeAdd<long long>> seg(segi);

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
            auto res = MonoidSumSizeAdd<long long>::MS::e();
            for (auto&& [l, r] : intervals) {
                res = MonoidSumSizeAdd<long long>::MS::op(res, seg.prod(l, r));
            }
            std::cout << res.first << '\n';
        }
    }

    return 0;
}