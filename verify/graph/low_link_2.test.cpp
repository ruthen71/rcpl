#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <iostream>

#include "graph/read_graph.hpp"
#include "graph/low_link.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto g = read_graph<int>(N, M, false, false, 0);
    LowLink llink(g);
    auto ans = llink.bridges;
    std::sort(ans.begin(), ans.end());
    for (auto&& [s, t] : ans) std::cout << s << ' ' << t << '\n';
    return 0;
}