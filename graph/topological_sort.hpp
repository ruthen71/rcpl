#pragma once

#include <cassert>
#include "graph/graph_template.hpp"

template <class T> std::vector<int> topological_sort(Graph<T>& g) {
    const int n = (int)(g.size());
    assert(n > 0);
    std::vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto&& e : g[i]) indeg[e.to]++;
    }
    std::vector<int> res;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) res.push_back(i);
    }
    for (int i = 0; i < (int)(res.size()); i++) {
        int v = res[i];
        for (auto&& e : g[v]) {
            indeg[e.to]--;
            if (indeg[e.to] == 0) res.push_back(e.to);
        }
    }
    // topological sort が一意に定まる <=> 最長パスの長さが n - 1
    if ((int)(res.size()) != n) {
        return std::vector<int>();
    }
    return res;
}