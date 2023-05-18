#pragma once

#include "icpc/template.hpp"

// https://onlinejudge.u-aizu.ac.jp/problems/3329

struct LCA {
    V<int> dep;
    V<V<int>> par;
    int n, log;

    LCA(V<V<int>>& g, int root = 0) : n(int(g.size())), log(32 - __builtin_clz(g.size())) {
        dep.assign(n, 0);
        par.assign(log, V<int>(n));
        auto dfs = [&](auto f, int c, int p) -> void {
            par[0][c] = p;
            for (auto& e : g[c]) {
                if (e == p) continue;
                dep[e] = dep[c] + 1;
                f(f, e, c);
            }
        };
        dfs(dfs, root, -1);
        REP(k, log - 1) REP(v, n) par[k + 1][v] = (par[k][v] == -1 ? -1 : par[k][par[k][v]]);
    }

    int lca(int u, int v) {
        assert(int(dep.size()) == n);
        if (dep[u] > dep[v]) swap(u, v);
        REP(k, log) if ((dep[v] - dep[u]) >> k & 1) v = par[k][v];
        if (u == v) return u;
        for (int k = log - 1; k >= 0; k--) {
            if (par[k][u] != par[k][v]) {
                u = par[k][u];
                v = par[k][v];
            }
        }
        return par[0][u];
    }

    int level_ancestor(int u, int d) {
        assert(int(dep.size()) == n);
        if (dep[u] < d) return -1;
        REP(k, log) if (d >> k & 1) u = par[k][u];
        return u;
    }

    int distance(int u, int v) {
        int p = lca(u, v);
        return dep[u] + dep[v] - 2 * dep[p];
    }
};