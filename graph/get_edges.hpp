#pragma once

#include "graph/graph_template.hpp"

template <class T> Edges<T> get_edges(Graph<T> &G) {
    int N = (int)G.size(), M = 0;
    for (int i = 0; i < N; i++) {
        for (auto &&e : G[i]) {
            M = std::max(M, e.id + 1);
        }
    }
    Edges<T> es(M);
    for (int i = N - 1; i >= 0; i--) {
        for (auto &&e : G[i]) {
            es[e.id] = e;
        }
    }
    return es;
}