#pragma once

#include "graph/graph_template.hpp"

// Heavy-Light Decomposition (パスクエリ)
template <class T> struct HeavyLightDecomposition {
    int n;
    // dfs_size
    std::vector<int> subsize;  // subsize[v] = v を根とする部分木のサイズ
    std::vector<int> depth;    // depth[v] = v の深さ
    std::vector<int> parent;   // parent[v] = v の親の頂点番号

    // dfs_hld
    std::vector<int> vertices;  // Heavy-Edge から優先的に DFS したときの頂点の番号を並べたもの, n 要素
    std::vector<int> edges;     // Heavy-Edge から優先的に DFS したときの辺の番号を並べたもの, n - 1 要素
    std::vector<int> pathtop;   // pathtop[v] = v を含むパス上の祖先
    std::vector<int> subbegin;  // subbegin[v] = v を根とする部分木の頂点列の開始位置, vertices における v の登場位置
    std::vector<int> subend;    // subend[v] = v を根とする部分木の頂点列の終わり
    std::vector<int> eindex;    // eindex[e] = edges における e の登場位置

    // Graph<T> の辺の並べ替えを行うことに注意
    HeavyLightDecomposition(Graph<T>& g, const int root = 0) : n((int)(g.size())), subsize(n, 1), depth(n, 0), parent(n, -1), pathtop(n, -1), subbegin(n, -1), subend(n, -1), eindex(n - 1, -1) {
        // 部分木のサイズを計算
        auto dfs_size = [&](auto f, int cur, int par) -> void {
            parent[cur] = par;
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
                depth[e.to] = depth[cur] + 1;
                f(f, e.to, cur);
                subsize[cur] += subsize[e.to];
                if (subsize[e.to] > subsize[g[cur][0].to]) {
                    std::swap(e, g[cur][0]);
                }
            }
        };
        dfs_size(dfs_size, root, -1);

        // 頂点を並べる
        vertices.reserve(n);
        edges.reserve(n - 1);
        auto dfs_hld = [&](auto f, int cur, int par, int top) -> void {
            pathtop[cur] = top;
            subbegin[cur] = (int)(vertices.size());
            vertices.push_back(cur);

            for (auto&& e : g[cur]) {
                if (e.to == par) continue;
                eindex[e.id] = (int)(edges.size());
                edges.push_back(e.id);
                // top は heavy-edge に対してのみ引き継がれる
                f(f, e.to, cur, (e.to == g[cur][0].to ? top : e.to));
            }
            subend[cur] = (int)(vertices.size());
        };
        dfs_hld(dfs_hld, root, -1, root);
    }

    int lca(int u, int v) {
        // 同じパスまで上がる
        while (pathtop[u] != pathtop[v]) {
            if (subbegin[u] > subbegin[v]) {
                u = parent[pathtop[u]];
            } else {
                v = parent[pathtop[v]];
            }
        }
        if (subbegin[u] > subbegin[v]) std::swap(u, v);
        return u;
    }

    // u - v パスに対応する区間
    // is_edges = true なら edges に対応する区間, false なら vertices に対応する区間
    std::vector<std::pair<int, int>> path_query(int u, int v, const bool is_edges) {
        std::vector<std::pair<int, int>> res;
        while (pathtop[u] != pathtop[v]) {
            if (subbegin[u] > subbegin[v]) std::swap(u, v);
            // subbegin[u] <= subbegin[v]
            if (is_edges) {
                // edges に対応する区間なので pathtop[u] から parent[pathtop[u]] に行く辺も区間に加える
                res.emplace_back(subbegin[pathtop[v]] - 1, subbegin[v]);
            } else {
                res.emplace_back(subbegin[pathtop[v]], subbegin[v] + 1);
            }
            v = parent[pathtop[v]];
        }
        if (subbegin[u] > subbegin[v]) std::swap(u, v);
        if (is_edges) {
            res.emplace_back(subbegin[u], subbegin[v]);
        } else {
            res.emplace_back(subbegin[u], subbegin[v] + 1);
        }
        return res;
    }
};
