#pragma once

// https://atcoder.jp/contests/abc252/tasks/abc252_e
template <class T> std::vector<int> shortest_path_tree(Graph<T> &G, std::vector<int> &par) {
    const int N = int(G.size());
    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < N; i++) {
        for (auto &e : G[i]) {
            mp[{e.from, e.to}] = e.id;
        }
    }
    std::vector<int> res;
    res.reserve(N - 1);
    for (int i = 0; i < N; i++) {
        if (par[i] != -1) {
            res.push_back(mp[{par[i], i}]);
        }
    }
    assert(int(res.size()) == N - 1);
    return res;
}