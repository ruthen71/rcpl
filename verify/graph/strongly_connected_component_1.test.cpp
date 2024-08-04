#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/strongly_connected_component.hpp"

int main() {
    int V, E;
    std::cin >> V >> E;
    auto g = read_graph<int>(V, E, false, true, 0);
    auto res = strongly_connected_component(g);
    std::vector<int> id(V);
    for (int i = 0; i < (int)(res.size()); i++) {
        for (auto&& e : res[i]) id[e] = i;
    }
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; i++) {
        int u, v;
        std::cin >> u >> v;
        std::cout << (id[u] == id[v]) << '\n';
    }
    return 0;
}