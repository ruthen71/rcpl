#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>

#include "graph/graph_template.hpp"
#include "graph/read_graph.hpp"
#include "graph/strongly_connected_component.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<int>(N, M, false, true, 0);
    auto scc = strongly_connected_component(g);
    std::cout << scc.size() << '\n';
    for (auto&& vec : scc) {
        std::cout << vec.size();
        for (auto&& vi : vec) std::cout << ' ' << vi;
        std::cout << '\n';
    }
    return 0;
}