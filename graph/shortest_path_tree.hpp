#pragma once

#include <vector>
#include <cassert>
#include "graph/graph_template.hpp"

// https://atcoder.jp/contests/abc252/tasks/abc252_e
// 最短経路木のうちの 1 つを返す
template <class T> Graph<T> shortest_path_tree(Graph<T>& g, std::vector<int>& par) {
    const int n = (int)(g.size());

    // 逆向きの辺を貼ったグラフ
    Graph<T> rg(n, true);
    for (int v = 0; v < n; v++) {
        for (auto&& e : g[v]) {
            rg.add_edge(e.to, e.from, e.cost, e.id);
        }
    }

    Graph<T> sptree(n, true);
    for (int v = 0; v < n; v++) {
        if (par[v] == -1) continue;
        for (auto&& e : rg[v]) {
            if (e.to == par[v]) {
                sptree.add_edge(e.to, e.from, e.cost, e.id);
            }
        }
    }
    return sptree;
}