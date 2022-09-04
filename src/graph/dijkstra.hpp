#pragma once

#include "src/graph/template.hpp"

template <class Graph>
std::tuple<std::vector<typename Graph::cost_type>, std::vector<int>, std::vector<int>>  //
dijkstra(Graph &G, std::vector<int> &s) {
    using T = typename Graph::cost_type;
    const T INF = std::numeric_limits<T>::max() / 4;

    int N = (int)G.size();
    std::vector<T> dist(N, INF);
    std::vector<int> par(N, -1), root(N, -1);

    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> que;

    for (auto &v : s) {
        dist[v] = 0;
        root[v] = v;
        que.emplace(T(0), v);
    }

    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (dist[v] != d) continue;  // dist[v] < d
        for (auto &e : G[v]) {
            if (dist[e.to] > d + e.cost) {
                dist[e.to] = d + e.cost;
                root[e.to] = root[v];
                par[e.to] = v;
                que.emplace(dist[e.to], e.to);
            }
        }
    }
    return {dist, par, root};
}

/**
 * @brief Dijkstra's algorithm (ダイクストラ法)
 * @docs docs/graph/dijkstra.md
 */
