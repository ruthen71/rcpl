#pragma once

#include "graph/graph_template.hpp"

template <class T, class Graph>
std::vector<std::vector<T>>  //
traveling_salesman_problem(Graph &G, const T INF) {
    int N = (int)G.size();
    int N2 = 1 << N;

    std::vector<std::vector<T>> dist(N, std::vector<T>(N, INF));
    for (int i = 0; i < N; i++) dist[i][i] = T(0);
    for (int i = 0; i < N; i++) {
        for (auto &&e : G[i]) {
            dist[e.from][e.to] = std::min(dist[e.from][e.to], e.cost);
        }
    }

    std::vector<std::vector<T>> dp(N2, std::vector<T>(N, INF));
    dp[0][0] = 0;
    for (int s = 0; s < (1 << N); s++) {
        for (int v = 0; v < N; v++) {
            if (s >> v & 1) continue;
            for (int u = 0; u < N; u++) {
                if (u == v) continue;
                dp[s | (1 << v)][v] = std::min(dp[s | (1 << v)][v], dp[s][u] + dist[u][v]);
            }
        }
    }
    return dp;
}

/**
 * @brief Traveling Salesman Problem (巡回セールスマン問題)
 * @docs docs/dp/traveling_salesman_problem.md
 */