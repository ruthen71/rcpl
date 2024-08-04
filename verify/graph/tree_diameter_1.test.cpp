#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/tree_diameter.hpp"

int main() {
    int N;
    std::cin >> N;
    auto g = read_graph<long long>(N, N - 1, true, false, 0);
    auto [d, path] = tree_diameter(g);
    std::cout << d << '\n';
    return 0;
}