#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <bits/stdc++.h>

#include "graph/read_graph.hpp"
#include "graph/low_link.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    auto G = read_graph<int>(N, M, 0, 0, 0);
    LowLink llink(G);
    auto ans = llink.bridge;
    std::sort(ans.begin(), ans.end());
    for (auto& [s, t] : ans) std::cout << s << ' ' << t << '\n';
    return 0;
}