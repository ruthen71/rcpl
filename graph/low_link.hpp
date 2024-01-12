#pragma once

#include "graph/graph_template.hpp"

template <class T> struct LowLink {
    int n;
    std::vector<int> ord, low, articulation;
    std::vector<std::pair<int, int>> bridge;  // edges {u, v} (u < v)

    LowLink(const Graph<T> &g) : n(int(g.size())), ord(n, -1), low(n, -1) {
        int k = 0;
        auto dfs = [&](auto f, int cur, int par) -> void {
            low[cur] = ord[cur] = k;
            k++;
            int cnt = 0;
            bool is_articulation = false;
            for (auto &e : g[cur]) {
                if (ord[e.to] == -1) {
                    cnt++;
                    f(f, e.to, cur);
                    low[cur] = std::min(low[cur], low[e.to]);
                    is_articulation |= (par != -1) && (ord[cur] <= low[e.to]);
                    if (ord[cur] < low[e.to]) {
                        bridge.emplace_back(std::minmax(cur, e.to));
                    }
                } else if (e.to != par) {
                    low[cur] = std::min(low[cur], ord[e.to]);
                }
            }
            is_articulation |= par == -1 && cnt > 1;
            if (is_articulation) articulation.push_back(cur);
            return;
        };
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) {
                dfs(dfs, i, -1);
            }
        }
    }
};