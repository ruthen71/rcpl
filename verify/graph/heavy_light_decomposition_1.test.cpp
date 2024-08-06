#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/heavy_light_decomposition.hpp"
#include "data_structure/segment_tree.hpp"
#include "algebra/monoid_s/monoid_sum.hpp"

int main() {
    int N;
    std::cin >> N;
    Graph<int> g(N, false);

    std::vector<int> id(N, -1);
    for (int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        for (int j = 0; j < K; j++) {
            int c;
            std::cin >> c;
            id[c] = g.add_edge(i, c, 1);
        }
    }
    const int root = N / 2;  // verify のために適当に決める
    HeavyLightDecomposition hld(g, root);
    SegmentTree<MonoidSum<long long>> seg(N - 1);

    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int v, w;
            std::cin >> v >> w;
            int eid = id[v];
            seg.chset(hld.eindex[eid], w);
        } else {
            int v;
            std::cin >> v;
            auto intervals = hld.path_query(0, v, true);
            auto res = MonoidSum<long long>::e();
            for (auto&& [l, r] : intervals) {
                res = MonoidSum<long long>::op(res, seg.prod(l, r));
            }
            std::cout << res << '\n';
        }
    }
    return 0;
}