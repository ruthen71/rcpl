#pragma once

#include "graph/graph_template.hpp"

#include <vector>
#include <cassert>

// https://atcoder.jp/contests/abc252/tasks/abc252_e
// 最短経路木のうちの 1 つを返す
template <class T> Graph<T> shortest_path_tree(Graph<T>& g, std::vector<T>& dist, std::vector<int>& par) {
    const int n = (int)(g.size());
    Graph<T> sptree(n, true);
    for (auto&& e : g.edges) {
        if (par[e.to] == e.from and dist[e.from] + e.cost == dist[e.to]) {
            sptree.add_edge(e.from, e.to, e.cost, e.id);
        }
        if (!g.is_directed and par[e.from] == e.to and dist[e.to] + e.cost == dist[e.from]) {
            if (par[e.from] == e.to) sptree.add_edge(e.to, e.from, e.cost, e.id);
        }
    }
    return sptree;
}