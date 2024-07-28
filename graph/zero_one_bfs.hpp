#pragma once

#include "graph/graph_template.hpp"

template <class T>
std::tuple<std::vector<T>, std::vector<int>, std::vector<int>>  //
zero_one_bfs(Graph<T>& g, std::vector<int>& s, const T inf) {
    const int n = (int)(g.size());
    std::vector<T> dist(n, inf);
    std::vector<int> par(n, -1), root(n, -1);

    std::deque<int> que;

    for (auto& v : s) {
        dist[v] = 0;
        root[v] = v;
        que.push_back(v);
    }

    while (!que.empty()) {
        auto v = que.front();
        que.pop_front();
        for (auto& e : g[v]) {
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