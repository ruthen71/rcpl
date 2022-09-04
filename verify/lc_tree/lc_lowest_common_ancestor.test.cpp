#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>

#include "src/graph/lowest_common_ancestor.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    graph<long long> G(N);
    G.read_parent(0);
    lowest_common_ancestor<decltype(G)> tq(G, 0);
    while (Q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << tq.lca(u, v) << '\n';
    }
    return 0;
}