#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/lowest_common_ancestor.hpp"

int main() {
    int n;
    std::cin >> n;
    Graph<int> g(n, false);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int c;
            std::cin >> c;
            g.add_edge(i, c, 1);
        }
    }
    LowestCommonAncestor tq(g, 0);
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << tq.lca(u, v) << '\n';
    }
    return 0;
}