#pragma once

#include "graph/graph_template.hpp"
#include "graph/lowest_common_ancestor.hpp"

template <class T> struct AuxiliaryTree {
    Graph<T> g;
    int n, root;
    std::vector<int> preorder, rank;
    std::vector<T> depth;
    LowestCommonAncestor<T> lca;

    AuxiliaryTree(const Graph<T>& g, int root = 0) : n((int)(g.size())), root(root), g(g), lca(g, root) {
        // DFSして行きがけ順に頂点を並べる
        depth.assign(n, T(0));
        rank.resize(n);
        auto dfs = [&](auto f, int cur, int par) -> void {
            preorder.push_back(cur);
            for (auto& e : g[cur]) {
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
        std::sort(begin(vs), end(vs), comp);
        for (int i = 0, vslen = (int)(vs.size()); i + 1 < vslen; i++) {
            vs.emplace_back(lca.lca(vs[i], vs[i + 1]));
        }
        std::sort(begin(vs), end(vs), comp);
        vs.erase(unique(begin(vs), end(vs)), end(vs));
        Graph<T> aux(vs.size());
        std::vector<int> rs;
        rs.push_back(0);
        for (int i = 1; i < (int)(vs.size()); i++) {
            int l = lca.lca(vs[rs.back()], vs[i]);
            while (vs[rs.back()] != l) rs.pop_back();
            aux[rs.back()].push_back(Edge(rs.back(), i, depth[vs[i]] - depth[vs[rs.back()]], i - 1));
            aux[i].push_back(Edge(i, rs.back(), depth[vs[i]] - depth[vs[rs.back()]], i - 1));
            rs.push_back(i);
        }
        return {aux, vs};
    }
};