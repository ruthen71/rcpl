#pragma once

#include "src/graph/template.hpp"

template <class Graph> struct lowest_common_ancestor {
    std::vector<int> depth;
    std::vector<std::vector<int>> parent;
    int n, LOG;

    lowest_common_ancestor(Graph &G, int root = 0) : n(G.size()), LOG(32 - __builtin_clz(G.size())) {
        depth.assign(n, 0);
        parent.assign(LOG, std::vector<int>(n));
        auto dfs = [&](auto f, int cur, int par) -> void {
            parent[0][cur] = par;
            for (auto &e : G[cur]) {
                if (e.to == par) continue;
                depth[e.to] = depth[cur] + 1;
                f(f, e.to, cur);
            }
        };
        dfs(dfs, root, -1);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int v = 0; v < n; v++) {
                parent[k + 1][v] = (parent[k][v] < 0 ? -1 : parent[k][parent[k][v]]);
            }
        }
    }

    int lca(int u, int v) {
        assert((int)depth.size() == n);
        if (depth[u] > depth[v]) std::swap(u, v);
        // depth[u] <= depth[v]
        for (int k = 0; k < LOG; k++)
            if ((depth[v] - depth[u]) >> k & 1) v = parent[k][v];

        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int level_ancestor(int u, int d) {
        assert((int)depth.size() == n);
        if (depth[u] < d) return -1;
        for (int k = 0; k < LOG; k++)
            if (d >> k & 1) u = parent[k][u];
        return u;
    }
};

/**
 * @brief Lowest Common Ancestor (最小共通祖先)
 * @docs docs/graph/lowest_common_ancestor.md
 */
