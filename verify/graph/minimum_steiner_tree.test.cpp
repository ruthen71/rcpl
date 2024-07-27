#define PROBLEM "https://yukicoder.me/problems/no/114"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/minimum_steiner_tree.hpp"

int main() {
    int N, M, T;
    std::cin >> N >> M >> T;
    auto g = read_graph<long long>(N, M, true);
    std::vector<int> terminals(T);
    for (int i = 0; i < T; i++) {
        std::cin >> terminals[i];
        terminals[i]--;
    }
    if (T <= 15) {
        auto dp = minimum_steiner_tree(g, terminals, 1'000'000'000'000'000'000LL);
        std::cout << dp.back()[terminals[0]] << '\n';
    } else {
        std::cout << minimum_steiner_tree_mst(g, terminals, 1'000'000'000'000'000'000LL) << '\n';
    }
    return 0;
}