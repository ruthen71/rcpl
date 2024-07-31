#define PROBLEM "https://atcoder.jp/contests/abc359/tasks/abc359_g"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/auxiliary_tree.hpp"

int main() {
    int N;
    std::cin >> N;
    auto g = read_graph<int>(N, N - 1);
    std::vector<int> A(N);
    std::vector<std::vector<int>> vs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
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
    std::cout << ans << '\n';
    return 0;
}