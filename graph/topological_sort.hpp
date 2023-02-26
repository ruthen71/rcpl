#pragma once

#include "graph/graph_template.hpp"
template <class T> std::vector<int> topological_sort(Graph<T> &G) {
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
        // determine whether topological sort is unique or not
        // or by checking the length of G's longest path is N - 1
        // if ((int)res.size() - i != 1) return std::vector<int>();
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