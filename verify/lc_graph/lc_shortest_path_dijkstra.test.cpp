#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>

#include "src/graph/dijkstra.hpp"

int main() {
    int N, M, s, t;
    std::cin >> N >> M >> s >> t;
    graph<long long, true> G(N);
    G.read_graph(M, true, 0);
    std::vector<int> ss = {s};
    auto [d, p, r] = dijkstra(G, ss);
    if (d[t] == std::numeric_limits<long long>::max() / 4) {
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