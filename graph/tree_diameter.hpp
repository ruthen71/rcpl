#pragma once

#include <utility>
#include "graph/graph_template.hpp"
#include "graph/restore_path.hpp"

// {直径の辺の重みの総和, 通る頂点集合}
template <class T> std::pair<T, std::vector<int>> tree_diameter(Graph<T>& g) {
    const int n = (int)(g.size());
    std::vector<int> parent(n, -1);
    std::vector<T> dist(n);

    auto dfs = [&](auto f, int cur, int par) -> void {
        for (auto&& e : g[cur]) {
            if (e.to == par) continue;
            dist[e.to] = dist[cur] + e.cost;
            parent[e.to] = cur;
            f(f, e.to, cur);
        }
        return;
    };

    dfs(dfs, 0, -1);
    int s = std::max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(n, 0);
    parent.assign(n, -1);
    dfs(dfs, s, -1);
    int t = std::max_element(dist.begin(), dist.end()) - dist.begin();
    auto path = restore_path(parent, t);
    return {dist[t], path};
}