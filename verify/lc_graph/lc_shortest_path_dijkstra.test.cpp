#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>

#include "graph/dijkstra.hpp"
#include "graph/read_graph.hpp"
#include "graph/restore_path.hpp"

int main() {
    int N, M, s, t;
    std::cin >> N >> M >> s >> t;
    auto G = read_graph<long long>(N, M, true, true, 0);
    std::vector<int> ss = {s};
    const long long INF = 1LL << 60;
    auto [d, p, r] = dijkstra(G, ss, INF);
    if (d[t] == INF) {
        std::cout << -1 << '\n';
        return 0;
    }
    auto ans = restore_path(p, t);
    std::cout << d[t] << ' ' << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; i++) std::cout << ans[i] << ' ' << ans[i + 1] << '\n';
    return 0;
}