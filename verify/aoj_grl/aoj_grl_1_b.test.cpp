#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <bits/stdc++.h>

#include "src/graph/bellman_ford.hpp"
#include "src/graph/read_graph.hpp"

int main() {
    int N, M, r;
    std::cin >> N >> M >> r;
    graph<int> G = read_graph<int>(N, M, true, true, 0);
    std::vector<int> s = {r};
    const int INF = 1 << 30;
    auto [dist, par, root] = bellman_ford(G, s, INF);
    int ans = *std::min_element(dist.begin(), dist.end());
    if (ans == -INF) {
        std::cout << "NEGATIVE CYCLE" << '\n';
    } else {
        for (int i = 0; i < N; i++) {
            if (dist[i] == INF) {
                std::cout << "INF" << '\n';
            } else {
                std::cout << dist[i] << '\n';
            }
        }
    }
    return 0;
}