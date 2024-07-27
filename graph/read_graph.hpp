#pragma once

#include "graph/graph_template.hpp"

template <class T> Graph<T> read_graph(const int n, const int m, const bool weight = false, const bool directed = false, const int offset = 1) {
    Graph<T> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a -= offset, b -= offset;
        if (weight) {
            T c;
            std::cin >> c;
            if (!directed) g[b].push_back(Edge(b, a, c, i));
            g[a].push_back(Edge(a, b, c, i));
        } else {
            // c = 1
            if (!directed) g[b].push_back(Edge(b, a, T(1), i));
            g[a].push_back(Edge(a, b, T(1), i));
        }
    }
    return g;
}

template <class T> Graph<T> read_parent(const int n, const bool weight = false, const bool directed = false, const int offset = 1) {
    Graph<T> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        p -= offset;
        if (weight) {
            T c;
            std::cin >> c;
            if (!directed) g[i].push_back(Edge(i, p, c, i - 1));
            g[p].push_back(Edge(p, i, c, i - 1));
        } else {
            // c = 1
            if (!directed) g[i].push_back(Edge(i, p, T(1), i - 1));
            g[p].push_back(Edge(p, i, T(1), i - 1));
        }
    }
    return g;
}