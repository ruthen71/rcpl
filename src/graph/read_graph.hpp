#pragma once

#include "src/graph/graph_template.hpp"

template <class T> graph<T> read_graph(int N, int M, const bool weight = false, const bool directed = false, const int offset = 1) {
    graph<T> G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a -= offset, b -= offset;
        if (weight) {
            T c;
            std::cin >> c;
            if (!directed) G[b].push_back(edge(b, a, c, i));
            G[a].push_back(edge(a, b, c, i));
        } else {
            // c = 1
            if (!directed) G[b].push_back(edge(b, a, 1, i));
            G[a].push_back(edge(a, b, 1, i));
        }
    }
    return G;
}