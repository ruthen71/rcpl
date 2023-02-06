#pragma once

#include "data_structure/unionfind.hpp"
#include "graph/get_edges.hpp"
#include "graph/graph_template.hpp"

template <class T> std::pair<T, Edges<T>> kruskal(Graph<T> &G) {
    auto es = get_edges<T>(G);
    std::sort(es.begin(), es.end(), [](Edge<T> a, Edge<T> b) { return a.cost < b.cost; });
    int N = (int)G.size();
    UnionFind uf(N);
    T ret = 0;
    Edges<T> es_ret;
    es_ret.reserve(N - 1);
    for (auto &&e : es) {
        if (!uf.same(e.from, e.to)) {
            ret += e.cost;
            uf.merge(e.from, e.to);
            es_ret.push_back(e);
        }
    }
    return {ret, es_ret};
}