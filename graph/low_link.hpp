#pragma once

#include "graph/graph_template.hpp"

template <class T> struct LowLink {
    int n;
    std::vector<int> ord, low;
    std::vector<std::vector<int>> dfs_tree;
    std::vector<int> articulations;
    std::vector<std::pair<int, int>> bridges;  // edges {u, v} (u < v)
    std::vector<int> roots;

    LowLink(Graph<T>& g) : n((int)(g.size())), ord(n, -1), low(n, -1), dfs_tree(n) {
        int ord_id = 0;
        auto dfs = [&](auto f, int cur, int par) -> void {
            low[cur] = ord[cur] = ord_id++;
            bool is_articulation = false;
            for (auto&& e : g[cur]) {
                if (ord[e.to] == -1) {
                    // DFS 木上の辺に対する処理
                    f(f, e.to, cur);
                    dfs_tree[cur].push_back(e.to);
                    // e が DFS 木に含まれているので後退辺をすでに通った low[e.to] を使って更新して良い
                    low[cur] = std::min(low[cur], low[e.to]);
                    is_articulation |= (par != -1) and (ord[cur] <= low[e.to]);
                    if (ord[cur] < low[e.to]) {
                        bridges.emplace_back(std::minmax(cur, e.to));
                    }
                } else if (e.to != par) {
                    // 後退辺に対する処理
                    // Todo: multiple edges
                    low[cur] = std::min(low[cur], ord[e.to]);
                }
            }
            is_articulation |= par == -1 and (int)(dfs_tree[cur].size()) > 1;
            if (is_articulation) articulations.push_back(cur);
            return;
        };
        for (int i = 0; i < n; i++) {
            if (ord[i] == -1) {
                roots.push_back(i);
                dfs(dfs, i, -1);
            }
        }
    }

    // 連結成分数
    int count_components() { return (int)(roots.size()); }

    // 頂点 x を取り除くともともと 1 つだった連結成分がいくつになるか
    int count_components_remove(int x) {
        if (std::binary_search(roots.begin(), roots.end(), x)) {
            return (int)(dfs_tree[x].size());
        } else {
            int c = 0;
            for (auto&& e : dfs_tree[x]) {
                if (ord[x] <= low[e]) c++;
            }
            // 親の分で +1
            return c + 1;
        }
    }
};