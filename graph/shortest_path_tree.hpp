#pragma once

#include <vector>

// https://atcoder.jp/contests/abc252/tasks/abc252_e
template <class T> std::vector<int> shortest_path_tree(Graph<T>& g, std::vector<int>& par) {
    const int n = (int)(g.size());
    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        for (auto& e : g[i]) {
            mp[{e.from, e.to}] = e.id;
        }
    }
    std::vector<int> res;
    res.reserve(n - 1);
    for (int i = 0; i < n; i++) {
        if (par[i] != -1) {
            res.push_back(mp[{par[i], i}]);
        }
    }
    assert(int(res.size()) == n - 1);
    return res;
}