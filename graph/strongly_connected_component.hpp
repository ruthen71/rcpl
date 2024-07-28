#pragma once

#include "graph/graph_template.hpp"

template <class T> std::vector<std::vector<int>> strongly_connected_component(Graph<T>& g) {
    const int n = int(g.size());
    int now_ord = 0, group_num = 0;
    std::vector<int> visited, low(n), ord(n, -1), ids(n);
    visited.reserve(n);
    auto dfs = [&](auto f, int cur) -> void {
        low[cur] = ord[cur] = now_ord++;
        visited.push_back(cur);
        for (auto& e : g[cur]) {
            if (ord[e.to] == -1) {
                f(f, e.to);
                low[cur] = std::min(low[cur], low[e.to]);
            } else {
                low[cur] = std::min(low[cur], ord[e.to]);
            }
        }
        if (low[cur] == ord[cur]) {
            while (true) {
                int u = visited.back();
                visited.pop_back();
                ord[u] = n;
                ids[u] = group_num;
                if (u == cur) break;
            }
            group_num++;
        }
    };
    for (int i = 0; i < n; i++) {
        if (ord[i] == -1) dfs(dfs, i);
    }
    for (auto& x : ids) {
        x = group_num - 1 - x;
    }
    std::vector<int> counts(group_num);
    for (auto& x : ids) counts[x]++;
    std::vector<std::vector<int>> groups(group_num);
    for (int i = 0; i < group_num; i++) {
        groups[i].reserve(counts[i]);
    }
    for (int i = 0; i < n; i++) {
        groups[ids[i]].push_back(i);
    }
    return groups;
}