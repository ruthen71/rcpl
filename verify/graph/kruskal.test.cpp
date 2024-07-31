#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>

#include "graph/kruskal.hpp"
#include "graph/read_graph.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<long long>(N, M, true, false, 0);
    auto [cost, es_set] = kruskal<long long>(g);
    std::cout << cost << '\n';
    return 0;
}