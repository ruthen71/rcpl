#pragma once

#include "data_structure/unionfind.hpp"
#include "graph/graph_template.hpp"

#include <algorithm>

template <class T> std::pair<T, std::vector<Edge<T>>> kruskal(Graph<T>& g) {
    auto es = g.edges;
    std::sort(es.begin(), es.end());
    const int n = (int)(g.size());
    UnionFind uf(n);
    T ret = 0;
    std::vector<Edge<T>> es_ret;
    es_ret.reserve(n - 1);
    for (auto&& e : es) {
        if (!uf.same(e.from, e.to)) {
            ret += e.cost;
            uf.merge(e.from, e.to);
            es_ret.push_back(e);
        }
    }
    return {ret, es_ret};
}