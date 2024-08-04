#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>

#include "graph/dijkstra.hpp"
#include "graph/read_graph.hpp"

int main() {
    int V, E, r;
    std::cin >> V >> E >> r;
    auto g = read_graph<long long>(V, E, true, true, 0);
    std::vector<int> s = {r};
    const long long INF = 1LL << 60;
    auto [dist, par, root] = dijkstra(g, s, INF);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            std::cout << "INF\n";
        } else {
            std::cout << dist[i] << '\n';
        }
    }
    return 0;
}