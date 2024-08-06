#pragma once

#include "graph/graph_template.hpp"

#include <tuple>

// Euler Tour
// O(n + m)
// 辺と頂点のうち, 変化させるものを要素と見て, そうでないもので要素を区切ると考えると良い
template <class T> struct EulerTour {
    int n;
    std::vector<int> vertices;  // DFS で訪問する頂点の番号を並べたもの, 2 * n - 1 要素
    std::vector<int> edges;     // DFS で通る辺の番号を並べたもの, 2 * n - 2 要素
    std::vector<int> dir;       // DFS で通る辺の向きが 0 = 子供方向, 1 = 親方向
    std::vector<int> vsl;       // vsl[v]: vertices[i] = v となる i の最小値
    std::vector<int> vsr;       // vsr[v]: vertices[i] = v となる i の最大値
    std::vector<int> esl;       // esl[e]: edges[i] = e かつ dir[i] = 0 となる i
    std::vector<int> esr;       // esr[e]: edges[i] = e かつ dir[i] = 1 となる i

    EulerTour(Graph<T>& g, const int root = 0) : n((int)(g.size())), vsl(n, 2 * n - 1), vsr(n, -1), esl(n - 1, -1), esr(n - 1, -1) {
        vertices.reserve(2 * n - 1);
        edges.reserve(2 * n - 2);
        dir.reserve(2 * n - 2);

        auto dfs = [&](auto f, int cur, int par) -> void {
            for (auto&& e : g[cur]) {
                if (e.to == par) continue;
                // 頂点を追加
                vertices.emplace_back(cur);
                // 子供方向の辺を追加
                edges.emplace_back(e.id);
                dir.emplace_back(0);
                // DFS
                f(f, e.to, cur);
                // 親方向の辺を追加
                edges.emplace_back(e.id);
                dir.emplace_back(1);
            }
            // 頂点を追加
            vertices.emplace_back(cur);
        };
        dfs(dfs, root, -1);
        for (int i = 2 * n - 2; i >= 0; i--) vsl[vertices[i]] = i;
        for (int i = 0; i < 2 * n - 1; i++) vsr[vertices[i]] = i;
        for (int i = 0; i < 2 * n - 2; i++) (dir[i] == 0 ? esl[edges[i]] : esr[edges[i]]) = i;
    }
};