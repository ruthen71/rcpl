#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>

#include "data_structure/unionfind.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    UnionFind uf(N);
    while (Q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            std::cout << uf.same(u, v) << '\n';
        }
    }
    return 0;
}
