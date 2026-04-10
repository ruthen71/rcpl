#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../graph/read_graph.hpp"
#include "../../graph/topological_sort.hpp"
#include "../../random/base.hpp"

void test1_lexicographical_order() {
    // 旧: https://atcoder.jp/contests/abc223/tasks/abc223_d
    const int n = 200;
    // 0 -> 1 -> n - 1
    // 0 -> 2 -> n - 1
    // をランダムな順序で張っていき, トポソする
    std::vector<std::pair<int, int>> p;
    for (int i = 1; i < n - 1; i++) {
        p.push_back({rng_auto.rand_int(), i});
    }
    std::sort(p.begin(), p.end());
    Graph<int> g(n, true);
    for (int i = 0; i < n - 2; i++) {
        g.add_edge(0, p[i].second);
        g.add_edge(p[i].second, n - 1);
    }
    auto vec = topological_sort(g);
    for (int i = 0; i < n; i++) {
        assert(vec[i] == i);
    }
}

int main() {
    test1_lexicographical_order();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
