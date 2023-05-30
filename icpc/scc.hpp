#pragma once

#include "icpc/template.hpp"

// https://onlinejudge.u-aizu.ac.jp/problems/2748

V<V<int>> scc(V<V<int>>& g) {
    int n = int(g.size());
    int now_ord = 0, group_num = 0;
    V<int> vis, low(n), ord(n, -1), ids(n);
    vis.reserve(n);
    auto dfs = [&](auto f, int c) -> void {
        low[c] = ord[c] = now_ord++;
        vis.push_back(c);
        for (auto& e : g[c]) {
            if (ord[e] == -1) {
                f(f, e);
                low[c] = min(low[c], low[e]);
            } else {
                low[c] = min(low[c], ord[e]);
            }
        }
        if (low[c] == ord[c]) {
            while (true) {
                int u = vis.back();
                vis.pop_back();
                ord[u] = n;
                ids[u] = group_num;
                if (u == c) break;
            }
            group_num++;
        }
    };
    REP(i, n) if (ord[i] == -1) dfs(dfs, i);
    V<V<int>> res(group_num);
    REP(i, n) res[group_num - 1 - ids[i]].push_back(i);
    return res;
}