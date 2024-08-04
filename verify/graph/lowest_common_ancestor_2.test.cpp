#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/lowest_common_ancestor.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    auto g = read_parent<int>(N, false, false, 0);
    LowestCommonAncestor tq(g, 0);
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << tq.lca(u, v) << '\n';
    }
    return 0;
}