#pragma once

#include "graph/graph_template.hpp"

template <class T>
std::vector<std::vector<T>>  //
traveling_salesman_problem(Graph<T> &G, const T INF) {
    const int N = (int)G.size();
    const int N2 = 1 << N;

    std::vector dist(N, std::vector<T>(N, INF));
    for (int i = 0; i < N; i++) dist[i][i] = T(0);
    for (int i = 0; i < N; i++) {
        for (auto &&e : G[i]) {
            dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);
        }
    }

    std::vector<std::vector<T>> dp(N2, std::vector<T>(N, INF));
    dp[0][0] = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        for (int u = 0; u < N; u++) {
            if (~bit >> u & 1) continue;
            if (dp[bit][u] == INF) continue;
            for (int v = 0; v < N; v++) {
                if (bit >> v & 1) continue;
                if (dist[u][v] == INF) continue;
                dp[bit | (1 << v)][v] = std::min(dp[bit | (1 << v)][v], dp[bit][u] + dist[u][v]);
            }
        }
    }
    return dp;
}