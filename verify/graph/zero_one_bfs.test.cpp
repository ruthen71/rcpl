#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include <iostream>
#include <algorithm>

#include "graph/read_graph.hpp"
#include "graph/zero_one_bfs.hpp"

int main() {
    constexpr int INF = 1 << 30;
    int n;
    std::cin >> n;
    auto g = read_graph<int>(n, n - 1, true, false, 0);
    for (int i = 0; i < n; i++) {
        std::vector<int> s = {i};
        auto [d, p, r] = zero_one_bfs(g, s, INF);
        int depth = *std::max_element(d.begin(), d.end());
        std::cout << depth << '\n';
    }
    return 0;
}