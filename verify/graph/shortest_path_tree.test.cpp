#define PROBLEM "https://atcoder.jp/contests/abc252/tasks/abc252_e"
#define IGNORE

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/dijkstra.hpp"
#include "graph/shortest_path_tree.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<long long>(N, M, true, false, 1);
    std::vector<int> s = {0};
    const long long INF = 1LL << 60;
    auto [d, p, r] = dijkstra(g, s, INF);
    auto sptree = shortest_path_tree(g, d, p);
    std::vector<int> ans;
    for (auto&& e : sptree.edges) ans.push_back(e.id + 1);
    for (int i = 0; i < (int)(ans.size()); i++) {
        std::cout << ans[i] << " \n"[i + 1 == (int)(ans.size())];
    }
    return 0;
}