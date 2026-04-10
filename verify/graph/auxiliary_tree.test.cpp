#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <iostream>

#include "../../graph/auxiliary_tree.hpp"
#include "../../graph/read_graph.hpp"

long long solve(Graph<int> g, std::vector<int> A) {
    const int N = g.n;
    std::vector<std::vector<int>> vs(N);
    for (int i = 0; i < N; i++) {
        A[i]--;
        vs[A[i]].push_back(i);
    }
    AuxiliaryTree<int> aux(g);
    long long ans = 0;
    for (int col = 0; col < N; col++) {
        auto vec = vs[col];
        if ((int)(vec.size()) == 0) continue;
        auto res = aux.get(vec);
        auto caux = res.first;
        auto label = res.second;
        const int M = (int)(vec.size());
        std::vector<int> dp((int)(label.size()));
        auto rec = [&](auto f, int cur, int par) -> void {
            dp[cur] = (A[label[cur]] == col);
            for (auto&& e : caux[cur]) {
                if (e.to == par) continue;
                f(f, e.to, cur);
                dp[cur] += dp[e.to];
                ans += (long long)e.cost * dp[e.to] * (M - dp[e.to]);
            }
        };
        rec(rec, 0, -1);
    }
    return ans;
}

void test1_sample1() {
    const int n = 4;
    Graph<int> g(n, false);
    g.add_edge(2, 3);
    g.add_edge(3, 1);
    g.add_edge(0, 1);
    std::vector<int> a = {2, 1, 1, 2};
    assert(solve(g, a) == 4);
}

void test2_sample2() {
    const int n = 8;
    Graph<int> g(n, false);
    g.add_edge(7, 5);
    g.add_edge(2, 7);
    g.add_edge(0, 3);
    g.add_edge(6, 7);
    g.add_edge(3, 4);
    g.add_edge(2, 3);
    g.add_edge(7, 1);
    std::vector<int> a = {1, 2, 2, 2, 3, 1, 1, 3};
    assert(solve(g, a) == 19);
}

int main() {
    // https://atcoder.jp/contests/abc359/tasks/abc359_g
    test1_sample1();
    test2_sample2();
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << '\n';
    return 0;
}
