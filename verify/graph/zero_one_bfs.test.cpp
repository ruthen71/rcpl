#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B"

#include <iostream>
#include <algorithm>

#include "graph/read_graph.hpp"
#include "graph/tree_diameter.hpp"
#include "graph/zero_one_bfs.hpp"

int main() {
    constexpr int INF = 1 << 30;
    int n;
    std::cin >> n;
    auto g = read_graph<int>(n, n - 1, true, false, 0);
    auto [cost, path] = tree_diameter(g);
    int s = path.front(), t = path.back();
    std::vector<int> ss = {s}, st = {t};
    auto [dist1, par1, root1] = zero_one_bfs(g, ss, INF);
    auto [dist2, par2, root2] = zero_one_bfs(g, st, INF);
    for (int i = 0; i < n; i++) std::cout << std::max(dist1[i], dist2[i]) << '\n';
    return 0;
}