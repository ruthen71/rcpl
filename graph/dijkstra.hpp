#pragma once

#include "graph/graph_template.hpp"

template <class T, class Graph>
std::tuple<std::vector<T>, std::vector<int>, std::vector<int>>  //
dijkstra(Graph &G, std::vector<int> &s, const T INF) {
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
