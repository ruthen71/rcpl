#pragma once

#include "graph/graph_template.hpp"

template <class T> Graph<T> read_graph(int n, int m, const bool weight = false, const bool directed = false, const int offset = 1) {
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

std::tuple<Graph<int>, std::vector<std::vector<int>>, std::vector<std::pair<int, int>>> read_grid(const int h, const int w, std::string rel = ".#") {
    std::vector<std::string> s(h);
    std::vector id(h, std::vector<int>(w, -1));
    std::vector<std::pair<int, int>> loc;
    int n = 0;
    for (int i = 0; i < h; i++) {
        std::cin >> s[i];
        for (int j = 0; j < w; j++) {
            if (s[i][j] == rel[1]) {
                id[i][j] = n++;
                loc.emplace_back(i, j);
            }
        }
    }
    int m = 0;
    Graph<int> g(n);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == rel[1]) {
                if (i + 1 < h and s[i + 1][j] == rel[1]) {
                    g[id[i][j]].push_back(Edge(id[i][j], id[i + 1][j], 1, m));
                    g[id[i + 1][j]].push_back(Edge(id[i + 1][j], id[i][j], 1, m++));
                }
                if (j + 1 < w and s[i][j + 1] == rel[1]) {
                    g[id[i][j]].push_back(Edge(id[i][j], id[i][j + 1], 1, m));
                    g[id[i][j + 1]].push_back(Edge(id[i][j + 1], id[i][j], 1, m++));
                }
            }
        }
    }
    return {g, id, loc};
}