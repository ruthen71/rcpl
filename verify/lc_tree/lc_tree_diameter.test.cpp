#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <bits/stdc++.h>

#include "src/graph/read_graph.hpp"
#include "src/graph/tree_diameter.hpp"

int main() {
    int N;
    std::cin >> N;
    auto G = read_graph<long long>(N, N - 1, true, false, 0);
    auto [d, path] = tree_diameter<long long>(G);
    std::cout << d << ' ' << path.size() + 1 << '\n';
    std::cout << path.front().from;
    for (auto &e : path) {
        std::cout << ' ' << e.to;
    }
    std::cout << '\n';
    return 0;
}