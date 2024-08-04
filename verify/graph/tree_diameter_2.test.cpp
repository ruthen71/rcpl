#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/tree_diameter.hpp"

int main() {
    int N;
    std::cin >> N;
    auto g = read_graph<long long>(N, N - 1, true, false, 0);
    auto [d, path] = tree_diameter(g);
    std::cout << d << ' ' << path.size() << '\n';
    for (int i = 0; i < (int)(path.size()); i++) {
        std::cout << path[i] << " \n"[i + 1 == (int)(path.size())];
    }
    return 0;
}