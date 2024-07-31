#pragma once

#include "graph/graph_template.hpp"
#include "graph/lowest_common_ancestor.hpp"

#include <algorithm>

template <class T> struct AuxiliaryTree {
    int n, root;
    std::vector<int> preorder, rank;
    std::vector<T> depth;
    LowestCommonAncestor<T> lca;

    AuxiliaryTree(Graph<T>& g, const int root = 0) : n((int)(g.size())), root(root), depth(n, T(0)), rank(n), lca(g, root) {
        // DFS して行きがけ順に頂点を並べる
        auto dfs = [&](auto f, int cur, int par) -> void {
            preorder.push_back(cur);
            for (auto&& e : g[cur]) {
                if (e.to == par) continue;
                depth[e.to] = depth[cur] + e.cost;
                f(f, e.to, cur);
            }
        };
        dfs(dfs, root, -1);
        for (int i = 0; i < n; i++) rank[preorder[i]] = i;
    }

    // (圧縮後のグラフ, グラフの頂点番号 -> 元のグラフの頂点番号 の対応表)
    std::pair<Graph<T>, std::vector<int>> get(std::vector<int> vs) {
        if (vs.empty()) return {};

        auto comp = [&](int i, int j) -> bool { return rank[i] < rank[j]; };
        std::sort(vs.begin(), vs.end(), comp);
        for (int i = 0, vslen = (int)(vs.size()); i + 1 < vslen; i++) {
            vs.emplace_back(lca.lca(vs[i], vs[i + 1]));
        }
        std::sort(vs.begin(), vs.end(), comp);
        vs.erase(unique(vs.begin(), vs.end()), vs.end());

        // Auxiliary Tree
        Graph<T> aux(vs.size(), false);
        std::vector<int> rs;
        rs.push_back(0);

        // i は新しい頂点番号, vs[i] はもとの頂点番号
        // vs は Auxiliary Tree の行きがけ順になっているのでループが DFS になっている
        for (int i = 1; i < (int)(vs.size()); i++) {
            // LCA まで遡ってから辺を追加する
            int l = lca.lca(vs[rs.back()], vs[i]);
            while (vs[rs.back()] != l) rs.pop_back();
            aux.add_edge(rs.back(), i, depth[vs[i]] - depth[vs[rs.back()]]);
            rs.push_back(i);
        }
        aux.build();
        return {aux, vs};
    }
};