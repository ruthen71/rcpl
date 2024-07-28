#pragma once

#include "graph/graph_template.hpp"
// {直径の辺の重みの総和, 通る頂点集合}
template <class T> std::pair<T, std::vector<Edge<T>>> tree_diameter(Graph<T>& g) {
    std::vector<int> to(g.size(), -1);

    auto dfs = [&](auto f, int cur, int par) -> std::pair<T, int> {
        std::pair<T, int> ret = {0, cur};
        for (auto& e : g[cur]) {
            if (e.to == par) continue;
            auto cost = f(f, e.to, cur);
            cost.first += e.cost;
            if (ret.first < cost.first) {
                ret = cost;
                to[cur] = e.to;
            }
        }
        return ret;
    };

    auto s = dfs(dfs, 0, -1);
    auto t = dfs(dfs, s.second, -1);

    int cur = s.second;
    std::vector<Edge<T>> path;
    while (cur != t.second) {
        for (auto& e : G[cur]) {
            if (to[cur] == e.to) {
                path.emplace_back(e);
            }
        }
        cur = to[cur];
    }
    return {t.first, path};
}