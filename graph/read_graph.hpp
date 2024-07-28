#pragma once

#include "graph/graph_template.hpp"

template <class T> Graph<T> read_graph(const int n, const int m, const bool weight = false, const bool directed = false, const int offset = 1) {
    Graph<T, directed> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a -= offset, b -= offset;
        T c = 1;
        if (weight) std::cin >> c;
        g.add_edge(a, b, c);
    }
    g.build();
    return g;
}

template <class T> Graph<T> read_parent(const int n, const bool weight = false, const bool directed = false, const int offset = 1) {
    Graph<T, directed> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        p -= offset;
        T c = 1;
        if (weight) std::cin >> c;
        g.add_edge(p, i, c);
    }
    g.build();
    return g;
}