#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>

#include "src/graph/dijkstra.hpp"
#include "src/graph/read_graph.hpp"

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
    std::vector<int> ans;
    int c = t;
    while (t != -1) {
        ans.push_back(t);
        t = p[t];
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << d[c] << ' ' << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size() - 1; i++) std::cout << ans[i] << ' ' << ans[i + 1] << '\n';
    return 0;
}