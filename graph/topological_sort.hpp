#pragma once

#include "graph/graph_template.hpp"
template <class T> std::vector<int> topological_sort(Graph<T>& g) {
    const int n = (int)(g.size());
    std::vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto&& e : g[i]) indeg[e.to]++;
    }
    std::vector<int> res;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) res.push_back(i);
    }
    int i = 0;
    while (i < (int)res.size()) {
        // determine whether topological sort is unique or not
        // or by checking the length of g's longest path is n - 1
        // if ((int)res.size() - i != 1) return std::vector<int>();
        int v = res[i];
        i++;
        for (auto&& e : g[v]) {
            indeg[e.to]--;
            if (indeg[e.to] == 0) res.push_back(e.to);
        }
    }
    if ((int)res.size() != n) {
        return std::vector<int>();
    }
    return res;
}