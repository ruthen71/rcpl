#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/topological_sort.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<int>(N, M, false, true, 0);
    auto vec = topological_sort(g);
    std::cout << ((int)(vec.size()) != N) << '\n';
    return 0;
}