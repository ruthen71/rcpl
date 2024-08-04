#pragma once

#include "graph/graph_template.hpp"

#include <cassert>
#include <queue>

// topological sort が存在するなら, 辞書順最小のものを返す
// O((n + m) log n)
// topological sort が一意に定まる <=> 最長パスの長さが n - 1
template <class T> std::vector<int> topological_sort(Graph<T>& g) {
    const int n = (int)(g.size());
    assert(n > 0);
    std::vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto&& e : g[i]) indeg[e.to]++;
    }
    // O(n + m) にしたい場合は std::queue にする
    std::priority_queue<int, std::vector<int>, std::greater<>> que;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            que.push(i);
        }
    }
    std::vector<int> res;
    while (!que.empty()) {
        auto v = que.top();
        que.pop();
        res.push_back(v);
        for (auto&& e : g[v]) {
            indeg[e.to]--;
            if (indeg[e.to] == 0) que.push(e.to);
        }
    }
    // topological sort できない
    if ((int)(res.size()) != n) {
        return std::vector<int>();
    }
    return res;
}