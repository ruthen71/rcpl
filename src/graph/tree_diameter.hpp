#pragma once

#include "src/graph/template.hpp"

template <class Graph>
std::pair<typename Graph::cost_type, std::vector<typename Graph::edge_type>>  //
tree_diameter(Graph &G) {
    using T = typename Graph::cost_type;
    std::vector<int> to(G.size(), -1);

    auto dfs = [&](auto f, int cur, int par) -> std::pair<T, int> {
        std::pair<T, int> ret = {0, cur};
        for (auto &e : G[cur]) {
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
    std::vector<typename Graph::edge_type> path;
    while (cur != t.second) {
        for (auto &e : G[cur]) {
            if (to[cur] == e.to) {
                path.emplace_back(e);
            }
        }
        cur = to[cur];
    }
    return {t.first, path};
}

/**
 * @brief Tree Diameter (木の直径)
 * @docs docs/graph/tree_diameter.md
 */
