#pragma once

#include "graph/graph_template.hpp"

template <class Graph> std::vector<int> topological_sort(Graph &G) {
    int N = (int)G.size();
    std::vector<int> indeg(N, 0);
    for (int i = 0; i < N; i++) {
        for (auto &e : G[i]) indeg[e.to]++;
    }
    std::vector<int> res;
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) res.push_back(i);
    }
    int i = 0;
    while (i < (int)res.size()) {
        int v = res[i];
        i++;
        for (auto &e : G[v]) {
            indeg[e.to]--;
            if (indeg[e.to] == 0) res.push_back(e.to);
        }
    }
    if ((int)res.size() != N) {
        return std::vector<int>();
    }
    return res;
}

/**
 * @brief Topological Sort (トポロジカルソート)
 * @docs docs/graph/topological_sort.md
 */
