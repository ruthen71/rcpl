#pragma once

#include "src/data_structure/unionfind.hpp"
#include "src/graph/get_edges.hpp"
#include "src/graph/graph_template.hpp"

template <class T, class Graph> std::pair<T, edges<T>> kruskal(Graph &G) {
    auto es = get_edges<T>(G);
    sort(es.begin(), es.end(), [](edge<T> a, edge<T> b) { return a.cost < b.cost; });
    int N = (int)G.size();
    unionfind uf(N);
    T ret = 0;
    edges<T> es_ret;
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

/**
 * @brief Kruskal's algorithm (クラスカル法)
 * @docs docs/graph/kruskal.md
 */
