#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0519"

#include <bits/stdc++.h>

#include "src/graph/topological_sort.hpp"

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(M), b(M);
    std::vector<std::vector<int>> C(N, std::vector<int>(N));
    graph<int, true> G(N);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i] >> b[i];
        a[i] = N - a[i];
        b[i] = N - b[i];
        G.add_edge(a[i], b[i]);
        C[a[i]][b[i]] = 1;
    }
    auto res = topological_sort(G);
    for (auto &e : res) std::cout << N - e << '\n';
    int ok = 1;
    for (int i = 0; i < N - 1; i++) {
        ok &= C[res[i]][res[i + 1]];
    }
    std::cout << 1 - ok << '\n';
    return 0;
}