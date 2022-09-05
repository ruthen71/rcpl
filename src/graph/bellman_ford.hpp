#pragma once

#include "src/graph/template.hpp"

template <class Graph>
std::tuple<std::vector<typename Graph::cost_type>, std::vector<int>, std::vector<int>>  //
bellman_ford(Graph &G, std::vector<int> &s, const typename Graph::cost_type INF = std::numeric_limits<typename Graph::cost_type>::max() / 4) {
    using T = typename Graph::cost_type;

    int N = (int)G.size();
    std::vector<T> dist(N, INF);
    std::vector<int> par(N, -1), root(N, -1);

    for (auto &v : s) {
        dist[v] = 0;
        root[v] = v;
    }
    int loop_count = 0;

    while (true) {
        loop_count++;
        bool update = false;
        for (int cur = 0; cur < N; cur++) {
            if (dist[cur] == INF) continue;
            for (auto &e : G[cur]) {
                T nd = std::max(-INF, dist[cur] + e.cost);
                if (dist[e.to] > nd) {
                    par[e.to] = cur;
                    root[e.to] = root[cur];
                    update = true;
                    if (loop_count >= N) nd = -INF;
                    dist[e.to] = nd;
                }
            }
        }
        if (!update) break;
    }
    return {dist, par, root};
}

/**
 * @brief Bellman-Ford algorithm (ベルマンフォード法)
 * @docs docs/graph/bellman_ford.md
 */
