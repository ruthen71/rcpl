#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <bits/stdc++.h>

#include "src/graph/tree_diameter.hpp"

int main() {
    int N;
    std::cin >> N;
    graph<long long> G(N);
    G.read_tree(true, 0);
    auto [d, path] = tree_diameter(G);
    std::cout << d << ' ' << path.size() + 1 << '\n';
    std::cout << path.front().from;
    for (auto &e : path) {
        std::cout << ' ' << e.to;
    }
    std::cout << '\n';
    return 0;
}