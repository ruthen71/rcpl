#pragma once

#include "src/graph/graph_template.hpp"

template <class T, class Graph>
std::tuple<std::vector<T>, std::vector<int>, std::vector<int>>  //
bfs01(Graph &G, std::vector<int> &s, const T INF) {
    int N = (int)G.size();
    std::vector<T> dist(N, INF);
    std::vector<int> par(N, -1), root(N, -1);

    std::deque<int> que;

    for (auto &v : s) {
        dist[v] = 0;
        root[v] = v;
        que.push_back(v);
    }

    while (!que.empty()) {
        auto v = que.front();
        que.pop_front();
        for (auto &e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                root[e.to] = root[v];
                par[e.to] = v;
                if (e.cost != 0) {
                    que.push_back(e.to);
                } else {
                    que.push_front(e.to);
                }
            }
        }
    }
    return {dist, par, root};
}

/**
 * @brief 01-BFS
 * @docs docs/graph/bfs01.md
 */
