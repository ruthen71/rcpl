#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <bits/stdc++.h>

#include "src/graph/kruskal.hpp"
#include "src/graph/read_graph.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto G = read_graph<long long>(N, M, true, false, 0);
    auto [cost, es_set] = kruskal<long long>(G);
    std::cout << cost << '\n';
    return 0;
}