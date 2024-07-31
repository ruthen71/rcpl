#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"

#include <iostream>

#include "graph/traveling_salesman_problem.hpp"
#include "graph/read_graph.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<long long>(N, M, true, true, 0);
    const long long INF = 1LL << 60;
    auto res = traveling_salesman_problem<long long>(g, INF);
    long long ans = res.back()[0];
    if (ans == INF) ans = -1;
    std::cout << ans << '\n';
    return 0;
}