#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>

#include "graph/lowest_common_ancestor.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    Graph<int> G(N);
    for (int i = 1; i < N; i++) {
        int p;
        std::cin >> p;
        G[i].push_back(Edge(i, p, 1, i - 1));
        G[p].push_back(Edge(p, i, 1, i - 1));
    }
    LowestCommonAncestor tq(G, 0);
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << tq.lca(u, v) << '\n';
    }
    return 0;
}