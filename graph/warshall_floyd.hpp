#pragma once

#include "graph/graph_template.hpp"

template <class T> std::vector<std::vector<T>> warshall_floyd(Graph<T>& g, const T inf) {
    const int n = (int)(g.size());

    std::vector dist(n, std::vector<T>(n, inf));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
        for (auto&& e : g[i]) {
            dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == inf) continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == inf) continue;
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // 負閉路検出
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) dist[i][i] = -inf;
    }

    // 負閉路をもとに小さくできるパスについて調べる
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][k] == inf) continue;
            for (int j = 0; j < n; j++) {
                if (dist[k][j] == inf) continue;
                T nd = dist[i][k] + dist[k][j];
                if (dist[i][k] == -inf or dist[k][j] == -inf) nd = -inf;
                dist[i][j] = std::min(dist[i][j], nd);
            }
        }
    }
    return dist;
}