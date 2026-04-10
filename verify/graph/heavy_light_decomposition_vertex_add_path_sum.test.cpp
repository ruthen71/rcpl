#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>

#include "../../algebra/monoid/monoid_plus.hpp"
#include "../../segment_tree/segment_tree.hpp"
#include "../../graph/heavy_light_decomposition.hpp"
#include "../../graph/read_graph.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    auto g = read_graph<long long>(N, N - 1, false, false, 0);

    const int root = N / 2;  // verify のために適当に決める
    HeavyLightDecomposition hld(g, root);
    std::vector<long long> segi(N);
    for (int i = 0; i < N; i++) segi[i] = a[hld.vertices[i]];
    SegmentTree<MonoidPlus<long long>> seg(segi);

    for (int i = 0; i < Q; i++) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int p, x;
            std::cin >> p >> x;
            seg.add(hld.subbegin[p], x);
        } else {
            int u, v;
            std::cin >> u >> v;
            auto intervals = hld.path_query(u, v, false);
            auto res = MonoidPlus<long long>::identity();
            for (auto&& [l, r] : intervals) {
                res = MonoidPlus<long long>::operation(res, seg.prod(l, r));
            }
            std::cout << res << '\n';
        }
    }
    return 0;
}
