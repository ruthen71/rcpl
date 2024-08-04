#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_d"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/topological_sort.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<int>(N, M, false, true, 1);
    auto vec = topological_sort(g);
    if ((int)(vec.size()) != N) {
        std::cout << -1 << '\n';
    } else {
        for (int i = 0; i < N; i++) std::cout << vec[i] + 1 << " \n"[i + 1 == N];
    }
    return 0;
}