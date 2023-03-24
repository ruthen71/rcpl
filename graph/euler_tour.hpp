#pragma once

#include "graph/graph_template.hpp"

// N = 5
// edges = [{0, 1}, {0, 2}, {2, 3}, {2, 4}]
//   0
//  / \
// 1   2
//    / \
//   3   4
// vertices = [0, 1, 0, 2, 3, 2, 4, 2, 0]
// vertex_id = [{0, 8}, {1, 1}, {3, 7}, {4, 4}, {6, 6}]
// edges = [0, 0+N, 1, 2, 2+N, 3, 3+N, 1+N]
// edge_id = [{0, 1}, {2, 7}, {3, 4}, {5, 6}]
// edges[vertex_id[i].first, vertex_id[i].second) = edges in subtree with root i
template <class T>
std::tuple<std::vector<int>, std::vector<std::pair<int, int>>, std::vector<int>, std::vector<std::pair<int, int>>>  //
euler_tour(Graph<T> &G, int root = 0) {
    // compiler bugs
    // const int n = (int)G.size();
    // fix
    int n = (int)G.size();
    std::vector<int> vertices, edges;
    std::vector<std::pair<int, int>> vertex_id(n), edge_id(n - 1);
    vertices.reserve(2 * (n - 1));
    edges.reserve(2 * (n - 1));

    auto dfs = [&](auto f, int cur, int par) -> void {
        vertex_id[cur].first = (int)vertices.size();
        vertices.push_back(cur);
        for (auto &&e : G[cur]) {
            if (e.to == par) continue;
            edge_id[e.id].first = (int)edges.size();
            edges.push_back(e.id);

            f(f, e.to, cur);
            vertices.push_back(cur);

            edge_id[e.id].second = (int)edges.size();
            edges.push_back(e.id + n);
        }
        vertex_id[cur].second = (int)vertices.size() - 1;
    };
    dfs(dfs, root, -1);

    assert((int)vertices.size() == 2 * n - 1);
    assert((int)edges.size() == 2 * (n - 1));
    return {vertices, vertex_id, edges, edge_id};
}