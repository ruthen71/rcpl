#pragma once

#include "graph/graph_template.hpp"

#include <tuple>

// {dist, par, root}
template <class T> std::tuple<std::vector<T>, std::vector<int>, std::vector<int>> bellman_ford(Graph<T>& g, std::vector<int>& s, const T inf) {
    const int n = (int)(g.size());
    std::vector<T> dist(n, inf);
    std::vector<int> par(n, -1), root(n, -1);

    for (auto&& v : s) {
        dist[v] = 0;
        root[v] = v;
    }
    int loop_count = 0;

    while (true) {
        loop_count++;
        bool update = false;
        for (int cur = 0; cur < n; cur++) {
            if (dist[cur] == inf) continue;
            for (auto&& e : g[cur]) {
                T nd = std::max(-inf, dist[cur] + e.cost);
                if (dist[e.to] > nd) {
                    par[e.to] = cur;
                    root[e.to] = root[cur];
                    update = true;
                    if (loop_count >= n) nd = -inf;
                    dist[e.to] = nd;
                }
            }
        }
        if (!update) break;
    }
    return {dist, par, root};
}