#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <bits/stdc++.h>

#include "src/data_structure/weighted_unionfind.hpp"

int main() {
    int N, Q;
    std::cin >> N >> Q;
    weighted_unionfind<long long> uf(N);
    while (Q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x, y;
            std::cin >> x >> y;
            long long z;
            std::cin >> z;
            uf.merge(x, y, z);
        } else {
            int x, y;
            std::cin >> x >> y;
            if (uf.same(x, y)) {
                std::cout << uf.diff(x, y) << '\n';
            } else {
                std::cout << '?' << '\n';
            }
        }
    }
    return 0;
}