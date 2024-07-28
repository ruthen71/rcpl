#pragma once

#include "graph/graph_template.hpp"

template <class T> std::vector<std::vector<T>> traveling_salesman_problem(Graph<T>& g, const T inf) {
    const int n = (int)(g.size());
    const int n2 = 1 << n;

    std::vector dp(n2, std::vector<T>(n, inf));
    dp[0][0] = 0;
    for (int bit = 0; bit < n2; bit++) {
        for (int u = 0; u < n; u++) {
            if (dp[bit][u] == inf) continue;
            for (auto&& e : g[u]) {
                if (bit >> e.to & 1) continue;
                dp[bit | (1 << e.to)][e.to] = std::min(dp[bit | (1 << e.to)][e.to], dp[bit][u] + e.cost);
            }
        }
    }
    return dp;
}