#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/heavy_light_decomposition.hpp"
#include "data_structure/segment_tree.hpp"
#include "algebra/monoid_s/monoid_sum.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    auto g = read_parent<long long>(N, false, false, 0);

    const int root = 0;
    HeavyLightDecomposition hld(g, root);
    std::vector<long long> segi(N);
    for (int i = 0; i < N; i++) segi[i] = a[hld.vertices[i]];
    SegmentTree<MonoidSum<long long>> seg(segi);

    for (int i = 0; i < Q; i++) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int u, x;
            std::cin >> u >> x;
            seg.chset(hld.subbegin[u], x);
        } else {
            int u;
            std::cin >> u;
            auto [l, r] = hld.subtree_query(u, false);
            std::cout << seg.prod(l, r) << '\n';
        }
    }
    return 0;
}