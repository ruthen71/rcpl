#pragma once

#include "graph/graph_template.hpp"

#include <vector>

template <class T> struct LowestCommonAncestor {
    int n, lg;
    std::vector<int> depth;
    std::vector<std::vector<int>> parent;

    LowestCommonAncestor(Graph<T>& g, const int root = 0) : n((int)(g.size())), lg(32 - __builtin_clz(n)), depth(n, 0), parent(lg, std::vector<int>(n)) {
        auto dfs = [&](auto f, int cur, int par) -> void {
            parent[0][cur] = par;
            for (auto&& e : g[cur]) {
                if (e.to == par) continue;
                depth[e.to] = depth[cur] + 1;
                f(f, e.to, cur);
            }
        };
        dfs(dfs, root, -1);
        for (int k = 0; k + 1 < lg; k++) {
            for (int v = 0; v < n; v++) {
                parent[k + 1][v] = parent[k][v] < 0 ? -1 : parent[k][parent[k][v]];
            }
        }
    }

    int lca(int u, int v) {
        assert((int)(depth.size()) == n);
        if (depth[u] > depth[v]) std::swap(u, v);
        // depth[u] <= depth[v]
        for (int k = 0; k < lg; k++) {
            if ((depth[v] - depth[u]) >> k & 1) v = parent[k][v];
        }
        if (u == v) return u;
        for (int k = lg - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int level_ancestor(int u, const int d) {
        assert((int)(depth.size()) == n);
        if (depth[u] < d) return -1;
        for (int k = 0; k < lg; k++) {
            if (d >> k & 1) u = parent[k][u];
        }
        return u;
    }

    int distance(const int u, const int v) const { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};