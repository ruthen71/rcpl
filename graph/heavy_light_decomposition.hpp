#pragma once

#include "graph/graph_template.hpp"

// Heavy-Light Decomposition
// パスクエリに対応
// 辺の並べ替えを内部で行うので注意
template <class T> struct HeavyLightDecomposition {
    int n;
    std::vector<int> subsize;   // subsize[v] = v を根とする部分木のサイズ
    std::vector<int> vertices;  // Heavy-Edge から優先的に DFS したときの頂点を訪問順に並べたもの
    std::vector<int> parent;    // 親の頂点
    std::vector<int> pathtop;   // 各頂点を含むパス上の最も祖先の頂点
    std::vector<int> indexes;   // 各頂点が vertives で何番目に登場するか

    HeavyLightDecomposition(Graph<T>& g, const int root = 0) : n((int)(g.size())), subsize(n, 1), parent(n, -1), pathtop(n, -1), indexes(n, -1) {
        // 部分木のサイズを計算
        auto dfs_size = [&](auto f, int cur, int par) -> void {
            // 親方向への辺を末尾に移動
            for (int i = 0; i < (int)(g[cur].size()); i++) {
                if (g[cur][i].to == par) {
                    std::swap(g[cur][i], g[cur][(int)(g[cur].size()) - 1]);
                    break;
                }
            }
            // 部分木のサイズが最大のものを先頭に移動
            for (auto&& e : g[cur]) {
                if (e.to == par) continue;
                f(f, e.to, cur);
                subsize[cur] += subsize[e.to];
                if (subsize[e.to] > subsize[g[cur][0].to]) {
                    std::swap(e, g[cur][0]);
                }
            }
        };
        dfs_size(dfs_size, root, -1);

        // 頂点を並べる
        auto dfs_hld = [&](auto f, int cur, int par, int top) -> void {
            parent[cur] = par;
            pathtop[cur] = top;
            indexes[cur] = (int)(vertices.size());
            vertices.emplace_back(cur);

            for (int i = 0; i < (int)(g[cur].size()); i++) {
                if (g[cur][i].to == par) continue;
                // top は heavy-edge に対してのみ引き継がれる
                f(f, g[cur][i].to, cur, (i == 0 ? top : g[cur][i].to));
            }
        };
        dfs_hld(dfs_hld, root, -1, root);
    }

    int lca(int u, int v) {
        // 同じパスまで上がる
        while (pathtop[u] != pathtop[v]) {
            if (indexes[u] > indexes[v]) {
                u = parent[pathtop[u]];
            } else {
                v = parent[pathtop[v]];
            }
        }
        if (indexes[u] > indexes[v]) std::swap(u, v);
        return u;
    }

    // u - v パスに操作を行うときに使う区間を列挙する
    std::vector<std::pair<int, int>> query(int u, int v) {
        std::vector<std::pair<int, int>> res;
        while (pathtop[u] != pathtop[v]) {
            // 辺に対する操作なので pathtop[u] から parent[pathtop[u]] に行く辺も区間に加える
            if (indexes[u] > indexes[v]) {
                res.emplace_back(indexes[pathtop[u]] - 1, indexes[u]);
                u = parent[pathtop[u]];
            } else {
                res.emplace_back(indexes[pathtop[v]] - 1, indexes[v]);
                v = parent[pathtop[v]];
            }
        }
        if (indexes[u] > indexes[v]) std::swap(u, v);
        res.emplace_back(indexes[u], indexes[v]);
        return res;
    }
};
